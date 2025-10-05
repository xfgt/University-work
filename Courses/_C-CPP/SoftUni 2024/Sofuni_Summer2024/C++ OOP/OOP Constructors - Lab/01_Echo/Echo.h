//
// Created by twister on 7/27/24.
//

#ifndef ECHO_H
#define ECHO_H

#include <iostream>


inline bool echoOn{};

inline void echo(const std::string& msg){
    if(echoOn == true){
        std::cout << msg << std::endl;
    }
}



#endif //ECHO_H
