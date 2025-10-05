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


    int cnt{}, last{};
    int element{};
    for(int i = 0; i < N; i++){
        int& search = X[i];
        for(int j = 1; j < N-1; j++){
            if(search == X[j]){
                element = search;
                cnt++;
            }
        }
        if(cnt > last){
            last = cnt;
            element = search;
        }

        cnt = 0;
    }


    if(last <= 1) std::cout << X[N-1];
    else
        for(int i = 0; i < last; i++)
            std::cout << element << ' ';



    return 0;
}