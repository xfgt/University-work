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


    int A[N]{}, k{};

    for(int i = 0; i < N; i++){

        int& current = X[i];

        while(current < X[i+1] && i < N-1)
            current = X[++i];

        //A[k++] = current;
        std::cout << current << ' ';

    }

    // for(int i = 0; i < k; i++){
    //     if(A[i] > A[i+1]){
    //         std::cout << A[i] << ' ';
    //     }
    // }



    return 0;
}