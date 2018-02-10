/* 
 * 监听器的实现
 * 
 * created by itsl<itsl@foxmail.com>
 * 2018-2-10
 */

#include "./listener.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>

using ltrov::network::tcp::Listener;

typedef boost::asio::ip::tcp boostTCP;

Listener::Listener(int port) :
    acceptor(io, boostTCP::endpoint(boostTCP::v4(), port)),
    socket(io) {
    this->dataHandler = nullptr;
}

void Listener::bind(CallBackInterface* dataHandler) {
    this->dataHandler = dataHandler;
}

void Listener::start() {
    if (dataHandler == nullptr) {
        std::exception err;
        err.what = "data handler has not been set.";
        throw err;
    }
    acceptor.async_accept(socket, 
        boost::bind(
            &Listener::onAccept, 
            this, 
            boost::asio::placeholders::error));
}

void Listener::onAccept(const boost::system::error_code& error) {
    // 连接成功，开始处理收发数据
    std::string data;
    socket.async_receive(
        boost::asio::buffer(data), 
        boost::bind(&dataHandler->onDataReceived, data));
}