//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>



int main(){

    std::string word{};
    while(std::cin >> word){
        for(size_t i = 0; i < word.size(); i++){
            std::cout << word;
        }
    }

    return 0;
}