#include "pros/motors.hpp"
#include "pros/misc.hpp"

#include "config.hpp"

pros::Controller ctr_master(pros::E_CONTROLLER_MASTER);

pros::Motor mtr_frontLeft(7, true);
pros::Motor mtr_backLeft(6, true);
pros::Motor mtr_frontRight(9);
pros::Motor mtr_backRight(10);
pros::Motor mtr_combine(1);
pros::Motor mtr_launcher1(4);
pros::Motor mtr_launcher2(5);
pros::Motor mtr_pusher(3, true);