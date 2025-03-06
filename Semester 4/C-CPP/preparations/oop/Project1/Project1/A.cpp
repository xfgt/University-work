#include "A.h"


#include <iostream>
#include <cstring>


A::A(const char* name, int number, float point) : number(number), point(point) {

	this->setName(name);

}

A::A(const A& rhs) : A(rhs.name, rhs.number, rhs.point) {}
A& A::operator=(const A& rhs) {
	A temp(rhs);
	return temp;
}


char* A::getName() { return name; }
int A::getNumber()  { return number; }
float A::getPoint() { return point; }



void A::setName(const char* name) {
	if (name) {
		if (strlen(name) <= MAX_SIZE)
			strcpy_s(this->name, name);
		else
			strncpy_s(this->name, name, MAX_SIZE-1);
	}
}

void A::setNumber(int number) {
	this->number = number;
}

void A::setPoint(float point) {
	this->point = point;
}

std::ostream& operator << (std::ostream& out, A& rhs) {
	out << rhs.getName() << std::endl << rhs.getNumber() << std::endl << rhs.getPoint() << std::endl;

	return out;
}

std::istream& operator >> (std::istream& in, A& rhs) {

	char temp[100];
	in.getline(temp, 100);
	rhs.setName(temp);

	in >> rhs.number >> rhs.point;
	in.ignore();

	return in;


}