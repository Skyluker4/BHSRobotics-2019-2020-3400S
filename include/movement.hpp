#include <cstdint>

#include "config.hpp"

namespace movement {
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

    void forward(float seconds, int_fast8_t speed);
    void turnLeft(float seconds, int_fast8_t speed);
    void turnRight(float seconds, int_fast8_t speed);
}