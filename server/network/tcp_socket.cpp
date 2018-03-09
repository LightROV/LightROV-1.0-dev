//
// Created by itsl on 18-3-9.
//

#include "tcp_socket.hpp"

#include <boost/bind.hpp>

using ltrov::network::TcpSocket;
using ltrov::network::Socket;
using boost::asio::ip::tcp;

TcpSocket::TcpSocket(tcp::socket** socket):
        Socket<tcp::socket>(socket) {

}

void TcpSocket::asyncWrite(std::string data) {
    (*this->socket)->async_write_some(
            boost::asio::buffer(data),
            boost::bind(&TcpSocket::asyncWriteCallBack,
                        this,
                        boost::asio::placeholders::bytes_transferred,
                        boost::asio::placeholders::error)
    );
}

void TcpSocket::asyncWriteCallBack(std::size_t bytesTransed,
                                   const boost::system::error_code& error) {
    // TODO: handle the sent-event
}

std::size_t TcpSocket::write(std::string data) {
    return (*this->socket)->write_some(boost::asio::buffer(data));
}
