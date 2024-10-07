cmake_minimum_required(VERSION 3.13)

project(DroneControl LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

set(MAVLINK_INC_DIR "/Users/code/drone-lab-controls/libraries/mavlink/common")

include_directories(${MAVLINK_INC_DIR})


add_executable(DroneControl core/main.c)

target_include_directories(DroneControl PRIVATE ${MAVLINK_INC_DIR})
