//
// Created by twister on 8/31/24.
//


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

int main(){

    std::string word{};
    std::getline(std::cin, word);

    while(word != "end"){
        std::string reverse = word;
        std::reverse(reverse.begin(), reverse.end());

        std::cout << word << " = " << reverse << std::endl;

        std::getline(std::cin, word);
    }

    return 0;
}