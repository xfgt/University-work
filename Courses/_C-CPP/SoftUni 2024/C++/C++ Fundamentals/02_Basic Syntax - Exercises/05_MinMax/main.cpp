//
// Created by twister on 8/27/24.
//



#include <iostream>


int main(){


    int N, x;


    std::cin >> N;
    std::cin >> x;
    int min = x;
    int max = x;

    for(int i = 0; i < N; i++){

        if(i+1 == N)
            break;
        else
            std::cin >> x;

        if(x < min)
            min = x;

        if(x > max)
            max = x;


    }

    std::cout << min << ' ' << max;



    return 0;
}