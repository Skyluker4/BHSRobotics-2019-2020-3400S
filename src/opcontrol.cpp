#include <cstdint>

#include "main.h"
#include "config.hpp"
#include "movement.hpp"

// Controls how fast the robot will turn with the joystick
#define MAX_TURN_SPEED 75
#define MAX_JOYSTICK_SPEED 90

bool shootTwoRunning = false;
uint_fast8_t speed = 127;
int_fast16_t leftX, leftY, power, turn, left, right;

inline void drive() {
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
}

inline void combine() {
	if (ctr_master.get_digital(DIGITAL_L1))
		mtr_combine = 110;
	else if (ctr_master.get_digital(DIGITAL_L2))
		mtr_combine = -127;
	else
		mtr_combine = 0;
}

inline void launcher() {
	if (ctr_master.get_digital(DIGITAL_R1)) {
			mtr_launcher1 = -70;
			mtr_launcher2 = -70;
	}
	else if (ctr_master.get_digital(DIGITAL_R2)) {
			mtr_launcher1 = 100;
			mtr_launcher2 = 100;
	}
	else {
			mtr_launcher1 = 0;
			mtr_launcher2 = 0;
	}
}

inline void	push() {
	if (ctr_master.get_analog(ANALOG_RIGHT_Y) > 0)
		mtr_pusher = 127;
	else if (ctr_master.get_analog(ANALOG_RIGHT_Y) < 0)
		mtr_pusher = -127;
	else
		mtr_pusher = 0;
}

void opcontrol() {
	// Set braking modes
	mtr_frontLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    mtr_backLeft.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    mtr_frontRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
    mtr_backRight.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	mtr_launcher1.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	mtr_launcher2.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	mtr_combine.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
	mtr_pusher.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

	// Make sure we know what's going on
	pros::lcd::clear_line(1);
	pros::lcd::print(1, "Driver mode.");
	ctr_master.clear_line(2);
	ctr_master.set_text(2, 2, "Driver");

	// Tell driver we're ready
	ctr_master.rumble("-");

	while (true) {
		drive();
		combine();
		launcher();
		push();

		// Delay for controller
		pros::delay(2);
	}
}