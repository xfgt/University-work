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
		H(const char* x = "", int y =0, float z=0.){
			a = new char[strlen(x)+1];
			strcpy(a, x);

			b = y;
			c = z;

		}

		void seta(char* q){
			if(a != nullptr) delete[] a; // empty *this on reach
			a = new char[strlen(q) + 1];
			strcpy(a, q);
		}
		char* geta() {return a;}


		void setb(int w) { b = w;}
		int getb()	{return b;}

		void setc(float e) {c = e;}
		float getc() {return c;}


};


std::ostream& operator << (std::ostream& out, H& obj)
{
	out << obj.geta() << std::endl
		<< obj.getb() << std::endl
		<< obj.getc() << std::endl;
	return out;
}
std::istream& operator >> (std::istream& in, H& obj){

	char* x;
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

