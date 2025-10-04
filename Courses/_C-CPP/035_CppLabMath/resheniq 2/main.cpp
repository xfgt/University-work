#include <iostream>

int main() {

    char* inp = new char[100];
    std::cin.get(inp, 99);

    const int f = 20;
    const int b = 5;

    char** arrOfWords = new char*[f];
    for(int i = 0; i < f; i++){
        arrOfWords[i] = new char[b];
        arrOfWords[i][b-1] = '\0';
        for(int j = 0; j < b-1; j++){
            if(inp[0] != ' '){
                arrOfWords[i][j] = inp[0];
            }
            else{
                j--;
            }
            inp++;

        }

    }


    for(int i = 0; i < f; i++){

            std::cout << arrOfWords[i] << ' ';

    }



    for(int i = 0 ; i < f; i++){
        delete arrOfWords[i];
    }
    delete[] arrOfWords;

    return 0;
}
