//
// Created by twister on 8/30/24.
//


#include <iostream>


int main(){

    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;

    int x{}, sumE{}, sumO{};

    for(int i = 0; i < N; i++){
        std::cin >> x;
        if(x % 2 == 0)
            sumE += x;
        else
            sumO += x;

    }

    std::cout << sumE - sumO;

    return 0;
}