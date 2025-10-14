//
// Created by twister on 8/30/24.
//


#include <iostream>
#include <cmath>

int main(){

    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;

    int X[N];
    for(int i = 0; i < N; i++)
        std::cin >> X[i];



    int diff{}, old{-99999};
    for(int i = 0; i < N; i++){
        int& first = X[i];
        for(int j = i+1; j < N; j++){
            int& second = X[j];
            diff = first - second;

            if(old < diff){
                if(abs(old) > abs(diff))
                    old = diff;
            }
        }

    }

    std::cout << abs(old);



    return 0;
}