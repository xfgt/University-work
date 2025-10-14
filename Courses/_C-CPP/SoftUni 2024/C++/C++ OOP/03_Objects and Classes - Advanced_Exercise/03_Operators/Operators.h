//
// Created by User on Сб-6.7.2024 г..
//

#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>


template<typename T>
std::vector<T>& operator<<(std::vector<T>&V, const std::string& s1){
    V.push_back(s1);
    return V;
}

template<typename T>
std::ostream& operator<<(std::ostream& OUT, const std::vector<T>& v1){
    for(int i = 0; i < v1.size(); i++){
        if(i == v1.size()-1)
            OUT << v1[i];
        else
            OUT << v1[i] << std::endl;
    }
    return OUT;
}



std::string operator+(std::string& s1, const int& n){
    s1.append(std::to_string(n));
    return s1;
}



#endif //OPERATORS_H
