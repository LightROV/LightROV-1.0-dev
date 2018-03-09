cmake_minimum_required(VERSION 3.5)
project(lightROV-controller-mod)

set(CMAKE_CXX_STANDARD 11)

add_library(controller STATIC base_controller.cpp base_controller.hpp)

# add_subdirectory(unit_test)