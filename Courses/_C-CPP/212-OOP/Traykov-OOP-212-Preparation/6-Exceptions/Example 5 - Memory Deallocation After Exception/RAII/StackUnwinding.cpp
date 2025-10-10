//
// Created by LOCAL_ADMIN on 10.10.2025 г..
//
#include <iostream>
using namespace std;


// Пусни си да гледаш стека
struct Log {
    const char* name;
    Log(const char* n): name(n) { cout << "ctor " << name << endl; }
    ~Log()                    { cout << "dtor " << name << endl; }
};

void f() {
    Log a{"A"};
    Log b{"B"};
    throw runtime_error("boom"); // няма catch тук
    Log c{"C"}; // няма да се изпълни
}

int main() {
    try {
        f();
    } catch (const exception& e) {
        cout << "caught: " << e.what() << endl;
    }
}
