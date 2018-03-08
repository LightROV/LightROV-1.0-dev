/*
 * 监听器的实现
 *
 * created by itsl<itsl@foxmail.com>
 * 2018-2-10
 */

#include "./listener.hpp"

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
    this->LISTENING = true;
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
//    boostTCP::endpoint endp(boostTCP::v4(), port);
//    try{
//        acceptor.bind(endp);
//        acceptor.listen();
//    } catch (std::exception& e) {
//        std::cout << e.what() << std::endl;
//        return;
//    }
    registerNewAcceptor();
}

void Listener::onAccept(const boost::system::error_code& error,
                        boostTCP::socket** sock) {
    registerNewAcceptor();
    // std::cout << "连接成功" << std::endl;
    auto remote_end = (*sock)->remote_endpoint();
    Log::i(
            "Client-Connected",
            "Client "
            + remote_end.address().to_string()
            + ":"
            + std::to_string((int)remote_end.port())
            + " connected."
    );
    // 连接成功，开始处理收发数据
    boost::system::error_code ignored_error;
    auto buffer = boost::asio::buffer(buff);
    // TODO: 接收数据并交替处理
    while (LISTENING) {
        std::size_t length = 0;
        // 判断 socket 是否关闭
        if ((*sock)->is_open()){
            length = (*sock)->read_some(buffer, ignored_error);
        } else {
            break;
        }
        if (!ignored_error && length != 0) {
            std::cout << length << std::endl;
            onReceiveHandler(length, sock);
        }
        else if (ignored_error == boost::asio::error::eof) {
            (*sock)->close();
            Log::e(
                    "Connection-Reset",
                    "Connection reset by peer: " + remote_end.address().to_string()
            );
        }
    }
    (*sock)->close();
}

void Listener::onReceiveHandler(std::size_t length,
                                boostTCP::socket** sock) {
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
}

Listener::~Listener() {
    LISTENING = false;
    this->io.stop();
    this->workerGroup.join_all();
}