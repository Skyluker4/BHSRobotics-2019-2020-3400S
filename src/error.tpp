#include <cstdint>

#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "error.hpp"

namespace error {
    template <typename M, typename... Args>
    bool getError(M mtr, Args... mtrs) {
        return getMotorError(mtr) || getError(mtrs...);
    }

    template <typename C1, typename M, typename... Args>
    bool getError(C1 ctr, M mtr, Args... mtrs) {
        return getMotorError(mtr) || getError(ctr, mtrs...);
    }

    template <typename C1, typename C2, typename M, typename... Args>
    bool getError(C1 ctr1, C2 ctr2, M mtr, Args... mtrs) {
        return getError(mtr) || getError(ctr1, ctr2, mtrs...);
    }

    template <typename M, typename... Args>
    bool getWarning(M mtr, Args... mtrs) {
        return getWarning(mtr) || getWarning(mtrs...);
    }

    template <typename C1, typename M, typename... Args>
    bool getWarning(C1 ctr, M mtr, Args... mtrs) {
        return getWarning(mtr) || getWarning(ctr, mtrs...);
    }

    template <typename C1, typename C2, typename M, typename... Args>
    bool getWarning(C1 ctr1, C2 ctr2, M mtr, Args... mtrs) {
        return getWarning(mtr) || getWarning(ctr1, ctr2, mtrs...);
    }

    inline bool getMotorError() {
        return false;
    }

    template <typename M, typename... Args>
    bool getMotorError(M mtr, Args... mtrs) {
        return getMotorError(mtr) || getMotorError(mtrs...);
    }

    template <typename M, typename... Args>
    Error::Error(M mtr, Args... mtrs) {
        addDevice(mtr);
        addDevice(mtrs...);
    }

    template <typename C, typename M, typename... Args>
    Error::Error(C ctr, M mtr, Args... mtrs) {
        addDevice(ctr, mtr);
        addDevice(mtrs...);
    }

    template <typename C, typename D, typename M, typename... Args>
    Error::Error(C ctr1, D ctr2, M mtr, Args... mtrs) {
        addDevice(ctr1, ctr2, mtr);
        addDevice(mtrs...);
    }
}