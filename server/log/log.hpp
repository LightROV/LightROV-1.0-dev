//
// Created by itsl on 18-2-26.
//

#ifndef LIGHTRO_1_0_SERVER_LOG_HPP
#define LIGHTRO_1_0_SERVER_LOG_HPP

#include <iostream>

namespace ltrov{

enum LOG_TYPE {ERROR, INFO};

class Log
{
public:
    std::string tag;
    std::string text;

    static void i(std::string tag, std::string text);

    static void e(std::string tag, std::string text);
};

}   //namespace ltrov

#endif //LIGHTRO_1_0_SERVER_LOG_HPP
