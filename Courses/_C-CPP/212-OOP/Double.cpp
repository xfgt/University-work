#include "Double.h"


// preporuchva se binarnite operacii da sa globalni


Double::Double(double val) : d(val) {};

bool Double::operator==(const Double& rhs) const {
	double l = fabs(d);
	double r = fabs(rhs.d);

	double m = l > r ? l : r;

	double res = fabs(d - rhs.d);


	
	return m == 0. ? true : res / m < 1.e-14;
}

bool Double::operator!=(const Double& rhs) const {
	return !(*this == rhs);

		//*this is lhs (deref)
}

ostream& operator<<(ostream& out, Double& rhs) { 
	/*return out << rhs.d;*/
	return rhs.ins(out); // const Double gives a problem;
}

Double& Double::operator+=(const Double& rhs){
	d += rhs.d;
	return *this;
}
Double& Double::operator-=(const Double& rhs){
	d -= rhs.d;
	return *this;
}
Double& Double::operator*=(const Double& rhs){
	d *= rhs.d;
	return *this;
}
Double& Double::operator/=(const Double& rhs){
	d /= rhs.d;
	return *this;
}

Double& Double::operator%=(const Double& rhs) {
	d = d - (int)(d / rhs.d) * rhs.d;
	return *this;
}