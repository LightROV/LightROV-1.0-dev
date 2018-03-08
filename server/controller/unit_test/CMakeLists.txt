cmake_minimum_required(VERSION 3.5)
project(lightROV-controller-unittest)

set(CMAKE_CXX_STANDARD 11)

add_executable(controller_tester tester.cpp)
target_link_libraries(controller_tester controller)