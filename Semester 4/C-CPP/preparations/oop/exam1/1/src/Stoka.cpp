
#include "Stoka.h"
#include <iostream>
#include <cstring>
#include <cassert>

Stoka::Stoka(
			    const char* name,
				const char* id,
				double weight,
				int lenght,
				int width,
				int height
		){

		_n = new char[std::strlen(name)+1];
		assert(name != nullptr);
		strcpy(_n, name);
		

		_id = new char[std::strlen(id)+1];
		assert(id != nullptr);
		strcpy(_id, id);


		_ww = weight;
		_l = lenght;
		_w = width;
		_h = height;


}


Stoka::~Stoka(){
	delete[] _n;
	delete[] _id;
}


char* Stoka::getName() 	{ return _n;	}
char* Stoka::getId()	{ return _id; 	}
double Stoka::getww()	{ return _ww;	}
int Stoka::getl()		{ return _l;	}
int Stoka::getw()		{ return _w;	}
int Stoka::geth()		{ return _h;	}



void Stoka::setName(const char* name) { 
	
	if(_n != nullptr) delete[] _n;

	_n = new char[std::strlen(name)+1];
	assert(name != nullptr);
	strcpy(_n, name);
}


void Stoka::setId(const char* id){

	if(_id != nullptr) delete[] _id;

	_id = new char[std::strlen(id)+1];
	assert(_id != nullptr);
	strcpy(_id, id);
}


void Stoka::setww(double w) { _ww = w; }
void Stoka::setl(int l) { _l = l; }
void Stoka::setw(int w) { _w = w; }
void Stoka::seth(int h) { _h = h; }


std::istream& operator >> (std::istream& in, Stoka& obj){
	 
	char* n = new char[20];
	char* i = new char[20];

	in >> n >> i;
	obj.setName(n);
	obj.setId(i);
	delete[] n;
	delete[] i;

	in >> obj._ww >> obj._l >> obj._w >> obj._h;

	return in;

}


std::ostream& operator << (std::ostream& out, Stoka& obj) {

	out << obj.getName() 	<< std::endl
		<< obj.getId()		<< std::endl
		<< obj.getww()		<< std::endl
<< '[' << obj.getl() << ", " << obj.getw() << ", " << obj.geth() << ']' << std::endl;

	return out;

}
