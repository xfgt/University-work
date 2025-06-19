#include <iostream>

bool isPrime(int x){
    if(x <= 1)
        return false;
    for(int i = 2 ; i <= x/2; i++){
        if(x % i == 0)
            return false;
    }
    return true;
}

void fill(char* cross, char* univ, int* bitmask, const int& size, int& sum){
    int c{};
    for(int i = 0; i < size; i++){
        if(bitmask[i] == 1){
            if(univ[i] >= 'A' && univ[i] <= 'Z'){
                cross[c] = univ[i];
                sum += univ[i];
                c++;

            }
        }
    }

}

void print(char* letters, const int& size){
    std::cout << '[';
    while(*letters != NULL){
        std::cout << *letters;
        letters++;
    }
    std::cout << ']' << std::endl;

}


int main(){



    char univ[10] { 'f', 'W', 'v', 'b', 'Z', 'N', 'a', 'x', 'c', 'o' };
    int A[10]{ 0, 1, 0, 0, 1, 0, 1, 0, 1, 0 };

    int sum{};
    char cross[10];
    fill(cross, univ, A, 10, sum);

    //print(univ, 10);


    if(isPrime(sum))
        std::cout << std::boolalpha << isPrime(sum) << ":\t " << sum << std::endl;
    else
        std::cout << std::boolalpha << isPrime(sum) << ":\t " << sum << std::endl;

    return 0;
}