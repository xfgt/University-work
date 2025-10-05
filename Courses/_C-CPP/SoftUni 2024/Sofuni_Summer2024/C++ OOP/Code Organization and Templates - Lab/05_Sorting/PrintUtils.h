//
// Created by twister on 7/21/24.
//

#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>
#include <iterator>


template<typename T>
void printContainer(const typename T::iterator& begin, const typename T::iterator& end){
    for(auto it = begin; it != end; ++it){
        std::cout << *it << ' ';
    }
}

















#endif //PRINTUTILS_H
