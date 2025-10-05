//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>

int main(){

    std::string input{};
    std::getline(std::cin, input);

    // std::string section{};
    // std::stringstream getSection(input);
    //
    // while(std::getline(getSection, section)){
    //     std::stringstream eachWord(section);
    //     std::string word{};
    //
    //
    //     while (std::getline(eachWord, word, ',')){
    //         std::stringstream os(word);
    //         std::string e{};
    //         while(os >> e){
    //             if(e[0] >= 'a' && e[0] <= 'z')
    //                 e[0] -= 32;
    //
    //             std::cout << e;
    //
    //         }
    //         std::cout << ',';
    //     }
    // }


    for(int i = 0; i < input.size()-1; i++){
        if(input[0] >= 'a' && input[0] <= 'z'){
            input[i] -= 32;
            continue;
        }


        if(!(input[i] >= 'a' && input[i] <= 'z' || input[i] >= 'A' && input[i] <= 'Z' )){
            while(input[i] != ' ' && i < input.size())
                ++i;
            if(input[i+1] >= 'a' && input[i+1] <= 'z'){
                input[i+1] -= 32;

            }
        }
    }

    std::cout << input;

    return 0;
}