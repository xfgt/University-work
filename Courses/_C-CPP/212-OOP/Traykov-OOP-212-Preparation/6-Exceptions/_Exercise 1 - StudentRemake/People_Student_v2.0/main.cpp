//
// Created by ADMIN on 10-Oct-25.
//

// main.cpp
#include "People.h"
#include <iostream>

#include <locale.h>
#include <set>
#include <windows.h>

using namespace std;


std::set<Student*> createCollection(int n) throw (std::bad_alloc, std::logic_error){


    auto collection = new std::set<Student*>();
    Student* s;


    for (int i = 0; i < n; i++) {
        s = new Student();
        s->read(); // TODO: fix reading next object; make the sorting overlad of operator < for s->grade; p. 52/53
        collection->insert(s);
    }


    return *collection;
}


void destroyCollection(std::set<Student*>& collection) {
    collection.clear();

}

int main(){

    setlocale(LC_ALL, ".utf8");
    SetConsoleOutputCP(65001);

    /*{
        People * arrPeople[3];
        arrPeople[0] = new People("Тихомир Лалев", "8904123648");
        arrPeople[1] = new Student("Анастасия Георгиева", "9206066055", "F323248", 5.45);
        arrPeople[2] = new Student("Христо Караиванов", "9311123040", "F121234", 4.34);
        for(int i=0; i<3; i++){
            cout << "Име: " << arrPeople[i]->get_name()
            << " ЕГН: " << arrPeople[i]->get_egn() << endl;

            arrPeople[i]->print(); // полиморфизъм
            //cout << (*arrPeople[i]) << endl;
        }
    }*/



    { // 6 - Exceptions


        std::set<Student*> StudentsCollection;

        try {
            StudentsCollection = createCollection(3);

        } catch (const std::bad_alloc& e) {

            destroyCollection(StudentsCollection);
            std::cout << "Caught exception of type BADALLOC: " << e.what() << std::endl;


        } catch (const std::logic_error& e) {
            destroyCollection(StudentsCollection);
            std::cout << "Caught exception of type LOGICEROR: " << e.what() << std::endl;

        } catch (...) {
            destroyCollection(StudentsCollection);
            std::cout << "Caught exception of ~UNSPECIFIED~ type:\r\n" << std::endl;
        }










    }
    return 0;
}
