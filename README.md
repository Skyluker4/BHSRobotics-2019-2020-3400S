# BHS Robotics Code - Team 3400S

The code for team 3400S's robot.

## Structure

### [src/](src/)

* [**initialize.cpp**](src/initialize.cpp) - Sets up the robot.
* [**autonomous.cpp**](src/autonomous.cpp) - Code for the autonomous period (15 seconds).
* [**opcontrol.cpp**](src/opcontrol.cpp) - Code for controlling the robot with the controller.
* [**error.cpp**](src/error.cpp) - Code for the catching of errors.
* [**error.tpp**](src/error.tpp) - Implementation of the templates defined in **error.hpp** since templates have to be defined/included in header files.

### [include/](include/)

* [**/display/\***](include/display/) - Files required for interacting with the display, **lvgl.h** should be included in **api.h** and **main.h**.
* [**/okapi/\***](include/okapi) - Files required for OKAPI.
* [**/pros/\***](include/pros) - Files required for interacting with robot API. Included in **api.h** and **main.h**.
  * [misc.hpp](include/pros/misc.hpp) - This file has been edited to make **controller_id_e_t pros::Controller::_id** public instead of private.
  * [motors.hpp](include/pros/motors.hpp) - This file has been edited to make **const std::uint8_t pros::Motor::_port** public instead of private.
* [**api.h**](include/api.h) - The file to include to interact with the robot API.
* [**config.hpp**](include/config.hpp) - Robot configuration.
* [**error.hpp**](include/error.hpp) - The file to include to handle robot errors.
* [**main.h**](include/main.h) - Defines functions to be run by robot and includes **api.h**.

### [firmware/](firmware/)

* Compiled executables for interacting with robot and APIs.

## Building

Requires [PROS-CLI3](https://github.com/purduesigbots/pros-cli3/releases/latest) installed. Build using "**prosv5 make**".

## Uploading

Plug in V5 brain into computer with micro-USB cable. Upload using "**prosv5 upload**".

## Resources

BHS Robotics website is [here](https://sites.google.com/bentonvillek12.org/bentonville-robotics/home).

The latest game manual can be viewed [here](https://content.vexrobotics.com/docs/vrc-turning-point/VRC-TurningPoint-GameManual-20180817.pdf).