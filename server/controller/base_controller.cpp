//
// Created by itsl on 18-3-8.
//

#include "base_controller.hpp"

#include <iostream>

using namespace std;
using ltrov::controller::BaseController;

BaseController::BaseController() {
}

BaseController::~BaseController() {
}

unsigned int BaseController::getEventId() {
    return event;
}
