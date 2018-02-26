cmake_minimum_required(VERSION 3.5)
project(ltrov_log)
set(CMAKE_CXX_STANDARD 11)

add_library(log STATIC log.cpp)

add_executable(log_tester log_tester.cpp)
target_link_libraries(log_tester log)