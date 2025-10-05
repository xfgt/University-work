//
// Created by twister on 8/31/24.
//


#include <iostream>
#include <sstream>
#include <string>






int main(){

    std::string a{}, b{};
    std::getline(std::cin, a, ' ');
    std::getline(std::cin, b);

    size_t sz{};
    int sum{};

    if(a.size() > b.size())
        sz = a.size();
    else
        sz = b.size();


    for(size_t i = 0; i < sz; i++){

        if(a[i] == '\0')
            sum += b[i];
        else if(b[i] == '\0')
            sum += a[i];
        else
            sum += (a[i]) * (b[i]);

    }


    std::cout << sum;


    return 0;
}