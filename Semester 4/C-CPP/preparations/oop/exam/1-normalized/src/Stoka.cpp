
#include "Stoka.h"
#include <iostream>
#include <cstring>

const size_t MAX_SIZE {21};


Stoka::Stoka() : 	_n(new char[MAX_SIZE]), _id(new char[MAX_SIZE]),
					_ww(0.0l), _l(0), _w(0), _h(0) {}

Stoka::Stoka(const char* name, const char* id,
			 double weight,
			 int lenght,
			 int width,
			 int height) : Stoka(){
	//setters
	setName(name);
	setId(id);	
	setww(weight);
	setl(lenght);
	setw(width);
	seth(height);


}	
//Stoka::~Stoka(){
//	delete[] _n;
//	delete[] _id;
//}
Stoka::Stoka(const Stoka& rhs) : 
	Stoka(rhs._n, rhs._id, rhs._ww, rhs._l, rhs._w, rhs._h)
{}

Stoka& Stoka::operator= (const Stoka& rhs){ // notice!
	
	setName(rhs._n);
	setId(rhs._id);
	setww(rhs._ww);
	setl(rhs._l);
	setw(rhs._w);
	seth(rhs._h);

	return *this;
}



void Stoka::setName(const char* name){
	std::snprintf(_n, MAX_SIZE, "%s", name);
}
void Stoka::setId (const char* id){
 	std::snprintf(_id, 11, "%s", id);
}

void Stoka::setww(double w) { _ww = w; }
void Stoka::setl(int l) { _l = l; }
void Stoka::setw(int w) { _w = w; }
void Stoka::seth(int h) { _h = h; }




char* Stoka::getName() 	{ return _n;	}
char* Stoka::getId()	{ return _id; 	}
double Stoka::getww()	{ return _ww;	}
int Stoka::getl()		{ return _l;	}
int Stoka::getw()		{ return _w;	}
int Stoka::geth()		{ return _h;	}





std::istream& operator >> (std::istream& in, Stoka& obj){
	
	char temp[100]{};
	in.getline(temp, 100);
	obj.setName(temp);


	in.getline(temp, 100);
	obj.setId(temp);
	in >> obj._ww >> obj._l >> obj._w >> obj._h;
	
	in.ignore();
	in.ignore();
	return in;

}


std::ostream& operator << (std::ostream& out, Stoka& obj) {

	out << obj.getName() 	<< std::endl
		<< obj.getId()		<< std::endl
		<< obj.getww()		<< std::endl
<< obj.getl() << " " << obj.getw() << " " << obj.geth() << std::endl;

	return out;

}
