#include "controller.hpp"
#include "pros/misc.hpp"

namespace controller {
    template <typename C, typename R, typename... Args> bool rumble(C ctr, R rumblePattern, Args... rumblePatterns) {
        if(!rumble(ctr, rumblePattern)) return false;
        rumble(ctr, rumblePatterns...);
        return true;
    }

    template <typename C, typename D, typename R, typename... Args> bool rumble(C ctr1, D ctr2, R rumblePattern, Args... rumblePatterns) {
        if(!rumble(ctr1, ctr2, rumblePattern)) return false;
        rumble(ctr1, ctr2, rumblePatterns...);
        return true;
    }

    template <typename C, typename B, typename... Args>
    void awaitControllerResponse(C ctr, B btn, Args... btns) {
        awaitControllerResponse(ctr, btn);
        awaitControllerResponse(ctr, btns...);
    }

    template <typename C, typename D, typename B, typename... Args>
    void awaitControllerResponse(C ctr1, D ctr2, B btn, Args... btns) {
        awaitControllerResponse(ctr1, ctr2, btn);
        awaitControllerResponse(ctr1, ctr2, btns...);
    }

    template <typename C, const char *R, pros::controller_digital_e_t B, typename... Args>
    void awaitControllerResponse(C ctr, const char *rumblePattern, pros::controller_digital_e_t btn, Args... btns) {
        awaitControllerResponse(ctr, rumblePattern, btn);
        awaitControllerResponse(ctr, rumblePattern, btns...);
    }

    template <typename C, typename D, const char *R, pros::controller_digital_e_t B, typename... Args>
    void awaitControllerResponse(C ctr1, D ctr2, const char *rumblePattern, pros::controller_digital_e_t btn, Args... btns) {
        awaitControllerResponse(ctr1, ctr2, rumblePattern, btn);
        awaitControllerResponse(ctr1, ctr2, rumblePattern, btns...);
    }
}