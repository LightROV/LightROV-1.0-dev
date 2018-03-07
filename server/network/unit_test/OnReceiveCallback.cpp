//
// Created by itsl on 18-3-7.
//

#include "OnReceiveCallback.hpp"

void on_receive_callback::onDataReceived(std::string& data,
                           boost::asio::ip::tcp::socket** sock) {
    std::cout << data << std::endl;
}
