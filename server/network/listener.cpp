/*
 * 监听器的实现
 *
 * created by itsl<itsl@foxmail.com>
 * 2018-2-10
 */

#include "listener.hpp"

#include "../exception/exception.hpp"
#include "../log/log.hpp"

using ltrov::network::tcp::Listener;
using ltrov::Log;

typedef boost::asio::ip::tcp boostTCP;

Listener::Listener(unsigned short port, short workers) :
    acceptor(io, boostTCP::endpoint(boostTCP::v4(), port)),
    worker(io),
    socket(io) {
    this->dataHandler = nullptr;
    this->workers = workers;
    this->port = port;
}

void Listener::bind(CallBackInterface* dataHandler) {
    this->dataHandler = dataHandler;
}

void Listener::workerStart() {
    for (int i = 0; i < workers; ++i) {
        workerGroup.create_thread(boost::bind(&boost::asio::io_service::run, &io));
    }
}

void Listener::registerNewAcceptor() {
    auto sock = new boostTCP::socket(io);
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
    registerNewAcceptor();
}

void Listener::onAccept(const boost::system::error_code& error,
                        boostTCP::socket** sock) {
    registerNewAcceptor();
    auto remote_end = (*sock)->remote_endpoint();
    Log::i(
            "Client-Connected",
            "Client "
            + remote_end.address().to_string()
            + ":"
            + std::to_string((int)remote_end.port())
            + " connected."
    );
    // 接收数据
    if ((*sock)->is_open()) {
        registerAsyncReceive(sock);
    }
}

void Listener::onReceiveHandler(std::size_t length,
                                const boost::system::error_code& error,
                                boostTCP::socket** sock) {
    if (error && error != boost::asio::error::message_size) {
        auto remote_end = (*sock)->remote_endpoint();
        if (error == boost::asio::error::eof) {
            Log::e(
                    "Conn-Reset",
                    "Connection reset by peer "
                    + remote_end.address().to_string()
                    + ":"
                    + std::to_string((int)remote_end.port())
                    + "."
            );
            return;
        }
    }
    std::string data(buff.begin(), buff.begin() + length);
    auto remote_end = (*sock)->remote_endpoint();
    Log::i(
            "Receive-Data",
            "Client "
            + remote_end.address().to_string()
            + ":"
            + std::to_string((int)remote_end.port())
            + " send:'"
            + data
            + "'."
    );
    dataHandler->onDataReceived(data, sock);
    // NOTE: sock is unusable when it's closed.
    if ((*sock)->is_open())
        registerAsyncReceive(sock);
    else
        delete *sock;
}

Listener::~Listener() {
    this->io.stop();
    this->workerGroup.join_all();
}

void ltrov::network::tcp::Listener::registerAsyncReceive(boostTCP::socket **sock) {
    auto buffer = boost::asio::buffer(buff);
    (*sock)->async_read_some(
            buffer,
            boost::bind(
                    &Listener::onReceiveHandler,
                    this,
                    boost::asio::placeholders::bytes_transferred,
                    boost::asio::placeholders::error,
                    sock
            )
    );
}
