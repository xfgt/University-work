//
// Created by User on Чт-4.7.2024 г..
//


#include <iostream>
#include <cmath>
#include <iomanip>

class Point{

private:
    float m_Xa;
    float m_Ya;
    float m_Xb;
    float m_Yb;

public:
    Point(int xa =0.0f, int ya =0.0f, int xb =0.0f, int yb =0.0f) : m_Xa(std::move(xa)), m_Ya(std::move(ya)), m_Xb(std::move(xb)), m_Yb(std::move(yb)){}


    float calcDistance(){
        return sqrt((pow(abs(m_Xb - m_Xa), 2)) + (pow(abs(m_Yb - m_Ya), 2)));

    }



};

int main(){

    float f_x, s_x, f_y, s_y;

    std::cin >> f_x >> s_x >> f_y >> s_y;

    Point p(f_x,s_x,f_y,s_y);

    std::cout.precision(3);
    std::cout << std::fixed << p.calcDistance() << std::endl;




    return 0;
}