//
// Created by ADMIN on 28-Aug-25.
//

#include "Money.h"

#include <cmath>

Money::Money(int _leva, float _stotinki) : leva(_leva), stotinki(_stotinki){}

void Money::setLeva(int amt) {
    leva = amt;
}
void Money::setStotinki(float famt) {
    stotinki = famt;
}
int Money::getLeva() const {
    return leva;
}
float Money::getStotinki() const {
    return stotinki;
}

bool Money::operator<(const Money &obj) const {
    return (this->getLeva() < obj.getLeva()) || (this->getStotinki() < obj.getStotinki());
}
Money Money::operator-(const Money& obj1) {
    Money temp;

    float a = this->getLeva() + 0.01 * this->getStotinki();
    float b = obj1.getLeva() + 0.01 * obj1.getStotinki();

    // sign char member variable
    a-=b;
    int x{};

    if (a < 0) {
        std::floor(a);
        a = -a;
    }

    else
        std::ceil(a);

    int y = std::abs(a*100);

    temp.setLeva(x);
    temp.setStotinki(y);

    return temp;


}




std::ostream& operator << (std::ostream& out, const Money& obj) {
    out << obj.leva << " lv. " << obj.stotinki << " st.";
    return out;
}
std::istream& operator >> (std::istream& in, Money& obj) {
    int l{}, s{};
    in >> l >> s;
    obj.setLeva(l);
    obj.setStotinki(s);
    return in;
}