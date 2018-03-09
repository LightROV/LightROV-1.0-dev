# network 模块
CMAKE_MINIMUM_REQUIRED(VERSION 3.5)
PROJECT(LightRO-1.0-mod-network)
SET(CMAKE_CXX_STANDARD 11)

FIND_PACKAGE(Boost REQUIRED COMPONENTS system thread regex)
IF(Boost_FOUND)
    INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS})
    LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
ENDIF(Boost_FOUND)

# Boost 链接库
SET(BOOST_LIBS ${Boost_SYSTEM_LIBRARY} ${Boost_THREAD_LIBRARY} ${Boost_REGEX_LIBRARY})

ADD_LIBRARY(listener STATIC listener.cpp)
TARGET_LINK_LIBRARIES(listener ${BOOST_LIBS})

ADD_LIBRARY(basesocket STATIC socket.cpp socket.hpp)
TARGET_LINK_LIBRARIES(basesocket ${BOOST_LIBS})

ADD_LIBRARY(tcpsocket tcp_socket.cpp tcp_socket.hpp)
TARGET_LINK_LIBRARIES(tcpsocket ${BOOST_LIBS} basesocket)

ADD_SUBDIRECTORY(unit_test)
