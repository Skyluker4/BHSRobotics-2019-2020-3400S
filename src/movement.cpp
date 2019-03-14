#include <cstdint>

#include "api.h"
#include "pros/motors.hpp"
#include "pros/rtos.hpp"
#include "movement.hpp"
#include "config.hpp"

#define MARGIN_OF_ERROR 8

namespace movement {
    void forward(time_e_t units, float time, int_fast8_t speed) {
        speed = -speed;
        mtr_frontLeft = speed;
        mtr_backLeft = speed;
        mtr_frontRight = speed;
        mtr_backRight = speed;
        pros::delay(time * units);
        zeroDriveMotors();
    }

    void backward(time_e_t units, float time, int_fast8_t speed) {
        mtr_frontLeft = speed;
        mtr_backLeft = speed;
        mtr_frontRight = speed;
        mtr_backRight = speed;
        pros::delay(time * units);
        zeroDriveMotors();
    }

    void turnLeft(time_e_t units, float time, int_fast8_t speed) {
        uint_fast8_t negSpeed = -speed;

        mtr_frontLeft = speed;
        mtr_backLeft = speed;
        mtr_frontRight = negSpeed;
        mtr_backRight = negSpeed;
        pros::delay(time * units);
        zeroDriveMotors();
    }

    void turnRight(time_e_t units, float time, int_fast8_t speed) {
        uint_fast8_t negSpeed = -speed;

        mtr_frontLeft = negSpeed;
        mtr_backLeft = negSpeed;
        mtr_frontRight = speed;
        mtr_backRight = speed;
        pros::delay(time * units);
        zeroDriveMotors();
    }

    void forward(time_e_t units, float time) {
        forward(units, time, 127);
    }

    void backward(time_e_t units, float time) {
        backward(units, time, 127);
    }

    void turnLeft(time_e_t units, float time) {
        turnLeft(units, time, 127);
    }

    void turnRight(time_e_t units, float time) {
        turnRight(units, time, 127);
    }

    void forward(float seconds, int_fast8_t speed) {
        forward(E_TIME_SECONDS, seconds, speed);
    }

    void backward(float seconds, int_fast8_t speed) {
        forward(seconds, -speed);
    }

    void turnLeft(float seconds, int_fast8_t speed) {
        turnLeft(E_TIME_SECONDS, seconds, speed);
    }

    void turnRight(float seconds, int_fast8_t speed) {
        turnRight(E_TIME_SECONDS, seconds, speed);
    }

    void forward(float seconds) {
        forward(seconds, 127);
    }

    void backward(float seconds) {
        backward(seconds, 127);
    }

    void turnLeft(float seconds) {
        turnLeft(seconds, 127);
    }
    void turnRight(float seconds) {
        turnRight(seconds, 127);
    }
    // MOE 5
    //while (mtr_frontLeft.get_position() > amount + 5 || mtr_backLeft.get_position() > amount + 5|| mtr_frontRight.get_position() > amount + 5|| mtr_backRight.get_position() > amount + 5)
    void forwardEncoder(pros::motor_encoder_units_e_t units, double amount, uint_fast8_t speed) {
        mtr_frontLeft.set_encoder_units(units);
        mtr_backLeft.set_encoder_units(units);
        mtr_frontRight.set_encoder_units(units);
        mtr_backRight.set_encoder_units(units);

        mtr_frontLeft.tare_position();
        mtr_backLeft.tare_position();
        mtr_frontRight.tare_position();
        mtr_backRight.tare_position();

        amount = -amount;

        mtr_frontLeft.move_absolute(amount, speed);
        mtr_backLeft.move_absolute(amount, speed);
        mtr_frontRight.move_absolute(amount, speed);
        mtr_backRight.move_absolute(amount, speed);

        while (mtr_frontLeft.get_position() > amount || mtr_backLeft.get_position() > amount || mtr_frontRight.get_position() > amount || mtr_backRight.get_position() > amount)
            pros::delay(1);

        zeroDriveMotors();
    }

    void backwardEncoder(pros::motor_encoder_units_e_t units, double amount, uint_fast8_t speed) {
        mtr_frontLeft.set_encoder_units(units);
        mtr_backLeft.set_encoder_units(units);
        mtr_frontRight.set_encoder_units(units);
        mtr_backRight.set_encoder_units(units);

        mtr_frontLeft.tare_position();
        mtr_backLeft.tare_position();
        mtr_frontRight.tare_position();
        mtr_backRight.tare_position();

        mtr_frontLeft.move_absolute(amount, speed);
        mtr_backLeft.move_absolute(amount, speed);
        mtr_frontRight.move_absolute(amount, speed);
        mtr_backRight.move_absolute(amount, speed);

        while (mtr_frontLeft.get_position() < amount || mtr_backLeft.get_position() < amount || mtr_frontRight.get_position() < amount || mtr_backRight.get_position() < amount)
            pros::delay(1);

        zeroDriveMotors();
    }

    void turnLeftEncoder(pros::motor_encoder_units_e_t units, double amount, uint_fast8_t speed) {
        mtr_frontLeft.set_encoder_units(units);
        mtr_backLeft.set_encoder_units(units);
        mtr_frontRight.set_encoder_units(units);
        mtr_backRight.set_encoder_units(units);

        mtr_frontLeft.tare_position();
        mtr_backLeft.tare_position();
        mtr_frontRight.tare_position();
        mtr_backRight.tare_position();

        double negAmount = -amount;

        mtr_frontLeft.move_absolute(amount, speed);
        mtr_backLeft.move_absolute(amount, speed);
        mtr_frontRight.move_absolute(negAmount, speed);
        mtr_backRight.move_absolute(negAmount, speed);

        while (mtr_frontLeft.get_position() < amount - MARGIN_OF_ERROR || mtr_backLeft.get_position() < amount - MARGIN_OF_ERROR || mtr_frontRight.get_position() > negAmount + MARGIN_OF_ERROR || mtr_backRight.get_position() > negAmount + MARGIN_OF_ERROR)
            pros::delay(1);

        zeroDriveMotors();
    }

    void turnRightEncoder(pros::motor_encoder_units_e_t units, double amount, uint_fast8_t speed) {
        mtr_frontLeft.set_encoder_units(units);
        mtr_backLeft.set_encoder_units(units);
        mtr_frontRight.set_encoder_units(units);
        mtr_backRight.set_encoder_units(units);

        mtr_frontLeft.tare_position();
        mtr_backLeft.tare_position();
        mtr_frontRight.tare_position();
        mtr_backRight.tare_position();

        double negAmount = -amount;

        mtr_frontLeft.move_absolute(negAmount, speed);
        mtr_backLeft.move_absolute(negAmount, speed);
        mtr_frontRight.move_absolute(amount, speed);
        mtr_backRight.move_absolute(amount, speed);

        while (mtr_frontLeft.get_position() > negAmount + MARGIN_OF_ERROR || mtr_backLeft.get_position() > negAmount + MARGIN_OF_ERROR || mtr_frontRight.get_position() < amount - MARGIN_OF_ERROR || mtr_backRight.get_position() < amount - MARGIN_OF_ERROR)
            pros::delay(1);

        zeroDriveMotors();
    }

    void forwardEncoder(double amount, uint_fast8_t speed) {
        forwardEncoder(pros::E_MOTOR_ENCODER_COUNTS, amount, speed);
    }

    void backwardEncoder(double amount, uint_fast8_t speed) {
        backwardEncoder(pros::E_MOTOR_ENCODER_COUNTS, amount, speed);
    }

    void turnLeftEncoder(double amount, uint_fast8_t speed) {
        turnLeftEncoder(pros::E_MOTOR_ENCODER_COUNTS, amount, speed);
    }

    void turnRightEncoder(double amount, uint_fast8_t speed) {
        turnRightEncoder(pros::E_MOTOR_ENCODER_COUNTS, amount, speed);
    }

    void forwardEncoder(double amount) {
        forwardEncoder(amount, 127);
    }

    void backwardEncoder(double amount) {
        backwardEncoder(amount, 127);
    }

    void turnLeftEncoder(double amount) {
        turnLeftEncoder(amount, 127);
    }

    void turnRightEncoder(double amount) {
        turnRightEncoder(amount, 127);
    }
}