//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>


bool iscorrect(const std::string& x, const size_t sz){


    int openings{}, closings{};

    for(size_t i = 0; i < sz; i++){
        if(x[i] == '(')
            openings++;

        if(x[i] == ')')
            closings++;
    }

    if(openings == closings)
        return true;
    return false;
}
int main(){

    std::string input{};
    std::getline(std::cin, input);

    (iscorrect(input, input.size())) ? std::cout << "correct" : std::cout << "incorrect";
    return 0;
}