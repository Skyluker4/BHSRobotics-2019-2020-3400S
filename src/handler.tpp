#include <cstdint>

#include "pros/motors.hpp"
#include "pros/misc.hpp"
#include "error.hpp"

#include "handler.hpp"

namespace handler {
    template <typename M, typename... Args>
    Handler::Handler(M mtr, Args... mtrs) {
        addDevice(mtr);
        addDevice(mtrs...);
    }

    template <typename C, typename M, typename... Args>
    Handler::Handler(C ctr, M mtr, Args... mtrs) {
        addDevice(ctr, mtr);
        addDevice(mtrs...);
    }

    template <typename C, typename D, typename M, typename... Args>
    Handler::Handler(C ctr1, D ctr2, M mtr, Args... mtrs) {
        addDevice(ctr1, ctr2, mtr);
        addDevice(mtrs...);
    }
}