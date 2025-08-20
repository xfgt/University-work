#include <iostream>



int main(){

    int setA[10] {5, 2, 3, 8, 1, 6, 4, 12, 9, 7};

    int sum{};

    for(int i = 0; i < 10; i++){
        if(setA[i] >= setA[0] && setA[i] <= setA[9])
            sum += setA[i];
    }
    std::cout << sum << std::endl;


    return 0;
}