//
// Created by twister on 9/6/24.
//

#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>


int main(){

    std::vector<int> v;

    std::string x{};
    while((std::cin >> x) && x != "\n"){
            if(std::stoi(x) >= 0)
                v.push_back(std::stoi(x));
    }

    if(v.empty()){
        std::cout << "empty";
        return 0;
    }

    std::reverse(v.begin(),v.end());
    for(const auto& it : v)
        std::cout << it << ' ';

    return 0;
}