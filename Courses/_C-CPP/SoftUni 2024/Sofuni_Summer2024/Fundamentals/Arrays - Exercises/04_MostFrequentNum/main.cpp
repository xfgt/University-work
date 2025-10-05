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
    for(int i = 0; i < N; i++){
        std::cin >> X[i];
        if(!(X[i] >= 0 && X[i] <= 9))
            return 0;
    }

    int cnt{}, last{}, hold{};

    for(int i = 0; i < N; i++){
        int& search = X[i];
        for(int j = 0; j < N; j++){
            if(search == X[j])
                cnt++;

            if(cnt > last){
                hold = search;
                last = cnt;
            }
        }
        cnt = 0;
    }


    std::cout << hold ;





    return 0;
}