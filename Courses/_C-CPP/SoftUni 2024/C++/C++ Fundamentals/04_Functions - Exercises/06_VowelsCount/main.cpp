//
// Created by twister on 8/27/24.
//


#include <iostream>



void solution(const std::string& x, const size_t& sz){
    int counter{};
    for(size_t i = 0; i < sz; i++){
        switch (x[i]){
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            counter++;
            break;
            default:
                break;
        }
    }

    std::cout << counter;
}

int main(){

    std::string input{};
    std::getline(std::cin, input);


    solution(input, input.size());


    return 0;
}