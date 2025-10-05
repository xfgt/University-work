//
// Created by twister on 8/27/24.
//


#include <iostream>

void solution(const std::string& x, size_t sz){




    int evenSum{}, oddSum{};

    for(int i = 0; i < sz; i++){
        if(!(x[i] >= '0' && x[i] <= '9'))
            continue;

        if((x[i]-'0') % 2 == 0){
            evenSum += x[i] - '0';
        } else{
            oddSum += x[i] - '0';
        }
    }

    std::cout << evenSum * oddSum;
}


int main(){

    std::string number{};
    std::getline(std::cin, number);

    solution(number, number.size());



    return 0;
}