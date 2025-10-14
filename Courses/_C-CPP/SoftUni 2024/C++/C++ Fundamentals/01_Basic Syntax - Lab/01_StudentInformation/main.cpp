//
// Created by twister on 8/26/24.
//


#include <iostream>
#include <iomanip>
#include <string>



int main(){
    using namespace std;
    cout << setprecision(2);

    string name{};
    int age;
    double avgG;


    cin >> name >> age >> avgG;


    cout << fixed <<
        "Name: " << name <<
            ", Age: " << age <<
                ", Grade: " << avgG << endl;


    return 0;
}