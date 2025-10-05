//
// Created by twister on 8/27/24.
//


#include <iostream>





bool isBad(const std::string& x, const size_t& sz){

    int counterDigits{};
    bool error = false;

    if(sz < 6 || sz > 10){
        std::cout << "Password must be between 6 and 10 characters" << std::endl;
        error = true;
    }

    bool hasDigit = false;

    for(size_t i = 0; i < sz; i++){
        if (x[i] >= '0' && x[i] <= '9'){
            hasDigit = true;
            counterDigits++;
        }

        if(!(x[i] >= 'a' && x[i] <= 'z' || x[i] >= 'A' && x[i] <= 'Z' || x[i] >= '0' && x[i] <= '9')){
            std::cout << "Password must consist only of letters and digits" << std::endl;
            error = true;
            break;
        }
    }

    if(counterDigits < 2){
        std::cout << "Password must have at least 2 digits" << std::endl;
        error = true;
    }



    return error;
}



int main(){

    std::string pwd{};
    std::getline(std::cin, pwd);

    if(!(isBad(pwd, pwd.size()))){
        std::cout << "Password is valid";
    }

    return 0;
}