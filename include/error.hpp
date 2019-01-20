#ifndef _ERROR_HEADER
#define _ERROR_HEADER

#include <cstdint>
#include "api.h"

#define ERROR_INTERNAL 0XFFFF
#define ERROR_PROS 0xEEEE

#define ERROR_MOTOR_TEMPERATURE     0xF000
#define ERROR_MOTOR_HBRIDGE_FAULT   0xE000
#define ERROR_MOTOR_CURRENT         0xD000
#define ERROR_MOTOR_HBRIDGE_CURRENT 0xC000
#define ERROR_MOTOR_NOCOMM          0xB000
#define ERROR_BATTERY_TEMPERATURE   0xA000
#define ERROR_CONTROLLER_NOCOMM     0xFF00

// How low should the battery be to warn user (in percentages)
#define LOWBATTERY_LEVEL 20

#define WARNING_ROBOT_LOWBATTERY 0X0A00
#define WARNING_CONTROLLER_LOWBATTERY 0x0B00

namespace error {
    extern std::uint_fast8_t lastError;
    extern std::uint_fast8_t lastWarning;

    void clearAllMsgs();

    void getError();
    void getError(pros::Controller &ctr);
    void getError(pros::Controller &ctr1, pros::Controller &ctr2);
    template <typename M, typename... Args> void getError(M mtr, Args... mtrs);
    template <typename C1, typename M, typename... Args> void getError(C1 ctr, M mtr, Args... mtrs);
    template <typename C1, typename C2, typename M, typename... Args> void getError(C1 ctr1, C2 ctr2, M mtr, Args... mtrs);

    void getWarning();
    void getWarning(pros::Controller &ctr);
    void getWarning(pros::Controller &ctr1, pros::Controller &ctr2);
    template <typename M, typename... Args> void getWarning(M mtr, Args... mtrs);
    template <typename C1, typename M, typename... Args> void getWarning(C1 ctr, M mtr, Args... mtrs);
    template <typename C1, typename C2, typename M, typename... Args> void getWarning(C1 ctr1, C2 ctr2, M mtr, Args... mtrs);

    void getMotorError(pros::Motor &motor);
    template <typename M, typename... Args> void getMotorError(M mtr, Args... mtrs);

    void checkBatteryTemp();
    void checkRobotBattery();
    double checkControllerBattery(pros::Controller &ctr);
    double checkControllerBatteries(pros::Controller &ctr1, pros::Controller &ctr2);
    double checkAllBatteries(pros::Controller &ctr);
    double checkAllBatteries(pros::Controller &ctr1, pros::Controller &ctr2);

    void checkControllerConnection(pros::Controller &ctr);
    void checkControllerConnection(pros::Controller &ctr1, pros::Controller &ctr2);
}

// Implement the templates
#include "../src/error.tpp"

#endif