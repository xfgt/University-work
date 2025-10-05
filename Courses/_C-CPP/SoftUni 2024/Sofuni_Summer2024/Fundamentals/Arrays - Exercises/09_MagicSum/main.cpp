//
// Created by twister on 8/30/24.
//


#include <iostream>

int main(){

    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;

    int X[N];
    for(int i = 0; i < N; i++)
        std::cin >> X[i];


    int magicNum{};
    std::cin >> magicNum;


    for(int i = 0; i < N; i++){
        int& current = X[i];
        for(int j = i; j < N; j++){
            int& second = X[j];
            if(current+second == magicNum){
                std::cout << current << ' ' << second << std::endl;
            }
        }
    }




    return 0;
}