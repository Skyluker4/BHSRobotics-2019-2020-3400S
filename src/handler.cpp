#include <cstdint>

#include "pros/motors.hpp"
#include "pros/misc.hpp"

#include "handler.hpp"
#include "error.hpp"
#include "controller.hpp"

namespace handler {
    Handler::Handler() : Error() {}
    Handler::Handler(pros::Motor &mtr) : Error(mtr) {}
    Handler::Handler(pros::Controller& ctr) : Error(ctr) {}
    Handler::Handler(pros::Controller &ctr1, pros::Controller &ctr2) : Error(ctr1, ctr2) {}
    Handler::Handler(pros::Controller &ctr, pros::Motor &mtr) : Error(ctr, mtr) {}
    Handler::Handler(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr) : Error(ctr1, ctr2, mtr) {}


    bool Handler::handleError() {

    }

    bool Handler::handleError(std::uint_fast8_t code) {

    }

    bool Handler::handleWarning() {

    }

    bool Handler::handleWarning(std::uint_fast8_t code) {

    }
}