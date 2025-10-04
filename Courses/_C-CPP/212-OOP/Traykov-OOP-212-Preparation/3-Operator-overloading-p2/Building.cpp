#include "Building.h"


Building::Building(string adr, int pfl, int pent, int bfl, int bent)
    :
    m_address(adr),
    m_plannedFloors(pfl),
    m_plannedEntrances(pent),
    m_builtFloors(bfl),
    m_builtEntrances(bent) {}

string Building::getBuilding_address() const { return m_address; }
int Building::getBuilding_plannedFloors() const  { return m_plannedFloors; }
int Building::getBuilding_plannedEntrances() const  { return m_plannedEntrances; }
int Building::getBuilding_builtFloors() const { return m_builtFloors; }
int Building::getBuilding_builtEntrances() const { return m_builtEntrances; }


void Building::setAddress(string str) {
    this->m_address = str;
}
void Building::setPlanFloors(int pf) {
    this->m_plannedFloors = pf;
}
void Building::setPlanEntr(int pe) {
    this->m_plannedEntrances = pe;
}
void Building::setBuiltFloors(int bf) {
    this->m_builtFloors = bf;
}
void Building::setBuiltEntr(int be) {
    this->m_builtEntrances = be;
}

Building::Building(const Building& obj) {
    m_address = obj.m_address;
    m_plannedFloors = obj.m_plannedFloors;
    m_plannedEntrances = obj.m_plannedEntrances;
    m_builtFloors = obj.m_builtFloors;
    m_builtEntrances = obj.m_builtEntrances;
}

Building& Building::operator=(const Building& obj) {
    this->m_address = obj.m_address;
    this->m_plannedFloors = obj.m_plannedFloors;
    this->m_plannedEntrances = obj.m_plannedEntrances;
    this->m_builtFloors = obj.m_builtFloors;
    this->m_builtEntrances = obj.m_builtEntrances;

    return *this;
}


ostream& operator << (ostream& out, const Building& obj) {
    out << '"' << obj.getBuilding_address() << '"' << ' '
    << obj.getBuilding_plannedFloors() << ' '
    << obj.getBuilding_plannedEntrances() << ' '
    << obj.getBuilding_builtFloors() << ' '
    << obj.getBuilding_builtEntrances() << '\n';

    return out;
}
istream& operator >> (istream& in, Building& obj) {
    string f;
    //getline(in, f);
    int a, b, c, d;
    in >> f >> a >> b >> c >> d;

    obj.setAddress(f);
    obj.setPlanFloors(a);
    obj.setPlanEntr(b);
    obj.setBuiltFloors(c);
    obj.setBuiltEntr(d);
    return in;
}

// b + 1 "increment built floors"
// 1 + b "increment built entrances"

Building& operator+( Building &lhs, int rhs) {
    lhs.m_builtFloors += rhs;
    return lhs;
}
Building& operator+=( Building &lhs, int rhs) {
    lhs.m_builtFloors += rhs;
    return lhs;
}

Building& operator+(int lhs, Building& rhs) {
    rhs.m_builtEntrances += lhs;
    return rhs;
}
Building& operator+=(int lhs, Building& rhs) {
    rhs.m_builtEntrances += lhs;
    return rhs;
}