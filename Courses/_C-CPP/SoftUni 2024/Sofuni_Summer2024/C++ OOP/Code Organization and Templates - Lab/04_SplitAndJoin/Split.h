//
// Created by twister on 7/19/24.
//

#ifndef SPLIT_H
#define SPLIT_H
//returns a vector

#include <iostream>
#include <vector>
#include <sstream>


template<typename X>
std::vector<X> split(std::string line, char seperator){
    std::vector<X> v;

    std::string sample{};
    std::stringstream ss(line);

    while(std::getline(ss, sample, seperator)){
        X type;
        std::stringstream xs(sample);
        xs >> type;
        v.push_back(type);
    }

    return v;
}



#endif //SPLIT_H