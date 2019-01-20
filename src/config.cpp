#include "api.h"
#include "config.hpp"

pros::Controller ctr_master(pros::E_CONTROLLER_MASTER);

pros::Motor mtr_frontLeft(6, true);
pros::Motor mtr_backLeft(7, true);
pros::Motor mtr_frontRight(9);
pros::Motor mtr_backRight(10);
pros::Motor mtr_combine(8);
pros::Motor mtr_launcher1(11);
pros::Motor mtr_launcher2(12);