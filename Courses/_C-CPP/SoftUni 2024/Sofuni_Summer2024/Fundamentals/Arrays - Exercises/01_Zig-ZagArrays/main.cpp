//
// Created by twister on 8/30/24.
//


#include <iostream>
#include <unistd.h>

int main(){
    int N{};
    std::cin >> N;
    if(N < 0 || N > 100)
        return 0;
// n c n c
//   ---
// c n c n

    // (4)
    // 1 5 9 10 31 81 21 20
    // *     *  *        *

    //(2)
    // 80 23 31 19
    // *        *

    int X[N]{}, Y[N]{}, x{}, pause{};
    for(int i = 0, j = 0, k = 0; i < N*2; i++){
        std::cin >> x;

        if(pause == 1 || pause == 2)
            Y[j++] = x;
        else
            X[k++] = x;



        ++pause;
        if(pause > 4)
            pause = 1;



    }

    for(const auto& it : X)
        std::cout << it << ' ';
    std::cout << std::endl;


    for(const auto& it : Y)
        std::cout << it << ' ';
    std::cout << std::endl;

    return 0;
}
