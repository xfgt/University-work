//
// Created by ADMIN on 06-Oct-25.
//

// main.cpp
#include "People.h"
#include <iostream>

#include <locale.h>
#include <windows.h>

using namespace std;

int main(){

    setlocale(LC_ALL, ".utf8");
    SetConsoleOutputCP(65001);

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
    return 0;
}
