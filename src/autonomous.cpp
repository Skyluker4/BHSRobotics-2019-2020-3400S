#include "main.h"
#include "config.hpp"
#include "movement.hpp"

/**
* Plan for close:
* Start facing straight ahead
* 1. Hit top flag with preload
* 2. Hit low flag with poles
* 3. Flip cap
* 4. Park on alliance platform
* 5. Stop
*/

/**
* Plan for far:
* Start facing flags
* 1. Hit middle flag with preload
* 2. Park
* 3. Stop
*/

inline void autonomousBlueClose() {
    using namespace movement;

    // Get launcher to full speed in time
    revUpLauncher();

    // Move forward
    forward(0.175, 127);

    // Face flags
    turnRight(0.52, 70);

    // Wait for launcher to rev up
    pros::delay(5000);

    // Move forward a little
    forward(0.4, 127);

    // Launch
    mtr_combine = -127;
    pros::delay(500);
    mtr_combine = 0;

    // Stop all motors
    zeroAllMotors();

    // Turn right just a little
    turnRight(0.05, 127);

    // Hit low flag
    forward(0.6, 127);

    // Back up
    forward(0.4, -127);

    // Turn toward cap
    turnLeft(0.4875, 127);

    // Turn on combine
    mtr_combine = 110;

    // Hit the cap
    forward(0.6, 127);

    pros::delay(500);

    // Stop combine
    mtr_combine = 0;

    // Backwards
    forward(0.25, -127);

    // Turn to platform
    turnLeft(0.22, 127);

    // Get on platform
    forward(1.4, 127);
}

inline void autonomousBlueFar() {
    using namespace movement;

    // Move backwards
    forward(0.175, -127);

    // Get launcher to full speed in time
    revUpLauncher();

    // Wait for launcher to rev up
    pros::delay(5000);

    // Launch
    mtr_combine = -127;
    pros::delay(500);
    mtr_combine = 0;

    // Stop all motors
    zeroAllMotors();

    // Go forward
    forward(0.95, 127);

    // Turn left toward platform
    turnLeft(0.525, 70);

    // Go on platform
    forward(1.5, 127);
}

inline void autonomousRedClose() {
    using namespace movement;

    // Get launcher to full speed in time
    revUpLauncher();

    // Move forward
    forward(0.175, 127);

    // Face flags
    turnLeft(0.52, 70);

    // Wait for launcher to rev up
    pros::delay(5000);

    // Move forward a little
    forward(0.4, 127);

    // Launch
    mtr_combine = -127;
    pros::delay(500);
    mtr_combine = 0;

    // Stop all motors
    zeroAllMotors();

    // Turn left just a little
    turnLeft(0.05, 127);

    // Hit low flag
    forward(0.6, 127);

    // Back up
    forward(0.4, -127);

    // Turn toward cap
    turnRight(0.4875, 127);

    // Turn on combine
    mtr_combine = 110;

    // Hit the cap
    forward(0.6, 127);

    /*// Turn to platform
    turnRight(0.2, 127);

    // Go toward platform
    forward(2, 127);

    // Straighten out
    turnRight(0.1, 127);

    // Get on platform
    forward(2, 127);*/
}

inline void autonomousRedFar() {
    using namespace movement;

    // Move backwards
    forward(0.175, -127);

    // Get launcher to full speed in time
    revUpLauncher();

    // Wait for launcher to rev up
    pros::delay(5000);

    // Launch
    mtr_combine = -127;
    pros::delay(500);
    mtr_combine = 0;

    // Stop all motors
    zeroAllMotors();

    // Go forward
    forward(0.95, 127);

    // Turn right toward platform
    turnRight(0.525, 70);

    // Go on platform
    forward(1.5, 127);
}

void autonomous() {
#ifdef BLUE_CLOSE
    autonomousBlueClose();
#endif

#ifdef BLUE_FAR
    autonomousBlueFar();
#endif

#ifdef RED_CLOSE
    autonomousRedClose();
#endif

#ifdef RED_FAR
    autonomousRedFar();
#endif

    // Stop
    movement::zeroAllMotors();
}