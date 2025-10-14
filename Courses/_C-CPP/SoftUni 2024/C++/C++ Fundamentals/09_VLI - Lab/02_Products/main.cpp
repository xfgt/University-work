//
// Created by twister on 9/6/24.
//

#include <iostream>
#include <set>



int main(){

    std::set<std::string> mySet{};

    int N{};
    std::cin >> N;

    std::string element{};
    for(int i = 0; i < N; i++){
        std::cin >> element;

        mySet.insert(element);


    }

    int p{};
    for(const auto& it : mySet)
        std::cout << ++p << '.' << it << std::endl;
    return 0;
}