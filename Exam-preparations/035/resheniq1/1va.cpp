#include <iostream>
#include <string>
#include <cstring>


void encryptText(char* txt, int& sz){

    for(int i = 0; i < sz; i++){

        if(txt[i] == 'Z' || txt[i] == 'z'){
            txt[i] = ' ';
        }
        else if(txt[i] == ' ') {
            if (txt[i + 1] >= 'A' && txt[i + 1] <= 'Z') {
                txt[i] = 'A';
            }
            if (txt[i + 1] >= 'a' && txt[i + 1] <= 'z') {
                txt[i] = 'a';
            }
        } else {
            txt[i] = txt[i] + 1;
        }

    }

}

void decryptText(char* txt, int& sz){
    for(int i = 0; i < sz; i++){

        if(txt[i] == ' '){
            if(txt[i+1] == NULL){
                if(txt[i-1] >= 'A' && txt[i-1] <= 'Z')
                    txt[i] = 'Z';
                if(txt[i-1] >= 'a' && txt[i-1] <= 'z')
                    txt[i] = 'z';
            }

            if(txt[i + 1] >= 'A' && txt[i+1] <= 'Z')
                txt[i] = 'Z';
            if(txt[i + 1] >= 'a' && txt[i+1] <= 'z')
                txt[i] = 'z';
        }
        else if(txt[i] == 'A') {
                txt[i] = ' ';
        } else if(txt[i] == 'a'){
            txt[i] = ' ';
        }
        else {
            txt[i] = txt[i] - 1;
        }


    }
}

int main(){


    char* text = new char[50];
    std::cin.get(text, 49);
    int size = std::strlen(text);


    encryptText(text, size);
    std::cout << text << std::endl;

    decryptText(text, size);
    std::cout << text << std::endl;





    delete[] text;

    return 0;
}