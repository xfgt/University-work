//
// Created by ADMIN on 28-Aug-25.
//

#include "BigInteger.h"


BigInteger::BigInteger(std::string & s){
    numbers = "";
    int n = s.size();
    for (int i = n - 1; i >= 0;i--){
        if(!isdigit(s[i]))
            throw("ERROR");
        numbers.push_back(s[i] - '0');
    }
}

BigInteger::BigInteger(const char *s){
    numbers = "";
    for (int i = strlen(s) - 1; i >= 0;i--)
    {
        if(!isdigit(s[i]))
            throw("ERROR");
        numbers.push_back(s[i] - '0');
    }
}


int Length(const BigInteger & a){
    return a.numbers.size();
}

int BigInteger::operator[](const int index)const{
    return numbers[index];
}

bool operator<(const BigInteger&a,const BigInteger&b){
    int n = Length(a), m = Length(b);
    if(n != m)
        return n < m;
    while(n--)
        if(a.numbers[n] != b.numbers[n])
            return a.numbers[n] < b.numbers[n];
    return false;
}
bool operator>(const BigInteger&a,const BigInteger&b){
    return b < a;
}


BigInteger &BigInteger::operator=(const BigInteger &a){
    numbers = a.numbers;
    return *this;
}

BigInteger &operator+=(BigInteger &a,const BigInteger& b){
    int t = 0, s, i;
    int n = Length(a), m = Length(b);
    if(m > n)
        a.numbers.append(m - n, 0);
    n = Length(a);
    for (i = 0; i < n;i++){
        if(i < m)
            s = (a.numbers[i] + b.numbers[i]) + t;
        else
            s = a.numbers[i] + t;
        t = s / 10;
        a.numbers[i] = (s % 10);
    }
    if(t)
        a.numbers.push_back(t);
    return a;
}
BigInteger operator+(const BigInteger &lhs, const BigInteger &rhs){
    BigInteger temp;
    temp = lhs;
    temp += rhs;
    return temp;
}

BigInteger &operator-=(BigInteger&a,const BigInteger &b){
    
    int n = Length(a), m = Length(b);
    int i, t = 0, s;
    for (i = 0; i < n;i++){
        if(i < m)
            s = a.numbers[i] - b.numbers[i]+ t;
        else
            s = a.numbers[i]+ t;
        if(s < 0)
            s += 10,
            t = -1;
        else
            t = 0;
        a.numbers[i] = s;
    }
    while(n > 1 && a.numbers[n - 1] == 0)
        a.numbers.pop_back(),
        n--;
    return a;
}
BigInteger operator-(const BigInteger& lhs,const BigInteger&rhs){
    BigInteger temp;
    temp = lhs;
    temp -= rhs;
    return temp;
}

BigInteger &operator*=(BigInteger &lhs, const BigInteger &rhs)
{
    
    int n = Length(lhs), m = Length(rhs);
    std::vector<int> v(n + m, 0);
    for (int i = 0; i < n;i++)
        for (int j = 0; j < m;j++){
            v[i + j] += (lhs.numbers[i] ) * (rhs.numbers[j]);
        }
    n += m;
    lhs.numbers.resize(v.size());
    for (int s, i = 0, t = 0; i < n; i++)
    {
        s = t + v[i];
        v[i] = s % 10;
        t = s / 10;
        lhs.numbers[i] = v[i] ;
    }
    for (int i = n - 1; i >= 1 && !v[i];i--)
            lhs.numbers.pop_back();
    return lhs;
}
BigInteger operator*(const BigInteger&a,const BigInteger&b){
    BigInteger temp;
    temp = a;
    temp *= b;
    return temp;
}

std::ostream &operator<<(std::ostream &out,const BigInteger &a){
    for (int i = Length(a) - 1; i >= 0;i--)
        std::cout << (short)a.numbers[i];
    return std::cout;
}

