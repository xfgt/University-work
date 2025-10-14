//
// Created by twister on 7/28/24.
//

#ifndef TRYPARSE_H
#define TRYPARSE_H

bool tryParse(const std::string& x_str, int& x_digit){
    try{
        int hold = std::stoi(x_str);
        x_digit = hold;
        return true;
    } catch (...){
        return false;
    }
}


#endif //TRYPARSE_H
