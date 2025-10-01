//
// Created by ADMIN on 28-Aug-25.
//

#ifndef UNTITLED_BIGINTEGER_H
#define UNTITLED_BIGINTEGER_H

#include  <iostream>
#include <cstring>
#include <vector>

// + - * <<


class BigInteger{
    std::string numbers;
public:

    BigInteger();
    BigInteger(std::string &);
    BigInteger(const char *);


    friend int Length(const BigInteger &);
    int operator[](const int)const;


    BigInteger &operator=(const BigInteger &);


    friend BigInteger &operator+=(BigInteger &, const BigInteger &);
    friend BigInteger operator+(const BigInteger &, const BigInteger &);
    friend BigInteger operator-(const BigInteger &, const BigInteger &);
    friend BigInteger &operator-=(BigInteger &, const BigInteger &);


    friend bool operator>(const BigInteger &, const BigInteger &);
    friend bool operator<(const BigInteger &, const BigInteger &);


    friend BigInteger operator*(const BigInteger &, const BigInteger &);

};
#endif //UNTITLED_BIGINTEGER_H
