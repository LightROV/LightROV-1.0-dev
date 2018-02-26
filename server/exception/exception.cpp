//
// Created by itsl on 18-2-26.
//

#include "exception.hpp"

using namespace ltrov;

Exception::Exception(int code, std::string what) {
    this->code = code;
    this->what = what;
}

std::string Exception::getMsg() {
    return what;
}

int Exception::getCode() {
    return code;
}