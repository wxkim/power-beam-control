# Welcome to the Power Beaming Drone Controls Repository

## Overview

### Development

Clone with:

```
git clone --recurse-submodules https://github.com/wxkim/power-beam-control.git
```

Ensure that the MAVLink submodule is initialized correctly.

### Required Tools

- STM32CubeIDE
- Git / GitHub Desktop
- Visual Studio Code (optional)
- the GNU Arm Toolchain: `gcc-arm-none-eabi`

Please compile and build with default compiler flags AND `-wall -werror`

## Source Documentation

## MAVLink

High level controls will utiilize the MAVLink library.
Source: The [MAVLink Website](https://mavlink.io/en/)

#### Brief Overview of MAVLink

Using MAVLink, a set of "messages" are continuously exchanged between drone and ground control in order to control and monitor that state of the drone.

MAVLink protocol is to be implemented inside the autopilot system - Ardupilot - which autonmously governs the direction and control of the drone.

## PX4 Pixhawk Flight Computer
