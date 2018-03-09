//
// Created by itsl on 18-3-9.
//

#include "tcp_socket.hpp"

using ltrov::network::TcpSocket;
using boost::asio::ip::tcp;


TcpSocket::TcpSocket():Socket<tcp::socket>() {

}

void asyncWrite(std::string data) override {

}