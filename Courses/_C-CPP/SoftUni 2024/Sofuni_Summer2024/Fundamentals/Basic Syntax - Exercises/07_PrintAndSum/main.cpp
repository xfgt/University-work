//
// Created by twister on 8/27/24.
//



#include <iostream>



int main(){

    int start{}, end{}, sum{};

    std::cin >> start >> end;


    for(int i = start; i <= end; i++){
        std::cout << i << ' ';
        sum += i;

    }

    std::cout << "\nSum: " << sum;


    return 0;
}