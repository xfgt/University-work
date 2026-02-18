//
// Created by ADMIN on 07-Oct-25.
//


#include <iostream>

#include <cstdint>
void toBinary(uint32_t x)
{
    for (int i = 7; i >= 0; --i) {

        putchar( (x >> i) & 1u ? '1' : '0' );

        if (i % 4 == 0 && i != 0) putchar(' ');
    }
}

void swap(uint32_t& a, uint32_t& b) {

    if (a==b) return;
    // 5 ^ 6 = 3;
    a ^= b; // 5 = 5 ^ 6 => 3 (5 is now 3)
    b ^= a; // 6 = 6 ^ 3 => 5 (6 is now 5)
    a ^= b; // 3 = 3 ^ 5 => 6 (5 is now 6)

}




int main() {



    uint32_t a = 5;
    uint32_t b = 6;

    swap(a,b);

    std::cout << a << '\n' << b << std::endl;
    toBinary(a);
    std::cout << '\n';
    toBinary(b);


    return 0;
}