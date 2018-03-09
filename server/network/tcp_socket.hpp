//
// Created by itsl on 18-3-9.
//

#ifndef LIGHTRO_1_0_SERVER_TCP_SOCKET_HPP
#define LIGHTRO_1_0_SERVER_TCP_SOCKET_HPP

#include "socket.hpp"

namespace ltrov{
namespace network{
class TcpSocket: public Socket {
public:
    TcpSocket();

    void asyncWrite(std::string data) override;

    std::size_t write(std::string data) override;
};
}
}

#endif //LIGHTRO_1_0_SERVER_TCP_SOCKET_HPP
