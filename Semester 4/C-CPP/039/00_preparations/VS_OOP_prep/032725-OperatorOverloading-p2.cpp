#if 1

#include "Double.h"

// firend & global functions
// nqmashe mnogo hora
//#include <cmath> // inherited from c
#include <math.h> // cpp
#include <iostream>
using namespace std;

// normal operators need to be global
Double operator+(const Double& a, const Double& b) {
	Double res = a;
	return (res += b);
}

Double operator-(const Double& a, const Double& b) {
	Double res = a;
	return (res -= b);
}
Double operator*(const Double& a, const Double& b) {
	Double res = a;
	return (res *= b);
}
Double operator/(const Double& a, const Double& b) {
	Double res = a;
	return (res /= b);
}
Double operator%(const Double& a, const Double& b) {
	Double res = a;
	return (res %= b);
}




int main() {


#if 0
	double a = 2.0;
	double b = sqrt(2.0) * sqrt(2.0);
	// double ne poddurja modulo (%)
	std::cout << std::boolalpha << (a == b) << std::endl; // false

	// DOUBLE OVERLOADED
	Double x = 2.0;
	Double y = sqrt(2.0) * sqrt(2.0);
	// double ne poddurja modulo (%)
	std::cout << std::boolalpha << (x == y) << std::endl; // true
#endif
	Double x = 4;
	Double y = 42;
	Double d = x + y;
	Double s = x + 10; // doesnt work with constants
	y %= x;
	std::cout << d; // cannot do << (x + y)
	

	std::cout << s;
}
#endif