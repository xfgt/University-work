//
// Created by twister on 8/27/24.
//


#include <iostream>


std::string status(const double& g){
    if(g >= 2.00 && g <= 2.99)       return "Fail";
    else if (g >= 3.00 && g <= 3.49) return "Poor";
    else if (g >= 3.50 && g <= 4.49) return "Good";
    else if (g >= 4.50 && g <= 5.49) return "Very good";
    else if (g >= 5.50 && g <= 6.00) return "Excellent";
    else return "";
}

int main(){

    double grade{};
    std::cin >> grade;


    std::cout << status(grade);


    return 0;
}