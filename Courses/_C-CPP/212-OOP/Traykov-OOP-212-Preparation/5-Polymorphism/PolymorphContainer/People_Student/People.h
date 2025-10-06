//
// Created by ADMIN on 06-Oct-25.
//

// People.h
#ifndef CPP_PEOPLE_H
#define CPP_PEOPLE_H

#include <iostream>

class People{
    friend std::ostream & operator << (std::ostream &, const People &);
    friend std::istream & operator >> (std::istream &, People &);
public:
    People(char * = "No Name", char * ="No EGN");
    People(const People &);

    ~People();

    void set_name(char *);
    void set_egn(char *);

    virtual char * get_name() const;
    virtual char * get_egn() const;

    virtual void print() const;
private:
    char * name;
    char * egn;
};

class Student:public People{
    friend std::ostream & operator << (std::ostream &, const Student &);
    friend std::istream & operator >> (std::istream &, Student &);
public:
    Student(char * = "No Name", char * ="No EGN", char * ="No Faculty Number", double = 2.);
    Student(const Student &);

    ~Student();

    void set_fnum(char *);
    void set_grade(double);

    virtual char * get_name() const;
    virtual char * get_egn() const;
    char * get_fnum() const;
    double get_grade() const;

    virtual void print() const;
private:
    char * fnum;
    double grade;
};

std::ostream & operator << (std::ostream &, const People &);
std::istream & operator >> (std::istream &, People &);

std::ostream & operator << (std::ostream &, const Student &);
std::istream & operator >> (std::istream &, Student &);


#endif //CPP_PEOPLE_H