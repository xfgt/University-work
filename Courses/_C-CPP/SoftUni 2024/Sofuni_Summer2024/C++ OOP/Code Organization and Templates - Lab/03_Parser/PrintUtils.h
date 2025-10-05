//
// Created by twister on 7/18/24.
//

#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>
#include <vector>

template <typename T>
void printVector(const std::vector<T>&);

template<typename T>
void printVector(const std::vector<T>& v){
    for(const auto& it : v)
        std::cout << it << ' ';
}

#endif //PRINTUTILS_H
