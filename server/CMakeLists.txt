cmake_minimum_required(VERSION 3.5)
project(LightRO-1.0-server)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(network bin/network)
add_subdirectory(log bin/log)
add_subdirectory(exception bin/exception)