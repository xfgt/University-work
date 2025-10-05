//
// Created by twister on 8/27/24.
//



#include <iostream>



long fact(int n){
    if(n <= 1)
         return 1;

    long fact = 1;
    while(n != 1){
        fact *= n;
        --n;
    }
    return fact;
}

bool isStrong(const std::string& x, const size_t sz){


    int result{}, m{1};
    for(int i = 0; i < sz-1; i++)
        m *= 10;

    for(int i = 0; i < sz; i++){
        result += (x[i]-'0') * m;
        m /= 10;
    }

    // RESULT IS KEPT


    int check{};


    for(int i = 0; i < sz; i++){
        check += fact(x[i]-'0');
    }

    return check == result;


}


int main(){

    std::string num{};
    std::getline(std::cin, num);

    // size -> type -> distinguish each num

    if(isStrong(num, num.size()))
        std::cout << "yes";
    else
        std::cout << "no";




    return 0;
}