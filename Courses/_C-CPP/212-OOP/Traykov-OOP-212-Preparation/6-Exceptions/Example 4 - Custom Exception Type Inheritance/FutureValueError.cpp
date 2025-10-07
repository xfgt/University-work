//
// Created by ADMIN on 07-Oct-25.
//

#include "FutureValueError.h"

FutureValueError::FutureValueError(const std::string& reason) :
    logic_error(reason) {}
