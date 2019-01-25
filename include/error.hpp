#ifndef _ERROR_HEADER
#define _ERROR_HEADER

#include <cstdint>
#include <vector>

#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "config.hpp"

#define ERROR_NOERROR 0
#define ERROR_INTERNAL 0xFFFF
#define ERROR_ERRNO 0xEEEE
#define ERROR_PROS 0xDDDD

#define ERROR_MOTOR_TEMPERATURE     0xF000
#define ERROR_MOTOR_HBRIDGE_FAULT   0xE000
#define ERROR_MOTOR_CURRENT         0xD000
#define ERROR_MOTOR_HBRIDGE_CURRENT 0xC000
#define ERROR_MOTOR_NOCOMM          0xB000
#define ERROR_BATTERY_TEMPERATURE   0xA000
#define ERROR_CONTROLLER_NOCOMM     0xFF00

// How low should the battery be to warn user (in percentages)
#define LOWBATTERY_LEVEL 20

#define WARNING_ROBOT_LOWBATTERY 0x0A00
#define WARNING_CONTROLLER_LOWBATTERY 0x0B00

namespace error {
    extern std::vector<uint_fast8_t> errors;
    extern std::vector<uint_fast8_t> warnings;

    inline void clearAllErrors() {
        errors.clear();
        errno = 0;
    }
    inline void clearAllMsgs() {
        clearAllErrors();
        warnings.clear();
    }
    inline void popMsgs() {
        errors.pop_back();
        warnings.pop_back();
    }

    bool getError();
    bool getError(pros::Controller &ctr);
    bool getError(pros::Controller &ctr1, pros::Controller &ctr2);
    template <typename M, typename... Args> void getError(M mtr, Args... mtrs);
    template <typename C1, typename M, typename... Args> void getError(C1 ctr, M mtr, Args... mtrs);
    template <typename C1, typename C2, typename M, typename... Args> void getError(C1 ctr1, C2 ctr2, M mtr, Args... mtrs);

    bool getWarning();
    bool getWarning(pros::Controller &ctr);
    bool getWarning(pros::Controller &ctr1, pros::Controller &ctr2);
    template <typename M, typename... Args> bool getWarning(M mtr, Args... mtrs);
    template <typename C1, typename M, typename... Args> bool getWarning(C1 ctr, M mtr, Args... mtrs);
    template <typename C1, typename C2, typename M, typename... Args> bool getWarning(C1 ctr1, C2 ctr2, M mtr, Args... mtrs);

    bool getMotorError(pros::Motor &motor);
    template <typename M, typename... Args> bool getMotorError(M mtr, Args... mtrs);

    double checkBatteryTemp();
    double checkRobotBattery();
    double checkControllerBattery(pros::Controller &ctr);
    double checkControllerBattery(pros::Controller &ctr1, pros::Controller &ctr2);
    double checkAllBatteries(pros::Controller &ctr);
    double checkAllBatteries(pros::Controller &ctr1, pros::Controller &ctr2);

    bool checkControllerConnection(pros::Controller &ctr);
    bool checkControllerConnection(pros::Controller &ctr1, pros::Controller &ctr2);

    bool checkController(pros::Controller &ctr);
    bool checkController(pros::Controller &ctr1, pros::Controller &ctr2);

    class Error : public Config {
    public:
        Error();
        Error(Config c);
        Error(pros::Controller &ctr);
        Error(pros::Controller &ctr1, pros::Controller &ctr2);
        Error(pros::Controller &ctr, pros::Motor &mtr);
        Error(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr);
        template <typename M, typename... Args>
        Error(M mtr, Args... mtrs);
        template <typename C, typename M, typename... Args>
        Error(C ctr, M mtr, Args... mtrs);
        template <typename C, typename D, typename M, typename... Args>
        Error(C ctr1, D ctr2, M mtr, Args... mtrs);
        bool getMotorOnlyErrors();
        bool getControllerOnlyErrors();
        bool getAllErrors();
        bool getControllerOnlyWarnings();
        bool getAllWarnings();
        double checkControllerBatteries();
        double checkAllBatteries();
        bool checkControllerConnections();
        bool checkControllers();
    };
}

// Implement the templates
#include "../src/error.tpp"

#endif