//
// Created by twister on 8/30/24.
//


#include <iostream>

int main(){
    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;

    int X[N], avg{};
    for(int i = 0; i < N; i++){
        std::cin >> X[i];
        avg += X[i];
    }
    avg /= N;

    for(int i = 0; i < N; i++){
        if(X[i] >= avg)
            std::cout << X[i] << ' ';
    }



    return 0;
}