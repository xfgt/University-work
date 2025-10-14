//
// Created by User on Чт-4.7.2024 г..
//


#include <iostream>
#include <vector>
#include <cstring>
#include <limits>
#include <string>




//different algorithm
void getShiftedSentence(std::vector<char*>& w, int& x){

    for(int h = 0; h <= x; h++){
        int dist = x;
        for(int i = 0; dist < w.size(); i++, dist++){
            char* temp = new char [std::strlen(w[i])+1];
            memset(temp, '\0', std::strlen(w[i])+1);
            std::strcpy(temp, w[i]);


            memset(w[i], '\0', std::strlen(w[dist])+1);
            std::strcpy(w[i], w[dist]);
            memset(w[dist], '\0', std::strlen(temp)+1);
            std::strcpy(w[dist], temp);

            delete[] temp;
        }
    }



}
int main(){

    char text[100];
    memset(text, '\0', 100);

    char test = std::cin.get();
    while(!(test >= 'a' && test <= 'z' || test >= 'A' && test <= 'Z')){
        std::cin.clear();
        std::cin >> test;
    }
    std::cin.putback(test);
    std::cin.get(text, 99);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int shift{};
    std::cin >> shift;
    while(shift == 0)
        std::cin >> shift;

    std::vector<char*> words;
    char* word = nullptr;
    int i{};

    while(i < 100){
        if(text[i] == '\0') break;

        int g(-1);
        word = new char[30];
        memset(word, '\0', 30);

        while(g < 30 && (text[i] != ' ' && text[i] != '\0'))
            word[++g] = text[i++];
        i++;

        if(g >= 0)      words.push_back(word);
        else            delete[] word;
    }

    if(shift >= 0 && shift < words.size()) getShiftedSentence(words, shift);


    for(int i = 0; i < words.size(); i++){
        if(i+1 == words.size())     std::cout << words[i];
        else                        std::cout << words[i] << std::endl;
    }



//  Memory management
    for(auto& it : words){
        delete it;
        it = nullptr;
    }
    words.clear();
    word = nullptr;

    return 0;
}