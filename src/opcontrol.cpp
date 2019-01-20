#include "main.h"
#include "config.hpp"
#include "error.hpp"

// Controls how fast the robot will turn with the joystick
#define MAX_TURN_SPEED 75
#define MAX_JOYSTICK_SPEED 90

void opcontrol() {
	// Set up variables
	uint_fast8_t speed = 127;
	int_fast16_t leftX, leftY, power, turn, left, right;

	while (true) {
		// Check for errors
		error::getWarning(ctr_master, mtr_backLeft, mtr_backRight, mtr_frontLeft, mtr_frontRight, mtr_launcher1, mtr_launcher2);
		if(error::lastWarning != 0) {
			// TODO: Handle errors/warnings
			error::clearAllMsgs();
		}

		// Drive
		// Speed change
		if (ctr_master.get_digital(DIGITAL_X) && speed < 116)
			speed += 12;
		else if(ctr_master.get_digital(DIGITAL_B) && speed > 12)
			speed -= 12;

		// Forward
		if (ctr_master.get_digital(DIGITAL_UP)) {
			mtr_frontLeft = -speed;
			mtr_backLeft = -speed;
			mtr_frontRight = -speed;
			mtr_backRight = -speed;
		}
		// Backwards
		else if (ctr_master.get_digital(DIGITAL_DOWN)) {
			mtr_frontLeft = speed;
			mtr_backLeft = speed;
			mtr_frontRight = speed;
			mtr_backRight = speed;
		}
		// Left
		else if (ctr_master.get_digital(DIGITAL_LEFT)) {
			mtr_frontLeft = speed;
			mtr_backLeft = speed;
			mtr_frontRight = -speed;
			mtr_backRight = -speed;
		}
		// Right
		else if (ctr_master.get_digital(DIGITAL_RIGHT)) {
			mtr_frontLeft = -speed;
			mtr_backLeft = -speed;
			mtr_frontRight = speed;
			mtr_backRight = speed;
		} else {
			// Get joystick values
			leftY = -1 * ctr_master.get_analog(ANALOG_LEFT_Y);
			leftX = ctr_master.get_analog(ANALOG_LEFT_X);

			// Max speed of joystick
			power = leftY > 0 ?
				leftY > MAX_JOYSTICK_SPEED ?
					MAX_JOYSTICK_SPEED
					: leftY
				: leftY < -MAX_JOYSTICK_SPEED ?
					-MAX_JOYSTICK_SPEED
					: leftY;

			turn = leftX > 0 ?
				leftX > MAX_JOYSTICK_SPEED ?
					MAX_JOYSTICK_SPEED
					: leftX
				: leftX < -MAX_JOYSTICK_SPEED ?
					-MAX_JOYSTICK_SPEED
					: leftX;

			// Control how fast the joystick can turn the robot
			if(turn > MAX_TURN_SPEED)
				turn = MAX_TURN_SPEED;
			else if(turn < -MAX_TURN_SPEED)
				turn = -MAX_TURN_SPEED;

			// Determine how fast left and right drive goes
			left = power - turn;
			right = power + turn;

			// Set motors accordingly
			mtr_frontLeft = left;
			mtr_backLeft = left;
			mtr_frontRight = right;
			mtr_backRight = right;
		}

		// Combine
		if (ctr_master.get_digital(DIGITAL_L1))
			mtr_combine = 110;
		else if (ctr_master.get_digital(DIGITAL_L2))
			mtr_combine = -127;
		else
			mtr_combine = 0;

		// Launcher
		if (ctr_master.get_digital(DIGITAL_R1)) {
			mtr_launcher1 = -70;
			mtr_launcher2 = -70;
		}
		else if (ctr_master.get_digital(DIGITAL_R2)) {
			mtr_launcher1 = 127;
			mtr_launcher2 = 127;
		}
		else {
			mtr_launcher1 = 0;
			mtr_launcher2 = 0;
		}

		// Delay for controller
		pros::delay(2);
	}
}