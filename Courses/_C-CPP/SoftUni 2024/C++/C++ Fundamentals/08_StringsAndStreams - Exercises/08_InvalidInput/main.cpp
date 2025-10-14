//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>

int main(){

    std::string input{}, hold{};
    std::getline(std::cin, input);

    std::stringstream ss(input);

    int sum{};
    std::ostringstream oss;
    while(ss >> hold){
        int x{};
        try{
            x = std::stoi(hold);
            sum += x;
        } catch (std::invalid_argument&){
            oss << hold << ' ';
        }
    }

    std::cout << sum << std::endl;
    std::cout << oss.str() << std::endl;
    return 0;
}