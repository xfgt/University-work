//
// Created by twister on 8/27/24.
//


#include <iomanip>
#include <iostream>

long fact(double x){
    if(x <= 1)
        return 1;

    long fact{1};

    while(x != 1){
        fact *= x;
        --x;
    }
    return fact;
}
int main(){

    std::cout << std::setprecision(2);
    double a, b;
    double res{0};
    std::cin >> a >> b;
    res = fact(a) / fact(b);
    std::cout << std::fixed << res;

    return 0;
}