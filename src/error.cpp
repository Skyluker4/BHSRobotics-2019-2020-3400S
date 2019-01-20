#include <cstdint>
#include "api.h"
#include "error.hpp"

namespace error {
    std::uint_fast8_t lastError = 0;
    std::uint_fast8_t lastWarning = 0;

    void clearAllMsgs() {
        lastError = 0;
        lastWarning = 0;
    }

    void getError() {
        checkBatteryTemp();
        if (errno == PROS_ERR)
            lastError = lastWarning = ERROR_PROS;
    }

    void getError(pros::Controller &ctr) {
        checkControllerConnection(ctr);
        getError();
    }

    void getError(pros::Controller &ctr1, pros::Controller &ctr2) {
        checkControllerConnection(ctr1, ctr2);
        getError();
    }

    void getWarning() {
        checkRobotBattery();
        getError();
    }

    void getWarning(pros::Controller &ctr) {
        checkControllerBattery(ctr);
        checkRobotBattery();
        getError(ctr);
    }

    void getWarning(pros::Controller &ctr1, pros::Controller &ctr2) {
        checkControllerBatteries(ctr1, ctr2);
        checkRobotBattery();
        getError(ctr1, ctr2);
    }

    void getMotorError(pros::Motor &mtr) {
        std::uint32_t faults = mtr.get_faults();

        if(mtr.get_flags()  &pros::E_MOTOR_FLAGS_BUSY)
            lastError = lastWarning = ERROR_MOTOR_NOCOMM | mtr._port;

        if(faults == pros::E_MOTOR_FAULT_NO_FAULTS) return;

        switch(faults) {
            case pros::E_MOTOR_FAULT_MOTOR_OVER_TEMP:
                lastError = lastWarning = ERROR_MOTOR_TEMPERATURE | mtr._port;
                break;
            case pros::E_MOTOR_FAULT_DRIVER_FAULT:
                lastError = lastWarning = ERROR_MOTOR_HBRIDGE_FAULT | mtr._port;
                break;
            case pros::E_MOTOR_FAULT_OVER_CURRENT:
                lastError = lastWarning = ERROR_MOTOR_CURRENT;
                break;
            case pros::E_MOTOR_FAULT_DRV_OVER_CURRENT:
                lastError = lastWarning = ERROR_MOTOR_HBRIDGE_CURRENT;
                break;
        }
    }

    void checkBatteryTemp() {
        if(pros::battery::get_temperature() > 55)
            lastError = lastWarning = ERROR_BATTERY_TEMPERATURE;
    }

    void checkRobotBattery() {
        if (pros::battery::get_capacity() < LOWBATTERY_LEVEL)
            lastWarning = WARNING_ROBOT_LOWBATTERY;
    }
    double checkControllerBattery(pros::Controller &ctr) {
        const double level = ctr.get_battery_level();
        if (level < LOWBATTERY_LEVEL)
            lastWarning = WARNING_CONTROLLER_LOWBATTERY;
        return level;
    }

    double checkControllerBatteries(pros::Controller &ctr1, pros::Controller &ctr2) {
        const double ctr1Level = checkControllerBattery(ctr1);
        const double ctr2Level = checkControllerBattery(ctr2);
        return ctr1Level < ctr2Level ? ctr1Level : ctr2Level;
    }

    double checkAllBatteries(pros::Controller &ctr) {
        double controllerLevel = checkControllerBattery(ctr);
        double robotLevel = pros::battery::get_capacity();

        if(robotLevel < LOWBATTERY_LEVEL)
            lastWarning = WARNING_ROBOT_LOWBATTERY;

        return controllerLevel < robotLevel ? controllerLevel : robotLevel;
    }

    double checkAllBatteries(pros::Controller &ctr1, pros::Controller &ctr2) {
        double ctr1Level = checkControllerBattery(ctr1);
        double ctr2Level = checkControllerBattery(ctr2);
        double robotLevel = pros::battery::get_capacity();

        if (robotLevel < LOWBATTERY_LEVEL)
            lastWarning = WARNING_ROBOT_LOWBATTERY;

        return robotLevel < ctr1Level && robotLevel < ctr2Level ?
            robotLevel : ctr1Level < ctr2Level ?
                ctr1Level : ctr2Level;
    }

    void checkControllerConnection(pros::Controller &ctr) {
        if(!ctr.is_connected()) lastWarning = lastError = ERROR_CONTROLLER_NOCOMM | ctr._id;
    }

    void checkControllerConnection(pros::Controller &ctr1, pros::Controller &ctr2) {
        checkControllerConnection(ctr1);
        checkControllerConnection(ctr2);
    }
}