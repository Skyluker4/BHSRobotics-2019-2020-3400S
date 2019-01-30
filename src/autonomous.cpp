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

    revUpLauncher(); //Luke, This is anish and I think you need to lower the speed of the launcher for the AUTONOMOUS PERIOD ONLY so that our robot is able to hit the flags.
    launcher = 1110 //try this motor speed.

    // Move forward
    forward(0.175, 127); // This moving forward command is putting to much momentem on the robot in the far side program (RED FAR OR BLUE FAR).

    // Face flags
    turnRight(0.32, 127);

    // Wait for launcher to rev up
    pros::delay(5000); //Try to shorten the period of delay to like 4.5 seconds or 4 seconds if you plan on doing motor on full speed, this is causing the rubber bands to fall out.
    pros::delay(4000) //Try this command and tell me if it works
    // Launch
    mtr_combine = -127;
    pros::delay(500);
    mtr_combine = 0;

    // Hit low flag
    forward(1, 127);

    // Turn toward platform
    turnRight(0.3, 127); //I think this command would be turn left.
    turnLeft(.5,127)
    // Go toward platform
    forward(2, 127);

    // Straighten out
    turnLeft(0.1, 127);

    // Get on platform
    forward(2, 127);

    // Stop
    zeroAllMotors();
}
//Another solution would be to try to hit the cone with commands:
goBack(motorport#,-127) for .2 sec*first motor
goBack(motorport#,-127) for .2 sec*second motor for wheel
// this would go after the move forward
turnLeft(motorport#,127) for .2sec * this sends the right motor straight forward
turnLeft(motorport#-127) for .2 sec *this ,moves the right motor back and rotates the robot left
 goForward(motorport#,127) for .1 sec * this moves the right motor forward
 goForward(motorport#,127) for .1 sec * this moves the left motor forward.
 goForward(motorport#,-127)for 1 sec // this will move the combine so that the cap can be flipped
 goForward(motorport#,-127) for 1 sec // this will trigger the other combine to do the same as the code segment above.
 //  This goes after turn toward platform
 // This is my idea for the new autonomous, tell me if this is good or not. If it is good then we can test it. WARNING: I HAVE NOT MADE THE CORRET CALCULATIONS.   
