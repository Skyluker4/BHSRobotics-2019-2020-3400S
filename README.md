# BHS Robotics Code - Team 3400S

The code for team 3400S's robot.

## Structure

### [src/](src/)

* [**initialize.cpp**](src/initialize.cpp) - Sets up the robot.
* [**autonomous.cpp**](src/autonomous.cpp) - Code for the autonomous period (15 seconds).
* [**opcontrol.cpp**](src/opcontrol.cpp) - Code for controlling the robot with the controller.

### [include/](include/)

* [**/display/\***](include/display/) - Files required for interacting with the display, should be included in **api.h** and **main.h**.
* [**/okapi/\***](include/okapi) - Files required for OKAPI.
* [**/pros/\***](include/pros) - Files required for interacting with robot API. Included in **api.h** and **main.h**.
* [**api.h**](include/api.h) - The file to include to interact with the robot API.
* [**config.h**](include/config.h) - Robot configuration.
* [**main.h**](include/main.h) - Defines functions to be run by robot and includes **api.h**.

### [firmware/](firmware/)

* Compiled executables for interacting with robot and APIs.

## Building

Requires [PROS-CLI3](https://github.com/purduesigbots/pros-cli3/releases/latest) installed. Build using "prosv5 make".

## Uploading

Plug in V5 brain into computer with micro-USB cable. Upload using "prosv5 upload".

## Resources

BHS Robotics website is [here](https://sites.google.com/bentonvillek12.org/bentonville-robotics/home).

The latest game manual can be viewed [here](https://content.vexrobotics.com/docs/vrc-turning-point/VRC-TurningPoint-GameManual-20180817.pdf).
