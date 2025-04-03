#include <iostream>

// Examples

#include "functions.h"

int main() {
    // 1
    //printf("%u\n", getSumOfDivisorsFrom(8589869056));

    // 2
    //std::string* arr = getStringArrayOfDivisorsFrom(8589869056);
    //std::string* arr2 = getStringArrayOfDivisorsFrom(8128);
    std::string* arr = getStringArrayOfDivisorsFrom(496);
    std::string* arr2 = getStringArrayOfDivisorsFrom(8128);
    printStringArray("arr: ", arr);
    printStringArray("arr2: ",arr2);

    // 3
    std::string* subsetArrs = getSubsetFrom(arr, arr2);
    std::string* unionArrs = getUnionFrom(arr, arr2);
    printStringArray("a n b: ", subsetArrs);
    printStringArray("a U b: ", unionArrs);

    // 4
    std::string* primeUnionString = getUnionOfPrimesFrom(arr, arr2);
    printStringArray("a U b (primes): ", primeUnionString);

    // 5
    printf("\nIs %s perfect?\t%s", "3", isPerfect("3")? "true" : "false" );
    printf("\nIs %s perfect?\t%s", "4", isPerfect("4") ? "true" : "false");
    printf("\nIs %s perfect?\t%s", "14", isPerfect("14") ? "true" : "false");
    printf("\nIs %s perfect?\t%s", "28", isPerfect("28") ? "true" : "false");
    printf("\nIs %s perfect?\t%s", "8128", isPerfect("8128") ? "true" : "false");

    // 6
    //std::string* perfectsInInterval = getAllPerfectsFromTheInterval(0, 500);
    std::string* perfectsInInterval = getAllPerfectsFromTheInterval(20, 8128);
    //std::string* perfectsInInterval = getAllPerfectsFromTheInterval(400, 10000);
    printStringArray("\nAll perfects from start to end are: ", perfectsInInterval);


    // 7 first n perfects
    // 8 save them to string
    // 9 first n with Mersenne
    // 10 (2^(p-1)) * (2^p - 1) Mersenne

    delete[] arr; // proper memory management
    delete[] arr2; // proper memory management
    delete[] subsetArrs; // proper memory management
    delete[] unionArrs; // proper memory management
    delete[] primeUnionString; // proper memory management
    delete[] perfectsInInterval; // proper memory management


























    return 0;
}