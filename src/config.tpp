#include "config.hpp"

template <typename M, typename... Args>
Config::Config(M mtr, Args... mtrs) {
    addDevice(mtr);
    addDevice(mtrs...);
}

template <typename C, typename M, typename... Args>
Config::Config(C ctr, M mtr, Args... mtrs) {
    addDevice(ctr, mtr);
    addDevice(mtrs...);
}

template <typename C, typename D, typename M, typename... Args>
Config::Config(C ctr1, D ctr2, M mtr, Args... mtrs) {
    addDevice(ctr1, ctr2, mtr);
    addDevice(mtrs...);
}

template <typename M, typename... Args>
bool Config::addDevice(M mtr, Args... mtrs) {
    return addDevice(mtr) && addDevice(mtrs...);
}

template <typename C, typename M, typename... Args>
bool Config::addDevice(C ctr, M mtr, Args... mtrs) {
    return addDevice(ctr, mtr) && addDevice(mtrs...);
}

template <typename C, typename D, typename M, typename... Args>
bool Config::addDevice(C ctr1, D ctr2, M mtr, Args... mtrs) {
    addDevice(ctr1, ctr2, mtr) && addDevice(mtrs...);
}

template <typename M, typename... Args>
bool Config::removeDevice(M mtr, Args... mtrs) {
    return removeDevice(mtr) && removeDevice(mtrs...);
}

template <typename C, typename M, typename... Args>
bool Config::removeDevice(C ctr, M mtr, Args... mtrs) {
    return removeDevice(ctr, mtr) && removeDevice(mtrs...);
}

template <typename C, typename D, typename M, typename... Args>
bool Config::removeDevice(C ctr1, D ctr2, M mtr, Args... mtrs) {
    return removeDevice(ctr1, ctr2, mtr) && removeDevice(mtrs...);
}