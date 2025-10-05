//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <strstream>
#include <cstring>


int main(){

    char a[100]{}, b[100]{};

    std::cin.getline(a, 100);
    std::cin.getline(b, 100);
    std::cout << std::strstr(a, b);

    for(size_t i = 0; a[i] != '\0'; i++){
        char& current = a[i];
        for(size_t j = 0; b[j] != '\0'; j++){
            char& second = b[j];
            if(current == second){
               second = ' ';
            }
        }
    }

    //
    // for(int i = 0; b[i] != '\0'; i++){
    //     if(b[i] != ' ')
    //         std::cout << b[i];
    // }

    std::cout << std::strstr(a, b);



    return 0;
}
