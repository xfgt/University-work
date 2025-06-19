#include <iostream>
#include <cstring>


void checkPrint(const char*& x, const int& xsz, const char*& y, const int& ysz){

    std::string meets{""};

    int count{};
    int spaces{};
    bool isSet = false;

    for(int i = 0; i < ysz; i++){
        if(y[i] == ' '){
            spaces++;
            continue;
        }
        for(int j = 0; j < xsz; j++){
            if(y[i] == x[j]){
                count++;
                size_t found = meets.find(y[i]);
                if(found == meets.npos){
                    meets += y[i];
                    meets += ", ";
                }
                if(count+spaces == xsz){
                    isSet = true;
                    break;
                }
                break;
            }

        }
    }

    std::cout << meets << std::endl;

    if(isSet)
        std::cout << "We have a set!" << std::endl;
    else
        std::cout << "not a set." << std::endl;

}


int main(){

    const char* A = "The way is here boys!";
    int sizeA = strlen(A);

    const char* B = "The way is here boys!";
    int sizeB = strlen(B);


    checkPrint(A, sizeA, B, sizeB);





    return 0;
}