cmake_minimum_required(VERSION 3.13)

project(DroneControl LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

include_directories(${CMAKE_SOURCE_DIR}/mavlink/include)


add_executable(DroneControl core/main.c)