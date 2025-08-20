#pragma once
#include <math.h>
#include <iostream>
using namespace std;

class Double {

	

public:
	Double(double val = 0.);


	bool operator==(const Double& rhs) const;
	bool operator !=(const Double& rhs) const;

	operator double() { return d; }
	
	// za da ne pishem getter moje da napravim friend ostream no ne e pravilno
	//friend ostream& operator<<(ostream& out, const Double& rhs);

	// moje inserter
	ostream& ins(ostream& out) {
		return out << d;
	}

	// as methods
	Double& operator+=(const Double&);
	Double& operator-=(const Double&);
	Double& operator*=(const Double&);
	Double& operator/=(const Double&);
	Double& operator%=(const Double&);


	//pishem getter

private:
	double d;
};

ostream& operator<<(ostream& out, Double& rhs);