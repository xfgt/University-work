//
// Created by ADMIN on 28-Aug-25.
//

#ifndef UNTITLED_MONEY_H
#define UNTITLED_MONEY_H
#include <iostream>

class Money {

    friend std::ostream& operator << (std::ostream& out, const Money& obj);
    friend std::istream& operator >> (std::istream& in, Money& obj);

private:
    int leva;
    float stotinki;

public:
    explicit Money(int=0, float=0);
    void setLeva(int);
    void setStotinki(float);

    int getLeva() const;
    float getStotinki() const;
    bool operator < (const Money& obj) const ;
    Money operator - (const Money& obj1);

};


#endif //UNTITLED_MONEY_H