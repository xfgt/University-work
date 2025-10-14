//
// Created by User on Сб-6.7.2024 г..
//

#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H


#include <vector>

template<typename T>
std::vector<T> operator+(const std::vector<T>& obj1, const std::vector<T>& obj2){

    std::vector<T> temp;
    temp.assign(obj1.begin(), obj1.end());
    int i{};

    for(auto& x : temp){
        x += " ";
        x += obj2[i++];
    }

    return temp;

}







#endif //SOLUTION_SOFTUNICPP_OOP_SUMOFVECTORS_H
