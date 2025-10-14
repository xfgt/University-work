//
// Created by twister on 8/27/24.
//


#include <cmath>
#include <iostream>

std::string getDigitName(char x ='0'){
    switch (x){
    case '0': return "zero";
    case '1': return "one";
    case '2': return "two";
    case '3': return "three";
    case '4': return "four";
    case '5': return "five";
    case '6': return "six";
    case '7': return "seven";
    case '8': return "eight";
    case '9': return "nine";
        default:
            return "";
    }
}


std::string processNumber(std::string x, size_t sz){
    if(x[0] == '-')
        return "";
    if(sz > 4)
        return "";

    std::string output{};
    int type{};
    bool caseTenHit = false;

    for (int i = 0; i < sz; i++){
        type = std::pow(10,sz-i-1);

        switch (type){
        case 1000:
            if(x[i] != '0')
                output += getDigitName(x[i]) + " thousand ";
            break;
        case 100:
            if(x[i] != '0')
                output += getDigitName(x[i]) + " hundred ";
            break;

        case 10:
            caseTenHit = true;
            switch (x[i]){
            case '1':
                switch (x[i+1]){ // teen
                case '0':
                    output += "ten";
                        break;
                case '1':
                    output += "eleven";
                        break;
                case '2':
                    output += "twelve";
                        break;
                // teen
                case '3':
                    output += "thir";
                        break;
                case '5':
                    output += "fif";
                        break;
                case '8':
                    output += "eigh";
                    break;

                case '4':
                case '6':
                case '7':
                case '9':
                    output += getDigitName(x[i+1]);
                        break;
                default:
                    break;
                }
                if(x[i+1] != '0' && x[i+1] != '1' && x[i+1] != '2')
                    output += "teen ";
                break;


            case '2':
                output += "twen";
                    break;
            case '3':
                output += "thir";
                    break;
            case '5':
                output += "fif";
                    break;
            case '8':
                output += "eigh";
                break;

            case '4':
            case '6':
            case '7':
            case '9':
                output += getDigitName(x[i]);
                    break;
            default:
                break;
            }
            if(x[i] != '0' && x[i] != '1')
                output += "ty ";
            break;

        case 1:
            if(caseTenHit && x[i-1] != '1' && x[i] != '0')
                output += getDigitName(x[i]);
            else if(sz == 1)
                output += getDigitName(x[i]);

            break;

        default:
            break;
        }

    }

    return output;
}
void test(std::string& number){
    for(int i = 0; i <= 9999; i++){
        number = std::to_string(i);
    //    std::getline(std::cin, number);
        std::cout << i << ":\t" << processNumber(number, number.size()) << std::endl;
    }
}
int main(){

    std::string number{};

    test(number);

    // std::getline(std::cin, number);
    // std::cout << processNumber(number, number.size()) << std::endl;

    return 0;
}