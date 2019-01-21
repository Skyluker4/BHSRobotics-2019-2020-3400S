#include <cstdint>
#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "error.hpp"

namespace error {
    template <typename M, typename... Args>
    void getError(M mtr, Args... mtrs) {
        getMotorError(mtr);
        getError(mtrs...);
    }

    template <typename C1, typename M, typename... Args>
    void getError(C1 ctr, M mtr, Args... mtrs) {
        getMotorError(mtr);
        getError(ctr, mtrs...);
    }

    template <typename C1, typename C2, typename M, typename... Args>
    void getError(C1 ctr1, C2 ctr2, M mtr, Args... mtrs) {
        getError(mtr);
        getError(ctr1, ctr2, mtrs...);
    }

    template <typename M, typename... Args>
    void getWarning(M mtr, Args... mtrs) {
        getWarning(mtr);
        getWarning(mtrs...);
    }

    template <typename C1, typename M, typename... Args>
    void getWarning(C1 ctr, M mtr, Args... mtrs) {
        getWarning(mtr);
        getWarning(ctr, mtrs...);
    }

    template <typename C1, typename C2, typename M, typename... Args>
    void getWarning(C1 ctr1, C2 ctr2, M mtr, Args... mtrs) {
        getWarning(mtr);
        getWarning(ctr1, ctr2, mtrs...);
    }

    template <typename M, typename... Args>
    void getMotorError(M mtr, Args... mtrs) {
        getMotorError(mtr);
        getMotorError(mtrs...);
    }
}