//
// Created by ADMIN on 07-Oct-25.
//

#ifndef CPP_FUTUREVALUEERROR_H
#define CPP_FUTUREVALUEERROR_H

#include <stdexcept>
#include <string>
class FutureValueError : public std::logic_error {
public:
    FutureValueError(const std::string& reason);
};




#endif //CPP_FUTUREVALUEERROR_H
