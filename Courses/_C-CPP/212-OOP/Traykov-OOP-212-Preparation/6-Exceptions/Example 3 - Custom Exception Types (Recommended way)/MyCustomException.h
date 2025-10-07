//
// Created by ADMIN on 07-Oct-25.
//

#ifndef CPP_MYCUSTOMEXCEPTION_H
#define CPP_MYCUSTOMEXCEPTION_H


#include <string>
class MyCustomException {
private:
    std::string reason;

public:
    MyCustomException(const std::string& msg);
    std::string what() const;

};


#endif //CPP_MYCUSTOMEXCEPTION_H