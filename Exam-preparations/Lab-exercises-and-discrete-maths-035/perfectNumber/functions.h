//
// Created by MRSLAVE on 03-Apr-25.
//

#pragma once
#include <iostream>
#include <stdlib.h>
#include <sstream>
typedef unsigned long long ull;



// helper funcitons
ull getSumOfDivisorsFrom(ull);
bool isPrime(std::string);
bool isPerfect(std::string);
size_t getStringArraySize(std::string*);
void printStringArray(const char*, std::string*);



// make a string array from all divisors
// exercises 2, 3, 4, 5, 6
std::string* getStringArrayOfDivisorsFrom(ull);
std::string* getSubsetFrom(std::string*, std::string*);
std::string* getUnionFrom(std::string*, std::string*);
std::string* getUnionOfPrimesFrom(std::string*, std::string*);
std::string* getAllPerfectsFromTheInterval(ull , ull);

// exercises 7, 8, 9, 10
void printFirstNPerfectNumbers(int);




