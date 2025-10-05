//
// Created by twister on 8/30/24.
//


#include <iostream>


int main(){


    int N{};
    std::cin >> N;

    int arr[N];
    int j = N-1;
    int x{};
    for(int i = 0; i < N; i++){
        std::cin >> x;
        arr[j--] = x;
    }

    for(const auto& it : arr)
        std::cout << it << ' ';

    return 0;
}