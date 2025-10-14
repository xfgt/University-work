//
// Created by twister on 8/27/24.
//


#include <iostream>

std::string checkNumber(int& n) {
    if(n == 0)
        return "zero.";
    else if(n < 0)
        return "negative.";
    else if(n > 0)
        return "positive.";
    else
        return "";
}
int main(){

    int n{};
    std::cin >> n;


    std::cout << "The number " << n << " is " << checkNumber(n);



    return 0;
}