//
// Created by twister on 8/30/24.
//


#include <iostream>


int main(){

    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;


    std::string arr[N];
    int j = N-1;
    std::string x{};
    for(int i = 0; i < N; i++){
        std::cin >> x;
        arr[j--] = x;
    }

    for(const auto& it : arr)
        std::cout << it << ' ';

    return 0;
}