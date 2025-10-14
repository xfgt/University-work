//
// Created by twister on 9/7/24.
//

#include <algorithm>
#include <iostream>
#include <list>

#include <sstream>


int main(){

    std::list<std::pair<int, char>> A, B, Merg;


    std::string input{}, x{};
    std::getline(std::cin, input);
    std::stringstream trim(input);

    while(trim >> x)
        A.emplace_back(std::make_pair(std::stoi(x), 'A'));
    std::cin.clear();

    std::getline(std::cin, input);
    std::stringstream trimT(input);

    while(trimT >> x)
        B.emplace_back(std::make_pair(std::stoi(x), 'B'));
    std::cin.clear();


    Merg = A;
    Merg.merge(B);
    Merg.sort();
    std::reverse(Merg.begin(), Merg.end());





    for(auto it = --Merg.end(); it != --Merg.begin(); --it)
        std::cout << it->second;


    std::cout << std::endl;
    for(const auto& it : Merg)
        std::cout << it.first << ' ';






    return 0;
}