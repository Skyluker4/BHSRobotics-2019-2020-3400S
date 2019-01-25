#ifndef _CONFIG_HEADER
#define _CONFIG_HEADER

#include <map>
#include <cstdint>
#include <functional>
#include "api.h"

extern pros::Controller ctr_master;

extern pros::Motor mtr_frontLeft;
extern pros::Motor mtr_backLeft;
extern pros::Motor mtr_frontRight;
extern pros::Motor mtr_backRight;
extern pros::Motor mtr_combine;
extern pros::Motor mtr_launcher1;
extern pros::Motor mtr_launcher2;

class Config {
protected:
    std::map<std::uint_fast8_t, std::reference_wrapper<pros::Motor>> Motors;
    std::map<pros::controller_id_e_t, std::reference_wrapper<pros::Controller>> Controllers;

    inline void addDevice() {}

public:
    Config();
    Config(pros::Motor &mtr);
    Config(pros::Controller &ctr);
    Config(pros::Controller &ctr1, pros::Controller &ctr2);
    Config(pros::Controller &ctr, pros::Motor &mtr);
    Config(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr);
    template <typename M, typename... Args> Config(M mtr, Args... mtrs);
    template <typename C, typename M, typename... Args> Config(C ctr, M mtr, Args... mtrs);
    template <typename C, typename D, typename M, typename... Args> Config(C ctr1, D ctr2, M mtr, Args... mtrs);

    bool addDevice(pros::Motor &mtr);
    bool addDevice(pros::Controller &ctr);
    bool addDevice(pros::Controller &ctr1, pros::Controller &ctr2);
    bool addDevice(pros::Controller &ctr, pros::Motor &mtr);
    bool addDevice(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr);
    template <typename M, typename... Args> bool addDevice(M mtr, Args... mtrs);
    template <typename C, typename M, typename... Args> bool addDevice(C ctr, M mtr, Args... mtrs);
    template <typename C, typename D, typename M, typename... Args> bool addDevice(C ctr1, D ctr2, M mtr, Args... mtrs);

    bool removeDevice(pros::Motor &mtr);
    bool removeDevice(pros::Controller &ctr);
    bool removeDevice(pros::Controller &ctr1, pros::Controller &ctr2);
    bool removeDevice(pros::Controller &ctr, pros::Motor &mtr);
    bool removeDevice(pros::Controller &ctr1, pros::Controller &ctr2, pros::Motor &mtr);
    bool removeDevice(std::uint_fast8_t port);
    bool removeDevice(pros::controller_id_e_t id);
    template <typename M, typename... Args> bool removeDevice(M mtr, Args... mtrs);
    template <typename C, typename M, typename... Args> bool removeDevice(C ctr, M mtr, Args... mtrs);
    template <typename C, typename D, typename M, typename... Args> bool removeDevice(C ctr1, D ctr2, M mtr, Args... mtrs);

    inline pros::Controller& getControllerFromID(pros::controller_id_e_t id) {
        return Controllers.at(id);
    }

    inline pros::Motor& getMotorFromPort(std::uint_fast8_t port) {
        return Motors.at(port);
    }

    inline std::uint_fast8_t getNumberOfMotors() {
        return Motors.size();
    }

    inline std::uint_fast8_t getNumberOfControllers() {
        return Controllers.size();
    }

    inline std::map<pros::controller_id_e_t, std::reference_wrapper<pros::Controller>> getControllerMap() {
        return Controllers;
    }

    inline std::map<std::uint_fast8_t, std::reference_wrapper<pros::Motor>> getMotorMap() {
        return Motors;
    }
};

// Implement the templates
#include "../src/config.tpp"

#endif