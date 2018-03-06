//
// Created by itsl on 18-2-26.
//
#include <exception>
#include <string>

#ifndef LIGHTRO_1_0_SERVER_EXCEPTION_HPP
#define LIGHTRO_1_0_SERVER_EXCEPTION_HPP

namespace ltrov{

class Exception: public std::exception
{
protected:
    int code;
    std::string what;
public:
    Exception(int code, std::string what);

    std::string getMsg();

    int getCode();
};

}   // namespace ltrov

#endif //LIGHTRO_1_0_SERVER_EXCEPTION_HPP
