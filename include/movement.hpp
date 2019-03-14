#include <cstdint>

#include "pros/motors.hpp"

#include "config.hpp"

namespace movement {
    typedef enum time_e {
        E_TIME_MILLISECONDS = 1,
        E_TIME_HUNDREDTHS = 10,
        E_TIME_DECISECONDS = 100,
        E_TIME_SECONDS = 1000,
        E_TIME_MINUTES = 60000
    } time_e_t;

    inline void zeroDriveMotors() {
        mtr_frontLeft = 0;
        mtr_backLeft = 0;
        mtr_frontRight = 0;
        mtr_backRight = 0;
    }

    inline void zeroLaunchMotors() {
        mtr_launcher1 = 0;
        mtr_launcher2 = 0;
    }

    inline void zeroAllMotors() {
        zeroDriveMotors();
        zeroLaunchMotors();
        mtr_combine = 0;
    }

    inline void revUpLauncher() {
        mtr_launcher1 = 127;
        mtr_launcher2 = 127;
    }

    inline void revUpLauncher(int_fast8_t speed) {
        mtr_launcher1 = speed;
        mtr_launcher2 = speed;
    }

    void forward(time_e_t units, float time, int_fast8_t speed);
    void backward(time_e_t units, float time, int_fast8_t speed);
    void turnLeft(time_e_t units, float time, int_fast8_t speed);
    void turnRight(time_e_t units, float time, int_fast8_t speed);

    void forward(time_e_t units, float time);
    void backward(time_e_t units, float time);
    void turnLeft(time_e_t units, float time);
    void turnRight(time_e_t units, float time);

    void forward(float seconds, int_fast8_t speed);
    void backward(float seconds, int_fast8_t speed);
    void turnLeft(float seconds, int_fast8_t speed);
    void turnRight(float seconds, int_fast8_t speed);

    void forward(float seconds);
    void backward(float seconds);
    void turnLeft(float seconds);
    void turnRight(float seconds);

    void forwardEncoder(pros::motor_encoder_units_e_t units, double amount, uint_fast8_t speed);
    void backwardEncoder(pros::motor_encoder_units_e_t units, double amount, uint_fast8_t speed);
    void turnLeftEncoder(pros::motor_encoder_units_e_t units, double amount, uint_fast8_t speed);
    void turnRightEncoder(pros::motor_encoder_units_e_t units, double amount, uint_fast8_t speed);

    void forwardEncoder(double amount, uint_fast8_t speed);
    void backwardEncoder(double amount, uint_fast8_t speed);
    void turnLeftEncoder(double amount, uint_fast8_t speed);
    void turnRightEncoder(double amount, uint_fast8_t speed);

    void forwardEncoder(double amount);
    void backwardEncoder(double amount);
    void turnLeftEncoder(double amount);
    void turnRightEncoder(double amount);
}