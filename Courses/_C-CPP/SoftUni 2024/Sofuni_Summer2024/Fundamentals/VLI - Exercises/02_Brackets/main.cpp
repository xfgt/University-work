//
// Created by twister on 9/7/24.
//

#include <iostream>
#include <sstream>


int getType(char& x) {
    switch (x){
    case '{': case '}': return 3;
    case '[': case ']': return 2;
    case '(': case ')': return 1;
    }
    return 0;
}

bool isClosing(char& x){
    switch (x){
    case '}':
    case ']':
    case ')':
        return true;

        default: return false;
    }
}

bool checkCorrect(std::string& input){

    char lastSymbol{};
    for(int i = 0; i < input.size(); i++){
        if(!lastSymbol){
            lastSymbol = input[i];
            continue;
        }

        int last = getType(lastSymbol);
        int curr = getType(input[i]);

        if(isClosing(input[i])){
            if(last > curr)
                return false;
        }

        lastSymbol = input[i];
    }
    return true;
}


int main(){
    // type hierarchy
    // {} 3
    // [] 2
    // () 1

    std::string input{};
    std::getline(std::cin, input);

    if(checkCorrect(input))
        std::cout << "valid";
    else
        std::cout << "invalid";


    return 0;
}