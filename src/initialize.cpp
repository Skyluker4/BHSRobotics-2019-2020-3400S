#include "main.h"
#include "config.hpp"
#include "movement.hpp"

void initialize() {
    pros::lcd::initialize();

    pros::lcd::print(0, "No competition switch dected.");

    mtr_backLeft.tare_position();
    mtr_frontLeft.tare_position();
    mtr_backRight.tare_position();
    mtr_backRight.tare_position();
    mtr_combine.tare_position();
    mtr_launcher1.tare_position();
    mtr_launcher2.tare_position();
    mtr_pusher.tare_position();
}

void disabled() {
    movement::zeroAllMotors();

    // Make sure we know what's going on
    pros::lcd::clear_line(1);
    pros::lcd::print(1, "Disabled.");
    ctr_master.clear_line(0);
    ctr_master.print(0, 0, "Disabled");

    // Tell driver we're disabled
    ctr_master.rumble(".-");

    mtr_backLeft.tare_position();
    mtr_frontLeft.tare_position();
    mtr_backRight.tare_position();
    mtr_backRight.tare_position();
    mtr_combine.tare_position();
    mtr_launcher1.tare_position();
    mtr_launcher2.tare_position();
    mtr_pusher.tare_position();
}

void competition_initialize() {
    pros::lcd::clear_line(0);
    pros::lcd::print(0, "Competition mode.");

    mtr_backLeft.tare_position();
    mtr_frontLeft.tare_position();
    mtr_backRight.tare_position();
    mtr_backRight.tare_position();
    mtr_combine.tare_position();
    mtr_launcher1.tare_position();
    mtr_launcher2.tare_position();
    mtr_pusher.tare_position();
}