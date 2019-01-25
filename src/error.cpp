#include <cstdint>
#include <vector>
#include <map>

#include "api.h"
#include "error.hpp"
#include "config.hpp"

namespace error {
    std::vector<uint_fast8_t> errors;
    std::vector<uint_fast8_t> warnings;

    inline void addError(std::uint_fast8_t code) {
        errors.push_back(code);
        warnings.push_back(code);
    }

    bool getError() {
        checkBatteryTemp();

        bool failed = false;

        if (errno == PROS_ERR) {
            addError(ERROR_PROS);
            failed = true;
        }
        else if(errno != 0) {
            addError(ERROR_ERRNO);
            failed = true;
        }

        return failed;
    }

    bool getError(pros::Controller &ctr) {
        return checkControllerConnection(ctr) || getError();
    }

    bool getError(pros::Controller &ctr1, pros::Controller &ctr2) {
        return checkControllerConnection(ctr1, ctr2) || getError();
    }

    bool getWarning() {
        return checkRobotBattery() || getError();
    }

    bool getWarning(pros::Controller &ctr) {
        return checkAllBatteries(ctr) || getError(ctr);
    }

    bool getWarning(pros::Controller &ctr1, pros::Controller &ctr2) {
        return checkAllBatteries(ctr1, ctr2) || getError(ctr1, ctr2);
    }

    bool getMotorError(pros::Motor &mtr) {
        bool failed = false;

        const std::uint32_t faults = mtr.get_faults();

        if(mtr.get_flags()  &pros::E_MOTOR_FLAGS_BUSY) {
            addError(ERROR_MOTOR_NOCOMM | mtr._port);
            failed = true;
        }

        if(faults == pros::E_MOTOR_FAULT_NO_FAULTS) return false;

        else if(faults & pros::E_MOTOR_FAULT_MOTOR_OVER_TEMP) {
                addError(ERROR_MOTOR_TEMPERATURE | mtr._port);
                failed = true;
        }
        else if(faults & pros::E_MOTOR_FAULT_DRIVER_FAULT) {
            addError(ERROR_MOTOR_HBRIDGE_FAULT | mtr._port);
            failed = true;
        }
        else if(faults & pros::E_MOTOR_FAULT_OVER_CURRENT) {
            addError(ERROR_MOTOR_CURRENT | mtr._port);
            failed = true;
        }
        else if(faults & pros::E_MOTOR_FAULT_DRV_OVER_CURRENT) {
            addError(ERROR_MOTOR_HBRIDGE_CURRENT | mtr._port);
            failed = true;
        }

        return failed;
    }

    double checkBatteryTemp() {
        const double temp = pros::battery::get_temperature();
        if (temp > 55)
            addError(ERROR_BATTERY_TEMPERATURE);
        return temp;
    }

    double checkRobotBattery() {
        const double cap = pros::battery::get_capacity();
        if (cap <= LOWBATTERY_LEVEL)
            warnings.push_back(WARNING_ROBOT_LOWBATTERY);
        return cap;
    }

    double checkControllerBattery(pros::Controller &ctr) {
        const double level = ctr.get_battery_level();
        if (level <= LOWBATTERY_LEVEL)
            warnings.push_back(WARNING_CONTROLLER_LOWBATTERY | ctr._id);
        return level;
    }

    double checkControllerBattery(pros::Controller &ctr1, pros::Controller &ctr2) {
        const double ctr1Level = checkControllerBattery(ctr1);
        const double ctr2Level = checkControllerBattery(ctr2);

        return ctr1Level < ctr2Level ? ctr1Level : ctr2Level;
    }

    double checkAllBatteries(pros::Controller &ctr) {
        const double controllerLevel = checkControllerBattery(ctr);
        const double robotLevel = pros::battery::get_capacity();

        if(robotLevel < LOWBATTERY_LEVEL)
            warnings.push_back(WARNING_ROBOT_LOWBATTERY);

        return controllerLevel < robotLevel ? controllerLevel : robotLevel;
    }

    double checkAllBatteries(pros::Controller &ctr1, pros::Controller &ctr2) {
        const double ctr1Level = checkControllerBattery(ctr1);
        const double ctr2Level = checkControllerBattery(ctr2);
        const double robotLevel = checkRobotBattery();

        return robotLevel < ctr1Level && robotLevel < ctr2Level ?
            robotLevel : ctr1Level < ctr2Level ?
                ctr1Level : ctr2Level;
    }

    bool checkControllerConnection(pros::Controller &ctr) {
        if(!ctr.is_connected()) {
            addError(ERROR_CONTROLLER_NOCOMM | ctr._id);
            return true;
        }
        return false;
    }

    bool checkControllerConnection(pros::Controller &ctr1, pros::Controller &ctr2) {
        return checkControllerConnection(ctr1) || checkControllerConnection(ctr2);
    }

    bool checkController(pros::Controller &ctr) {
        return (checkControllerBattery(ctr) <= LOWBATTERY_LEVEL) || checkControllerConnection(ctr);
    }

    bool checkController(pros::Controller &ctr1, pros::Controller &ctr2) {
        return (checkControllerBattery(ctr1, ctr2) <= LOWBATTERY_LEVEL) || checkControllerConnection(ctr1, ctr2);
    }

    Error::Error(): Config() {}

    Error::Error(Config c) {
        Controllers = c.getControllerMap();
        Motors = c.getMotorMap();
    }

    Error::Error(pros::Controller &ctr): Config(ctr) {}
    Error::Error(pros::Controller &ctr1, pros::Controller &ctr2): Config(ctr1, ctr2) {}
    Error::Error(pros::Controller &ctr, pros::Motor &mtr): Config(ctr, mtr) {}
    Error::Error(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr): Config(ctr1, ctr2, mtr) {}

    bool Error::getMotorOnlyErrors() {
        bool failed = false;
        for(auto mtr : Motors)
            if(getMotorError(mtr.second)) failed = true;
        return failed;
    }

    bool Error::getControllerOnlyErrors() {
        bool failed = false;
        for(auto ctr : Controllers)
            if(checkController(ctr.second)) failed = true;
        return failed;
    }

    bool Error::getAllErrors() {
        return getMotorOnlyErrors() || getControllerOnlyErrors() || getError();
    }

    bool Error::getControllerOnlyWarnings() {
        bool failed = false;
        for(auto ctr : Controllers)
            if((checkControllerBattery(ctr.second) <= WARNING_CONTROLLER_LOWBATTERY) || checkControllerConnection(ctr.second)) failed = true;
        return failed;
    }

    bool Error::getAllWarnings() {
        return getMotorOnlyErrors() || checkControllers() || getWarning();
    }

    double Error::checkControllerBatteries() {
        double lowest = -1;
        for(auto ctr : Controllers) {
            double bat = checkControllerBattery(ctr.second);
            if((bat < lowest) || (lowest = -1)) lowest = bat;
        }
        return lowest;
    }

    double Error::checkAllBatteries() {
        checkBatteryTemp();

        double ctr = checkControllerBatteries();
        double robot = checkRobotBattery();

        return ctr < robot ? ctr : robot;
    }

    bool Error::checkControllerConnections() {
        bool failed = false;
        for(auto ctr : Controllers)
            if(checkControllerConnection(ctr.second)) failed = true;
        return failed;
    }

    bool Error::checkControllers() {
        return checkControllerConnections() || checkControllerBatteries();
    }
}