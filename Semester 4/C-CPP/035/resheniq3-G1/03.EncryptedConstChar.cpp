#include <iostream>

#include <cstring>


int getMid(int*x, const int& sz){
    int i{};

    if(sz % 2 == 0){
        return x[(sz-1)/2];
    } else {
        return x[sz/2];
    }



}

char& change(char& x){
    if(x >= 'a' && x <= 'z'){
        x -= 32;

    } else if(x >= 'A' && x <= 'Z'){
        x += 32;
    }

    return x;
}

void encryptMessage( const char* message, int& sz, int& shift){


    std::string msg = message;
    int razlika{};

    for(int i = 0; i < sz; i++){


        if(msg[i] >= 'A' && msg[i] <= 'Z'){
            msg[i] -= shift;
            if(msg[i] < 'A'){
                razlika = 'A' -  msg[i];
                msg[i] = 'Z' - razlika + 1;
            }


        } else if(msg[i] >= 'a' && msg[i] <= 'z'){
            msg[i] -= shift;
            if(msg[i] < 'a'){
                razlika = 'a' -  msg[i];
                msg[i] = 'z' - razlika + 1;
            }
        }
        else{
            continue;
        }
        change(msg[i]);




    }

    std::cout << msg << std::endl;
}

int main(){

    int a[5] {5, 4, 2, 6, 3};
    int shift = getMid(a,5);

    const char* msg = "ABCD...xyz";
    int length = strlen(msg);

    encryptMessage(msg, length, shift);







    return 0;
}