#include <iostream>



void solve(char* crit, const int& sz, std::string& sample){

    int count{};
    int current{};


    for(int i = 0; i < sample.size(); i++){
        if(sample[i] != ' '){

            for(int l = 0; l < sz; l++){
                if(sample[i] == crit[l])
                    current++;
            }


        }

        if(current > count){
            count = current;
            current = 0;

        }


    }



    std::cout << count << std::endl;
}

int main(){

    char symbols[4] { 'e', 't', 'i', 's' };
    std::string str = "This is one test string!";

    solve(symbols, 4, str);



    return 0;
}