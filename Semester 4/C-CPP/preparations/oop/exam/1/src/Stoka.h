#include <iostream>

class Stoka{

	friend std::ostream& operator << (std::ostream&, Stoka&);
	friend std::istream& operator >> (std::istream&, Stoka&);


	private:
		
		char* _n;
		char* _id;
		double _ww;
		int _l, _w, _h;


	public:

		Stoka();
	
		char* getName();
		char* getId();
		double getww();
		int getl();
		int getw();
		int geth();


		void setName(char*);
		void setId(char*);
		void setww(double);
		void setl(int);
		void setw(int);
		void seth(int);
};

std::ostream& operator << (std::ostream&, Stoka&); // const Stoka&
std::istream& operator >> (std::istream&, Stoka&);


