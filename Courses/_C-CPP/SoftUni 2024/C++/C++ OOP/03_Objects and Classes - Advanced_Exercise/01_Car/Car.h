//
// Created by User on Сб-6.7.2024 г..
//

#ifndef CAR_H
#define CAR_H


using namespace std;


class Car{
private:
    string m_Brand;
    string m_Model;
    int m_Year;




public:

    Car(string brand, string model, int year) : m_Brand(move(brand)), m_Model(move(model)), m_Year(year) {}

    string GetBrand() const {return m_Brand;}
    string GetModel() const {return m_Model;}
    int GetYear() const {return m_Year; }


};










#endif //SOLUTION_SOFTUNICPP_OOP_CAR_H
