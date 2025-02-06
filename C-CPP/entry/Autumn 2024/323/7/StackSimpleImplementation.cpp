//
// Created by MRSLAVE on 23-Nov-24.
//
#include <iostream>

typedef struct Element * po;

struct Element {
    po Next{};
    char Data{};
};


int main() {

    po na = nullptr;
    po p{};
    po it;

    for (;;) {
        p = new Element;

        std::cin >> p->Data;

        p->Next = na;
        na = p;
        //~ Printing the stack ~
        std::cout << "CURRENT STACK\n";
        it = na;
        while(it != nullptr) {
            std::cout << it->Data << std::endl << "-----" << std::endl;
            it = it->Next;
        }
    }






//  Memory management!
    it = na;
    po x = it;
    while(true) {
        if(it) {
            x = it->Next;
            delete it;
            it = x->Next;
        } else {
            delete x;
            break;
        }
    }



    return 0;
}