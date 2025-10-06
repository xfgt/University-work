//
// Created by ADMIN on 06-Oct-25.
//

#include <iostream>
#include <vector>
using namespace std;


class BaseType {
public:
    virtual ~BaseType() = default;

    virtual void print() const {
        cout << "[" << this << "] BaseType::print\n";
    }
};


class Type1 : public BaseType {
public:
    void print() const override {
        cout << "[" << this << "] Type1::print()\n";
    }
};

class Type2 : public BaseType {
public:
    void print() const override {
        cout << "[" << this << "] Type2::print()\n";
    }
};

class Type3 : public BaseType {
public:
    void print() const override {
        cout << "[" << this << "] Type3::print()\n";
    }
};


int main() {

    vector<BaseType*> v_PolymorphContainer;

    BaseType* b_ptr;
    b_ptr = new BaseType();
    v_PolymorphContainer.push_back(b_ptr);


    b_ptr = new Type1();
    v_PolymorphContainer.push_back(b_ptr);

    b_ptr = new Type2();
    v_PolymorphContainer.push_back(b_ptr);

    b_ptr = new Type3();
    v_PolymorphContainer.push_back(b_ptr);


    for (const auto& i : v_PolymorphContainer)
        i->print();

    b_ptr = v_PolymorphContainer.at(1); // Type 1
    b_ptr->print();


//  Memory management
    for (auto& i : v_PolymorphContainer) {
        delete i;
        cout << "Deleted " << i << '\n';
        i = nullptr;
    }
    b_ptr = nullptr;

    return 0;
}