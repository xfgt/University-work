//
// Created by twister on 8/30/24.
//


#include <iostream>


int main(){

    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;

    int e{}, sum{};

    for(int i = 0; i < N; i++){
        std::cin >> e;
        if(e % 2 == 0)
            sum += e;
    }

    std::cout << sum;

    return 0;
}