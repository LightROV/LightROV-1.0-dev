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
#include "../exception/exception.hpp"

using ltrov::network::tcp::Listener;

typedef boost::asio::ip::tcp boostTCP;

Listener::Listener(unsigned short port, short workers) :
    acceptor(io),
    worker(io),
    socket(io) {
    this->dataHandler = nullptr;
    this->LISTENING = false;
    this->workers = workers;
}

void Listener::bind(CallBackInterface* dataHandler) {
    this->dataHandler = dataHandler;
}

void workerStart() {
    for (int i = 0; i < this->workers; ++i) {
        workerGroup.create_thread(boost::bind(&boost::asio::io_service::run, &io));
    }
}

void registeNewAcceptor() {
    boostTCP::socket* sock = new boostTCP::socket(io);
    acceptor.async_accept(
        *sock, 
        boost::bind(
            &Listener::onAccept, 
            this, 
            boost::asio::placeholders::error, 
            &sock
        )
    );
}

void Listener::start() {
    if (dataHandler == nullptr) {
        throw ltrov::Exception(0, "the handler is invalid.");
    }
    workerStart();
    boostTCP::endpoint endp(boostTCP::v4(), port);
    acceptor.bind(endp);
    acceptor.listen();
    registeNewAcceptor();
}

void Listener::onAccept(const boost::system::error_code& error, boostTCP::socket** sock) {
    registeNewAcceptor();
    // 连接成功，开始处理收发数据
    boost::system::error_code ignored_error;
    auto buffer = boost::asio::buffer(buff);
    // TODO: 接收数据并交替处理
    while (LISTENING) {
        std::size_t length = socket.read_some(buffer, ignored_error);
        if (!ignored_error && length != 0) onRecieveHandler(length, sock);
        else if (ignored_error == boost::asio::error::eof)
            throw ltrov::Exception(0, "Connection reset by peer.");
    }
}

void Listener::onRecieveHandler(std::size_t length, boostTCP::socket** sock) {
    std::string data(buff.begin(), buff.begin() + length);
    dataHandler->onDataReceived(data);
}