//
// Created by itsl on 18-3-8.
//

#ifndef LIGHTRO_1_0_SERVER_DEVICE_CONTROLLER_HPP
#define LIGHTRO_1_0_SERVER_DEVICE_CONTROLLER_HPP

#include "../base_controller.hpp"

#include <iostream>

using namespace std;
using ltrov::controller::BaseController;

class DeviceController: public BaseController
{
private:

public:
    DeviceController() {
        cout << "child controller construct function" << endl;
    }

    ~DeviceController() {
        cout << "child controller destruct function" << endl;
    }

};

#endif //LIGHTRO_1_0_SERVER_DEVICE_CONTROLLER_HPP
