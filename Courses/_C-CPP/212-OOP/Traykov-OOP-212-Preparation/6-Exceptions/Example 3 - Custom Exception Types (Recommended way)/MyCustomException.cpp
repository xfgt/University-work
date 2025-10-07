//
// Created by ADMIN on 07-Oct-25.
//

#include "MyCustomException.h"

MyCustomException::MyCustomException(const std::string &msg) :
    reason(msg) {}

std::string MyCustomException::what() const { return reason; }
