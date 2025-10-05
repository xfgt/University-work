//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>



int main(){
    std::string input{}, digits{}, letters{}, characters{};

    std::getline(std::cin, input);


    for(size_t i = 0; i < input.size(); i++){
        if(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z' ){
            letters += input[i];
        } else if (input[i] >= '0' && input[i] <= '9'){
            digits += input[i];
        } else{
            characters += input[i];
        }
    }

    std::cout << digits << std::endl;
    std::cout << letters << std::endl;
    std::cout << characters << std::endl;


    return 0;
}