//
// Created by twister on 8/31/24.
//


#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>


bool check(std::string& x,  size_t sz) {
    if(x[0] == ' '){
        x.erase(std::remove_if(x.begin(), x.end(), ::isspace), x.end());
        sz = x.size();
    }

    if(sz < 3 || sz > 16)
        return false;

    size_t i = 0;
    while(i != sz){

        if(x[i] == '\0'){
            i++;
            continue;
        }

        if (!(x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z'))
            if (!(x[i] >= '0' && x[i] <= '9'))
                if(!(x[i] == '-' || x[i] == '_'))
                    return false;
        i++;
    }
    return true;
}

int main(){

    std::string input{}, hold{};
    std::getline(std::cin, input);
    std::stringstream ss(input);


    while(std::getline(ss, hold, ',')){

        if(check(hold, hold.size())){

            std::cout << hold << std::endl;
        }


    }

    return 0;
}