CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(LightRO-1.0-mod-network-unittest)
SET(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(Boost REQUIRED COMPONENTS system regex thread)

# Boost 链接库
SET(USED_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

add_executable(tester Tester.cpp OnReceiveCallback.cpp)

target_link_libraries(tester ${USED_LIBS} listener exception log boost_thread)