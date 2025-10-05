//
// Created by twister on 8/27/24.
//



#include <iostream>

int gcd(int a, int b)
{
    // Find Minimum of a and b
    int result = std::min(a, b);
    while (result > 0) {
        if (a % result == 0 && b % result == 0) {
            break;
        }
        result--;
    }

    // Return gcd of a and b
    return result;
}

int main(){

    int a{}, b{};
    std::cin >> a >> b;

    std::cout << gcd(a, b);



    return 0;
}