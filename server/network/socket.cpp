//
// Created by itsl on 18-3-9.
//

#include "socket.hpp"

using namespace ltrov::network;

using ltrov::network::Socket;

template <typename SOCK_TYPE>
Socket<SOCK_TYPE>::Socket(SOCK_TYPE** socket) {
    this->socket = socket;
}