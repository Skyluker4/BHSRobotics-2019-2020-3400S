#include <cstdint>

#include "main.h"
#include "config.hpp"
#include "movement.hpp"

using namespace movement;

void autonomous() {
    /**
    * Plan:
    * 1. Hit high flag with preload
    * 2. Hit low flag with poles
    * 3. Flip cap
    * 4. Park on alliance deck
    */

    revUpLauncher();

    // Move forward
    forward(0.175, 127);

    // Face flags
    turnRight(0.32, 127);

    // Wait for launcher to rev up
    pros::delay(5000);

    // Launch
    mtr_combine = -127;
    pros::delay(500);
    mtr_combine = 0;

    // Hit low flag
    forward(1, 127);

    // Turn toward platform
    turnRight(0.3, 127);

    // Go toward platform
    forward(2, 127);

    // Straighten out
    turnLeft(0.1, 127);

    // Get on platform
    forward(2, 127);

    // Stop
    zeroAllMotors();
}