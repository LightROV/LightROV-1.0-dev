//
// Created by itsl on 18-3-7.
//

#include "OnReceiveCallback.hpp"
#include "../listener.hpp"

int main() {
    auto callback = new on_receive_callback();
    auto listener = new ltrov::network::tcp::Listener(2333, 1);
    listener->bind(callback);
    listener->start();
    while(true);
//    return 0;
}