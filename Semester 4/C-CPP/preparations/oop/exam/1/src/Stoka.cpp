
#include "Stoka.h"
#include <iostream>
#include <cstring>


Stoka::Stoka(){
	_n = nullptr;
	_id = nullptr;
	_ww = 0.0f;
	_l = _w = _h = 0;
}



char* Stoka::getName() 	{ return _n;	}
char* Stoka::getId()	{ return _id; 	}
double Stoka::getww()	{ return _ww;	}
int Stoka::getl()		{ return _l;	}
int Stoka::getw()		{ return _w;	}
int Stoka::geth()		{ return _h;	}



void Stoka::setName(char* name) { 
	if(_n!=NULL){
		delete[] _n;
	}
	_n = new char[strlen(name)+1];
	strcpy(_n, name);
}


void Stoka::setId(char* id){
	if(_id!=NULL){
		delete[] _id;
	}
	_id = new char[strlen(id)+1];
	strcpy(_id, id);
}


void Stoka::setww(double w) { _ww = w; }
void Stoka::setl(int l) { _l = l; }
void Stoka::setw(int w) { _w = w; }
void Stoka::seth(int h) { _h = h; }


std::istream& operator >> (std::istream& in, Stoka& obj){
	
	char name[100];
	char id[100];
	in >> name >> id;
	obj.setName(name);
	obj.setId(id);
	in.clear();
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	
	in >> obj._ww >> obj._l >> obj._w >> obj._h;

	return in;

}


std::ostream& operator << (std::ostream& out, Stoka& obj) {

	out << obj.getName() 	<< std::endl
		<< obj.getId()		<< std::endl
		<< obj.getww()		<< std::endl
<< obj.getl() << " " << obj.getw() << " " << obj.geth() << std::endl;

	return out;

}
