#include <map>
#include <functional>
#include <cstdint>

#include "api.h"
#include "config.hpp"

pros::Controller ctr_master(pros::E_CONTROLLER_MASTER);

pros::Motor mtr_frontLeft(7, true);
pros::Motor mtr_backLeft(6, true);
pros::Motor mtr_frontRight(9);
pros::Motor mtr_backRight(10);
pros::Motor mtr_combine(1);
pros::Motor mtr_launcher1(4);
pros::Motor mtr_launcher2(5);

Config::Config(pros::Motor &mtr) {
    addDevice(mtr);
}

Config::Config(pros::Controller &ctr) {
    addDevice(ctr);
}

Config::Config(pros::Controller &ctr1, pros::Controller &ctr2) {
    addDevice(ctr1, ctr2);
}

Config::Config(pros::Controller &ctr, pros::Motor &mtr) {
    addDevice(ctr, mtr);
}

Config::Config(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr) {
    addDevice(ctr1, ctr2, mtr);
}

bool Config::addDevice(pros::Motor &mtr) {
    try {
        Motors.emplace(mtr._port, std::ref(mtr));
    }
    catch (...){
        return false;
    }
    return true;
}

bool Config::addDevice(pros::Controller &ctr) {
    try {
        Controllers.emplace(ctr._id, std::ref(ctr));
    }
    catch (...){
        return false;
    }
    return true;
}

bool Config::addDevice(pros::Controller &ctr1, pros::Controller &ctr2) {
    try {
        Controllers.emplace(ctr1._id, std::ref(ctr1));
        Controllers.emplace(ctr2._id, std::ref(ctr2));
    }
    catch (...) {
        return false;
    }
    return true;
}

bool Config::addDevice(pros::Controller &ctr, pros::Motor &mtr) {
    try {
        Controllers.emplace(ctr._id, std::ref(ctr));
        Motors.emplace(mtr._port, std::ref(mtr));
    }
    catch (...) {
        return false;
    }
    return true;
}

bool Config::addDevice(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr) {
    try {
        Controllers.emplace(ctr1._id, std::ref(ctr1));
        Controllers.emplace(ctr1._id, std::ref(ctr1));
        Motors.emplace(mtr._port, std::ref(mtr));
    }
    catch (...) {
        return false;
    }
    return true;
}

bool Config::removeDevice(pros::Motor &mtr) {
    try {
        Motors.erase(mtr._port);
    } catch (...) {
        return false;
    }
    return true;
}

bool Config::removeDevice(pros::Controller &ctr) {
    try {
        Controllers.erase(ctr._id);
    } catch(...) {
        return false;
    }
    return true;
}

bool Config::removeDevice(pros::Controller &ctr1, pros::Controller &ctr2) {
    try {
        Controllers.erase(ctr1._id);
        Controllers.erase(ctr2._id);
    } catch (...) {
        return false;
    }
}

bool Config::removeDevice(pros::Controller &ctr, pros::Motor &mtr) {
    try {
        Controllers.erase(ctr._id);
        Motors.erase(mtr._port);
    } catch(...) {
        return false;
    }
    return true;
}

bool Config::removeDevice(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr) {
    try {
        Controllers.erase(ctr1._id);
        Controllers.erase(ctr2._id);
    } catch(...) {
        return false;
    }
    return true;
}

bool Config::removeDevice(std::uint_fast8_t port) {
    try {
        Motors.erase(port);
    } catch(...) {
        return false;
    }
    return true;
}

bool Config::removeDevice(pros::controller_id_e_t id) {
    try {
        Controllers.erase(id);
    } catch(...) {
        return false;
    }
    return true;
}