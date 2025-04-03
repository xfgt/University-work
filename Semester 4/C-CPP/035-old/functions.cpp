//
// Created by MRSLAVE on 03-Apr-25.
//
#include "functions.h"
typedef unsigned long long ull;


ull getSumOfDivisorsFrom(ull n){
    ull sum{};
    for(ull i = 1; i <= n/2; i++) {
        if(n % i == 0)
            sum += i;
    }
    return sum;
}

bool isPrime(std::string str_N){

    ull n = strtoull(str_N.c_str(), nullptr, 0);
    if(n<=1) return false;
    for(ull i = 2; i*i <= n; i++){
        if(n % i == 0)
            return false;
    }
    return true;
}

bool isPerfect(std::string str_N){

    ull n = strtoull(str_N.c_str(), nullptr, 0);
    ull sum = 1;

    for (ull i = 2; i * i <= n; i++)
        if (n % i == 0)
            if (i * i != n)
                sum = sum + i + n / i;
            else
                sum = sum + i;

    if (sum == n && n != 1)
        return true;
    return false;
}


size_t getStringArraySize(std::string* arr) {
    size_t count{};
    while(!arr->empty()) {
        count++;
        arr++;
    }
    return count;
}

void printStringArray(const char* text, std::string* arr) {
    std::cout << text;
    std::cout << '[';
    while(!arr->empty()) {
        if((arr+1)->empty())
            std::cout << *arr;
        else
            std::cout << *arr << ", ";
        arr++;
    }
    std::cout << "]\n";
}

// make a string array from all divisors
std::string* getStringArrayOfDivisorsFrom(ull n) {

    std::string* divisors = new std::string[200]{};
    int p{};
    for(ull i = 1; i <= n/2; i++) {
        if(n % i == 0) {
            std::stringstream os;
            os << i;
            divisors[p++] = os.str();
        }
    }

    size_t arrSize = getStringArraySize(divisors);
    if(arrSize <= 200) {
        std::string* temp = new std::string[arrSize];
        temp = divisors;
        return temp;
    }

    return divisors;
}




std::string* getSubsetFrom(std::string* a, std::string* b) {

    //get the smaller
    // iterate through it and check each a[i] == b[i-n]
    std::string* smaller = nullptr;
    std::string* larger = nullptr;
    if(getStringArraySize(a) < getStringArraySize(b)){
        smaller = a;
        larger = b;
    } else {
        smaller = b;
        larger = a;
    }




    std::string* subsetArray = new std::string[getStringArraySize(smaller)];
    int ssA_index{};

    for(int i = 0; i < getStringArraySize(smaller); i++) {
        std::string hold = smaller[i];

        for(int j = i; j < getStringArraySize(larger); j++) {
            if(hold == larger[j]) {
                subsetArray[ssA_index++] = larger[j];
                break;
            }
        }

    }



    return subsetArray;

}

std::string* getUnionFrom(std::string* a, std::string* b) {

    std::string* smaller = nullptr;
    std::string* larger = nullptr;
    if(getStringArraySize(a) < getStringArraySize(b)){
        smaller = a;
        larger = b;
    } else {
        smaller = b;
        larger = a;
    }

    size_t size = getStringArraySize(smaller) + getStringArraySize(larger);
    std::string* unionString = new std::string[size];
    int uS_index{};
    int i = 0;
    for(; i < getStringArraySize(smaller); i++) {

        if(smaller[i] == larger[i]) {
            unionString[uS_index++] = smaller[i];
        } else if(smaller[i] < larger[i]) {
            unionString[uS_index++] = smaller[i];
            unionString[uS_index++] = larger[i];
        } else if(smaller[i] > larger[i]) {
            unionString[uS_index++] = larger[i];
            unionString[uS_index++] = smaller[i];
        }
    }

    while(uS_index != size) {
        unionString[uS_index++] = larger[i++];
    }


    return unionString;
}


std::string* getUnionOfPrimesFrom(std::string* a, std::string* b) {

    std::string* unionString = getUnionFrom(a, b);
    std::string* primeUnionString = new std::string[getStringArraySize(unionString)];
    int pus_index{};
    for(int i = 0; i < getStringArraySize(unionString); i++) {
        if(isPrime(unionString[i])) {
            primeUnionString[pus_index++] = unionString[i];
        }
    }



    return primeUnionString;

}



std::string* getAllPerfectsFromTheInterval(ull start, ull end) {

    std::string* interval = new std::string[end];
    ull i_index{};
    std::string* perfect_interval = new std::string[end];
    ull pi_index{};

    for(ull i = start; i <= end; i++) {
        interval[i_index++] = std::to_string(i);
    }


    for(int i = 0; i < i_index; i++) {
        if(isPerfect(interval[i])) {
            perfect_interval[pi_index++] = interval[i];
        }
    }

    delete[] interval;

    return perfect_interval;
}



// 7, 8, 9, 10
void printFirstNPerfectNumbers(int n) {

    if(n > 8) return;

}





