//
// Created by twister on 8/30/24.
//


#include <iostream>

int main(){

    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;

    int X[N], rotations{};
    for(int i = 0; i < N; i++)
        std::cin >> X[i];

    std::cin >> rotations;


    int hold{};
    for(int i = 0; i < rotations; i++){
        hold = X[0];
        for(int j = 0; j < N-1; j++){
            X[j] = X[j+1];
        }
        X[N-1] = hold;
    }


    for(const auto& it : X)
        std::cout << it << ' ';


    return 0;
}