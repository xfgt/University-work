


#pragma once


#include <iostream>
#include <string>
using namespace std;

class Building{

    friend ostream& operator << (ostream& out, const Building& obj);
    friend istream& operator >> (istream& in, Building& obj);

    // b + 1 "increment built floors"
    // 1 + b "increment built entrances"
    friend Building& operator +( Building& lhs, int rhs);
    friend Building& operator +=( Building& lhs, int rhs);


    friend Building& operator +(int lhs,  Building& rhs);
    friend Building& operator +=(int lhs,  Building& rhs);

private:
    string m_address;
    int m_plannedFloors;
    int m_plannedEntrances;
    int m_builtFloors;
    int m_builtEntrances;


public:
    Building(string address="", int pfl=0, int pent=0, int bfl=0, int bent=0);
    Building (const Building& obj);

    Building& operator=(const Building& obj);

    // b + 1 "increment built floors"
    // 1 + b "increment built entrances"










    // getters
    string getBuilding_address() const ;
    int getBuilding_plannedFloors() const;
    int getBuilding_plannedEntrances() const;
    int getBuilding_builtFloors() const;
    int getBuilding_builtEntrances() const;

    // setters
    void setAddress(string str);
    void setPlanFloors(int pf);
    void setPlanEntr(int pe);
    void setBuiltFloors(int bf);
    void setBuiltEntr(int be);
};