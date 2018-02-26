//
// Created by itsl on 18-2-26.
//

#include "log.hpp"

int main(int argc, char* args[]) {
    ltrov::Log::i("Connection Reset", "the connection to 192.168.1.11 is reset by peer.");
    ltrov::Log::e("Connection Reset", "the connection to 192.168.1.11 is reset by peer.");
    return 0;
}