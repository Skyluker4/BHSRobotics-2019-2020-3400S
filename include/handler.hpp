#ifndef _HANDLE_HEADER
#define _HANDLE_HEADER

#include <cstdint>

#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "error.hpp"

namespace handler {
    class Handler : public error::Error {
    public:
        Handler();
        Handler(pros::Motor &mtr);
        Handler(pros::Controller& ctr);
        Handler(pros::Controller &ctr1, pros::Controller &ctr2);
        Handler(pros::Controller &ctr, pros::Motor &mtr);
        Handler(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr);
        template <typename M, typename... Args> Handler(M mtr, Args... mtrs);
        template <typename C, typename M, typename... Args> Handler(C ctr, M mtr, Args... mtrs);
        template <typename C, typename D, typename M, typename... Args> Handler(C ctr1, D ctr2, M mtr, Args... mtrs);

        bool handleError();
        bool handleError(std::uint_fast8_t code);
        bool handleWarning();
        bool handleWarning(std::uint_fast8_t code);
    };
}

// Implement the templates
#include "../src/handler.tpp"

#endif