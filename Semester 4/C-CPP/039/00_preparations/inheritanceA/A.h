#pragma once
#define MAX_SIZE 5

#include <iostream>

class A {

	friend std::ostream& operator << (std::ostream&, const A&);
	friend std::istream& operator >> (std::istream&, A&);

private:
	char name[MAX_SIZE];
	int number;
	float point;

public:

	A(const char* ="", int =0, float =0);
	A(const A&);
	
	A& operator= (const A&);


	// getters

	char* getName();
	int getNumber();
	float getPoint();


	// setters

	void setName(const char*);
	void setNumber(int);
	void setPoint(float);

	

};
std::ostream& operator << (std::ostream&, A&);

std::istream& operator >> (std::istream&, A&);
