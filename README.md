# Welcome to the Drone Controls Repository


## Overview

## Source Documentation

## MAVLink
High level controls will utiilize the MAVLink library.

> **MAVLink is a very lightweight messaging protocol for communicating with drones (and between onboard drone components). MAVLink follows a modern hybrid publish-subscribe and point-to-point design pattern: Data streams are sent / published as topics while configuration sub-protocols such as the mission protocol or parameter protocol are point-to-point with retransmission.**

Source: The [MAVLink Website](https://mavlink.io/en/)

#### Brief Overview of MAVLink

Using MAVLink, a set of "messages" are continuously exchanged between drone and ground control in order to control and monitor that state of the drone.

Typically, MAVLink protocol is implemented inside the autopilot system - Ardupilot - which autonmously governs the direction and control of the drone.