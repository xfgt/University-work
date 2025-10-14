//
// Created by twister on 8/30/24.
//


#include <iostream>

int main(){

    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;

    int X[N], Y[N*N];
    for(int i = 0; i < N; i++)
        std::cin >> X[i];

    int k{};

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            Y[k++] = X[i] * X[j];
        }
    }


    for(const auto& it : Y)
        std::cout << it << ' ';





    return 0;
}