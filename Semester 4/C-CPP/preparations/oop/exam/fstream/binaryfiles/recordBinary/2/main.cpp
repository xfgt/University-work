#include <iostream>
#include <fstream>
#include <string.h>


class H{
	friend std::ostream& operator << (std::ostream&, H&);
	friend std::istream& operator >> (std::istream&, H&);

	private:
		char* a; // this memory allocation
		int b;
		float c;


	public:
	 // getters
	 // setters
};


std::ostream& operator << (std::ostream& out, H& obj)
{
	out << obj.geta() << std::endl
		<< obj.getb() << std::endl
		<< obj.getc() << std::endl;
	return out;
}
std::istream& operator >> (std::istream& in, H& obj){

	char x[] {};
	in >> x;

	obj.seta(x);
	in >> obj.b >> obj.c;

	return in;
}





int main(){

	H h;
	std::cin >> h;
	std::cout << h << std::endl;

	return 0;
}

