//
// Created by ADMIN on 10-Oct-25.
//

// compile with C++ 11

// main.cpp


#include "People.h"
#include <iostream>
#include <algorithm>
#include <locale.h>
#include <windows.h>
#include <set>



typedef std::set<People*, StudentCmp> People_ptr_col;


People_ptr_col createCollection(int n) throw (std::bad_alloc, std::logic_error){

    People_ptr_col collection;
    Student* s;


    try {
        for (int i = 0; i < n; i++) {
            s = new Student();
            s->read();
            collection.insert(s);
        }
    } catch (...) {
        return collection;
    }
    return collection;
}


void destroyCollection(People_ptr_col& collection) {

    for (auto& x : collection) {
        delete x; // to delete properly first ~Student(), ~People() must be VIRTUAL
    }
    collection.clear();
}

void printCollection(const People_ptr_col& collection){
    for (const auto& i : collection)
        std::cout << *(dynamic_cast<Student*>(i)) << std::endl; // polymorphism
}


void getHighestScore(People_ptr_col& col) {
    std::cout << "*** The student with the highest score goes to: " << *(dynamic_cast<Student*>(*(col.begin()))) << std::endl;
    std::cout << "\t Congratulations!!!\r\n";
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



    {
        // 6 - Exceptions


        People_ptr_col StudentsCollection;
        int records{};

        try {

            std::cin >> records;
            StudentsCollection = createCollection(records); // if error it returns the already filled collection
            //std::sort(StudentsCollection->begin(), StudentsCollection->end());
            printCollection(StudentsCollection);
            getHighestScore(StudentsCollection);


            destroyCollection(StudentsCollection);

        } catch (const std::bad_alloc& e) {

            std::cout << "Caught exception of type BADALLOC: " << e.what() << std::endl;
            destroyCollection(StudentsCollection);

        } catch (const std::logic_error& e) {

            std::cout << "Caught exception of type LOGICEROR: " << e.what() << std::endl;
            destroyCollection(StudentsCollection);

        } catch (...) {

            std::cout << "Caught exception of ~UNSPECIFIED~ type:\r\n" << std::endl;
            destroyCollection(StudentsCollection);
        }










    }
    return 0;
}
