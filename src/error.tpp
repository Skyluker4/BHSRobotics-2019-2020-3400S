#include <cstdint>
#include "api.h"
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
        getMotorError(mtr);
        getError(ctr1, ctr2, mtrs...);
    }

    template <typename M, typename... Args>
    void getWarning(M mtr, Args... mtrs) {
        getMotorError(mtr);
        getWarning(mtrs...);
    }

    template <typename C1, typename M, typename... Args>
    void getWarning(C1 ctr, M mtr, Args... mtrs) {
        getMotorError(mtr);
        getWarning(ctr, mtrs...);
    }

    template <typename C1, typename C2, typename M, typename... Args>
    void getWarning(C1 ctr1, C2 ctr2, M mtr, Args... mtrs) {
        getMotorError(mtr);
        getWarning(ctr1, ctr2, mtrs...);
    }

    template <typename M, typename... Args>
    void getMotorError(M mtr, Args... mtrs) {
        std::uint32_t faults = mtr.get_faults();

        if (mtr.get_flags() & pros::E_MOTOR_FLAGS_BUSY)
            lastError = lastWarning = ERROR_MOTOR_NOCOMM | mtr._port;

        if (faults == pros::E_MOTOR_FAULT_NO_FAULTS)
            return;

        switch (faults)
        {
        case pros::E_MOTOR_FAULT_MOTOR_OVER_TEMP:
            lastError = lastWarning = ERROR_MOTOR_TEMPERATURE | mtr._port;
            break;
        case pros::E_MOTOR_FAULT_DRIVER_FAULT:
            lastError = lastWarning = ERROR_MOTOR_HBRIDGE_FAULT | mtr._port;
            break;
        case pros::E_MOTOR_FAULT_OVER_CURRENT:
            lastError = lastWarning = ERROR_MOTOR_CURRENT;
            break;
        case pros::E_MOTOR_FAULT_DRV_OVER_CURRENT:
            lastError = lastWarning = ERROR_MOTOR_HBRIDGE_CURRENT;
            break;
        }

        getMotorError(mtrs...);
    }
}