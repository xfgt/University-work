//
// Created by twister on 9/6/24.
//

#include <iostream>
#include <vector>


int main(){
    std::vector<int> v;

    int x{};
    while(std::cin >> x)
        v.push_back(x);


    int N = v.size();



    for(size_t i = 0; i < N/2; i++){

        std::cout << v[i] + v[N-i-1] << ' ';


    }
    if(!(N % 2 == 0))
        std::cout << v[N/2];
    return 0;
}