#include <cstdint>

#include "movement.hpp"
#include "config.hpp"

namespace movement {
    void forward(float seconds, int_fast8_t speed) {
        mtr_frontLeft = -speed;
        mtr_backLeft = -speed;
        mtr_frontRight = -speed;
        mtr_backRight = -speed;
        pros::delay(seconds * 1000);
        zeroDriveMotors();
    }

    void turnLeft(float seconds, int_fast8_t speed) {
        mtr_frontLeft = speed;
        mtr_backLeft = speed;
        mtr_frontRight = -speed;
        mtr_backRight = -speed;
        pros::delay(seconds * 1000);
        zeroDriveMotors();
    }

    void turnRight(float seconds, int_fast8_t speed) {
        mtr_frontLeft = -speed;
        mtr_backLeft = -speed;
        mtr_frontRight = speed;
        mtr_backRight = speed;
        pros::delay(seconds * 1000);
        zeroDriveMotors();
    }
}