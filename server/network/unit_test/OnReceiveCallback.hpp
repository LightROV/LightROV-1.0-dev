//
// Created by itsl on 18-3-7.
//

#ifndef LIGHTRO_1_0_SERVER_ONRECEIVECALLBACK_HPP
#define LIGHTRO_1_0_SERVER_ONRECEIVECALLBACK_HPP

#include "../callback_interface.hpp"

using ltrov::network::CallBackInterface;

class on_receive_callback: public CallBackInterface
{
public:
    void onDataReceived(std::string& data, boost::asio::ip::tcp::socket** sock);

    void onSocketClosed(ltrov::network::tcp::Listener &listener) override;
};


#endif //LIGHTRO_1_0_SERVER_ONRECEIVECALLBACK_HPP
