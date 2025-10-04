#include <iostream>
#include <cstring>

bool isPrime(int n){
    if(n <= 1)
        return false;

    for(int i = 2; i < n / 2; i++)
        if(n % i == 0)
            return false;


    return true;


}



int getLowestPrime(const int& min, const int max){

    for(int i = min; i < max; i++){
        if(isPrime(i))
            return i;
    }
    return 0;
}



void solve(std::string& sample, size_t& sz, int& shift){
    for(int i = 0; i < sz; i++){
        if(sample[i] >= 'A' && sample[i] <= 'Z' || sample[i] >= 'a' && sample[i] <= 'z')
            sample[i] = sample[i] + shift;
        std::cout << sample[i];
    }


}

int main(){


    //interval -> lowest prime -> move positions
    // if move positions > 26 => movePostitions = (movePositions % 26);

    int shift = getLowestPrime(30, 40);
    
    if(shift > 26)
        shift = shift % 26;


    std::string txt = "This is one test string!";
    auto txtSize = txt.size();

    solve(txt, txtSize, shift);



    return 0;
}