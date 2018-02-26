/* 
 * 监听器的实现
 * 
 * created by itsl<itsl@foxmail.com>
 * 2018-2-10
 */

#include "./listener.hpp"

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>

using ltrov::network::tcp::Listener;

typedef boost::asio::ip::tcp boostTCP;

Listener::Listener(int port) :
    acceptor(io, boostTCP::endpoint(boostTCP::v4(), port)),
    socket(io) {
    this->dataHandler = nullptr;
    this->LISTENING = false;
}

void Listener::bind(CallBackInterface* dataHandler) {
    this->dataHandler = dataHandler;
}

void Listener::start() {
    if (dataHandler == nullptr) {
        throw "";
    }
    listenThread = new boost::thread(boost::bind(&Listener::listenHandler, this));
}

void Listener::onAccept() {
    // 连接成功，开始处理收发数据
    boost::system::error_code ignored_error;
    auto buffer = boost::asio::buffer(buff);
    while (LISTENING) {
        std::size_t length = socket.read_some(buffer, ignored_error);
        if (!ignored_error && length != 0) onRecieveHandler(length);
        else if (ignored_error == boost::asio::error::eof)
            throw "";
    }
}

void Listener::onRecieveHandler(std::size_t length) {
    std::string data(buff.begin(), buff.begin() + length);
    dataHandler->onDataReceived(data);
}

void Listener::listenHandler() {
    while (LISTENING) {
        acceptor.accept(socket);
        this->onAccept();
    }
}