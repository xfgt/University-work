//
// Created by twister on 8/27/24.
//


#include <iostream>



int main(){

    int x{};
    std::cin >> x;
    int smallest = x;

    for(int i = 0; i < 3; i++){
        if(i + 1 == 3)
            break;
        std::cin >> x;
        if(x < smallest)
            smallest = x;
    }

    std::cout << smallest;

    return 0;
}