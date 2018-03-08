//
// Created by itsl on 18-3-7.
//

#include "OnReceiveCallback.hpp"
#include "../listener.hpp"
#include "../../log/log.hpp"

void on_receive_callback::onDataReceived(std::string& data,
                           boost::asio::ip::tcp::socket** sock) {
//    std::cout << data << std::endl;
}

void on_receive_callback::onSocketClosed(ltrov::network::tcp::Listener &listener) {
    ltrov::Log::i("port restart", "");
    listener.start();
}
