//
// Created by ADMIN on 10-Oct-25.
//

// People.cpp
#include <iostream>
#include "People.h"
#include <cassert>
#include <complex>
#include <cstring>

People::People(char * n, char * e){
	name = new char[strlen(n)+1];
	assert(name!=nullptr);
	strcpy_s(name, strlen(n)+1, n);

	egn = new char[strlen(e)+1];
	assert(egn!=nullptr);
	strcpy_s(egn, strlen(e)+1, e);
}

People::People(const People & p){
	name = new char[strlen(p.name)+1];
	assert(name!=nullptr);
	strcpy_s(name, strlen(p.name)+1, p.name);

	egn = new char[strlen(p.egn)+1];
	assert(egn!=nullptr);
	strcpy_s(egn, strlen(p.egn)+1, p.egn);
}

People::~People(){
	delete [] egn;
	delete [] name;
}

void People::set_name(char * n){
	if(name != nullptr) delete [] name;
	name = new char[strlen(n)+1];
	assert(name!=nullptr);
	strcpy_s(name, strlen(n)+1, n);
}

void People::set_egn(char * e){
	if(egn != nullptr) delete [] egn;
	egn = new char[strlen(e)+1];
	assert(egn!=nullptr);
	strcpy_s(egn, strlen(e)+1, e);

}

char * People::get_name() const{
	return name;
}

char * People::get_egn() const{
	return egn;
}

void People::print() const{
	std::cout << "Name: " << name << std::endl;
	std::cout << "EGN: " << egn << std::endl;
}

std::ostream & operator << (std::ostream & out, const People & p){
	out << "Name: " << p.name << " EGN: " << p.egn << std::endl;
	return out;
}

std::istream & operator >> (std::istream & in, People & p){
	in >> p.name >> p.egn;
	return in;
}


Student::Student(char * n, char * e, char * f, double g):People(n, e){
	fnum = new char[strlen(f)+1];
	assert(fnum!=nullptr);
	strcpy_s(fnum, strlen(f)+1, f);

	if(g >= 2 && g <= 6) grade = g;
	else if(g < 2) grade = 2;
	else grade = 6;
}

Student::Student(const Student & s):People(s){
	std::cout << "Student(const & )\n";
	fnum = new char[strlen(s.fnum)+1];
	assert(fnum!=nullptr);
	strcpy_s(fnum, strlen(s.fnum)+1, s.fnum);

	grade = s.grade;
}

Student::~Student(){
	delete [] fnum;
}

void Student::read() throw(std::bad_alloc, std::logic_error){
	char* lname;
	char* legn;
	char* lfnum;
	double lgrade{};

	lname = new char[20];
	if (!lname)
		throw std::bad_alloc();

	legn = new char[10];
	if (!legn)
		throw std::bad_alloc();

	lfnum = new char[7];
	if (!lfnum)
		throw std::bad_alloc();


	std::cin.getline(lname, sizeof(lname)* 20);
	std::cin.getline(legn, sizeof(legn) * 10); // you can do a check with regex
	std::cin.getline(lfnum, sizeof(lfnum) * 7); // ~/~


	int cnt{1};
	while (!(std::cin >> lgrade) && cnt <= 3) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "[" << cnt++ << "] Please enter a number for grade: ";
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


	if (!std::cin)
		throw std::logic_error("The entered grade is different of floating point type!");


	this->set_name(lname);
	this->set_egn(legn);
	this->set_fnum(lfnum);
	this->set_grade(lgrade);

	std::cin.clear();
}

void Student::set_fnum(char * f){
	if(fnum != nullptr) delete [] fnum;
	fnum = new char[strlen(f)+1];
	assert(fnum!=nullptr);
	strcpy_s(fnum, strlen(f)+1, f);

}

void Student::set_grade(double g){
	if(g >= 2 && g <= 6) grade = g;
	else if(g < 2) grade = 2;
	else grade = 6;

}

char * Student::get_name() const{
	//std::cout << "Student's name:";
	return People::get_name();
}

char * Student::get_egn() const{
	//std::cout << "Student's EGN:";
	return People::get_egn();
}

char * Student::get_fnum() const{
	return fnum;

}

double Student::get_grade() const{
	return grade;

}

void Student::print() const{
	People::print();
	std::cout << "Faculty number: " << fnum << std::endl;
	std::cout << "Grade: " << grade << std::endl;
}

std::ostream & operator << (std::ostream & out, const Student & s){
	out << "Name: " << s.get_name() << " EGN: " << s.get_egn() << std::endl
		<< " Faculty number: " << s.fnum << " Grade: " << s.grade << std::endl;
	return out;
}

std::istream & operator >> (std::istream & in, Student & s){
            char * tname;
            char * tegn;
            in >> tname >> tegn;

            s.set_name(tname);
            s.set_egn(tegn);
            in >> s.fnum >> s.grade;
	return in;
}