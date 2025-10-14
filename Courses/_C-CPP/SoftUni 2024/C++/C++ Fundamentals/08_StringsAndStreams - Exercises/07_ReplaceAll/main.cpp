//
// Created by twister on 8/31/24.
//



#include <iostream>


int main(){


    std::string input{}, find{}, replace{}, word{}, result{}, copy{};

    std::getline(std::cin, input);
    std::cin >> find >> replace;

    copy = input;


    std::string::size_type position;

    position = copy.find(find);
    while (std::string::npos != position){
        copy.replace(position, find.size(), replace);
        position = copy.find(find);
    }

    std::cout << copy;




    return 0;
}