#include "main.h"
#include "config.hpp"
#include "movement.hpp"

/**
* Plan for close:
* Start facing straight ahead
* 1. Hit top flag with preload
* 2. Hit low flag with poles
* 3. Flip cap
* 4. Get other cap core touching
* 5. Hit low middle flag
* 6. Park on alliance platform
* 7. Stop
*/

/**
* Plan for far:
* Start facing straight ahead
* 1. Hit middle flag with preload
* 2. Flip cap
* 3. Get other cap core touching
* 4. Park
* 5. Stop
*/

/**
* Plan for any:
* 1. Get cap core touching
* 2. Stop
*/

/**
* Plan for skills - Start Red Close, facing straight ahead:
* 1. Shoot high flag
* 2. Hit low flag with poles
* 3. Flip cap
* 4. Flip other cap
* 5. Hit low middle flag
* 6. Flip cap
* 7. Hit low far flag
* 8. Flip other cap
* 9. Flip far cap
* 10. Flip other far cap
* 11. Flip other far cap
* 12. Flip other far cap
* 13. Park on middle
* 14. Stop
*/

// 1000 raw units about equal to 1 square
// 900 raw units for 90 degree turn

inline void autonomousBlueClose() {
    using namespace movement;

    // Get launcher to full speed in time
    revUpLauncher();

    // Move forward
    forward(0.175, 127);

    // Face flags
    turnRight(0.67, 70);

    // Wait for launcher to rev up
    pros::delay(4500);

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
    forward(1, 127);

    // Back up
    forward(0.8, -127);

    // Turn toward cap
    turnLeft(0.4875, 127);

    // Turn on combine
    mtr_combine = 110;

    // Hit the cap
    forward(0.6, 127);

    pros::delay(300);

    // Stop combine
    mtr_combine = 0;

    // Backwards
    forward(0.155, -127);
/*
    // Turn to platform
    turnLeft(0.24, 127);

    // Get on platform
    forward(1.4, 127);*/
}

inline void autonomousBlueFar() {
    using namespace movement;

    forwardEncoder(2500);

    turnRight(0.3);

    backward(0.1);

}

inline void autonomousRedClose() {
    using namespace movement;

    // Get launcher to full speed in time
    revUpLauncher();

    // Move forward
    forward(0.175, 127);

    // Face flags
    turnLeft(0.7, 70);

    // Wait for launcher to rev up
    pros::delay(4500);

    // Move forward a little
    forward(0.4, 127);

    // Launch
    mtr_combine = -127;
    pros::delay(500);
    mtr_combine = 0;

    // Stop all motors
    zeroAllMotors();

    // Turn left just a little
    turnLeft(0.07, 127);

    // Hit low flag
    forward(1, 127);

    // Back up
    forward(0.8, -127);

    // Turn toward cap
    turnRight(0.53, 127);

    /*// Turn on combine
    mtr_combine = 110;
    // Hit the cap
    forward(0.6, 127);
    pros::delay(300);
    // Stop combine
    mtr_combine = 0;
    // Backwards
    forward(0.155, -127);
    // Turn to platform
    turnRight(0.34, 127);
    // Get on platform
    forward(1.55, 127);*/
    zeroAllMotors();
}

inline void autonomousRedFar() {
    using namespace movement;

    forwardEncoder(2500);

    turnRight(0.3);

    backward(0.1);
}

inline void autonomousAny() {
    using namespace movement;

    forwardEncoder(2500);

    turnLeftEncoder(1000);
}

inline void autonomousSkills() {
    using namespace movement;

    // Move forward
    forwardEncoder(230);

    // Face flags
    turnRightEncoder(885);

    // Get launcher to full speed in time
    revUpLauncher();

    // Wait for launcher to rev up
    pros::delay(3750);

    // Move forward a little
    forwardEncoder(1645);

    // Launch
    mtr_combine = -127;
    pros::delay(500);
    mtr_combine = 0;

    // Stop all motors
    zeroLaunchMotors();

    // Turn right just a little
    turnRightEncoder(100);

    // Hit low flag
    forwardEncoder(1760);

    // Back up
    backwardEncoder(1605);

    // Turn toward cap
    turnLeftEncoder(1100);

    // Turn on combine
    mtr_combine = 100;

    // Hit the cap
    forwardEncoder(2600);

    pros::delay(300);

    // Stop combine
    mtr_combine = 0;

    // Backwards
    backwardEncoder(400);

    // Turn toward low middle flag
    turnRightEncoder(700);

    //Other stuff to hit the flag

    // Hit low middle flag
    forwardEncoder(1945);

    turnRight(0.2);
    backward(0.1);
    turnLeft(0.1);
    forward(0.5);

    //Backwards
    backward(1.3, 100);

    // Scoot up just a little
    forward(0.1);

    // Turn right
    turnRightEncoder(1000);

    // Forward a little
    forwardEncoder(900);

    // Turn to platform
    turnRightEncoder(840);

    // Get on platform
    forwardEncoder(3000);

    // Turn right
    turnRightEncoder(900);

    // Get on
    forwardEncoder(1300);

    zeroAllMotors();
}

void autonomous() {
    // Make sure we know what's going on
    pros::lcd::clear_line(1);
    pros::lcd::print(1, "Autonomous mode.");
    ctr_master.clear_line(0);
    ctr_master.print(0, 0, "Autonomous");

    // Tell driver we're starting
    ctr_master.rumble(".");

    // Turn on braking
    mtr_frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    mtr_backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    mtr_frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    mtr_backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

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

#ifdef ANY
    autonomousAny();
#endif

#ifdef SKILLS
    autonomousSkills();
#endif

    // Stop
    movement::zeroAllMotors();
}
