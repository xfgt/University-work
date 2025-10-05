//
// Created by twister on 8/30/24.
//


#include <iostream>


int main(){

    std::string days[8] = {"Invalid day!", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

    int x{};
    std::cin >> x;

    if(x >= 1 && x <= 7)
        std::cout << days[x];
    else
        std::cout << days[0];


    return 0;
}