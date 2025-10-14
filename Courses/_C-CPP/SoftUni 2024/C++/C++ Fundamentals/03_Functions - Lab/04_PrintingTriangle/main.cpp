//
// Created by twister on 8/27/24.
//


#include <iostream>



int main(){

    int x{};
    std::cin >> x;


    // top

    for(int i = 1; i < x; i++){
        for(int j = 1; j <= i; j++)
            std::cout << j << ' ';
        std::cout << std::endl;
    }

    // mid
    for(int i = 1; i <= x; i++)
        std::cout << i << ' ';
    std::cout << std::endl;

    // bottom
    for(int i = x; i > 1; --i){
        for(int j = 1; j < i; j++)
            std::cout << j << ' ';
        std::cout << std::endl;
    }

    return 0;
}