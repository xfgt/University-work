//
// Created by MRSLAVE on 23-Nov-24.
//
#include <iostream>


typedef struct Element * po;

struct Element {
    po Next{};
    char Data{};
};

po createList(int size) {
    po na;
    po p;
    na = nullptr;
    while(size--){
        p = new Element;
        std::cin >> p->Data;
        p->Next = na;
        na = p;
    }
    return na;
}

void printList(po na) {
    po it;
    it = na;
    while(it != nullptr) {
        std::cout << " | " << it->Data ;
        it = it->Next;
    }
    std::cout << std::endl;
}

void printListR(po na) {
    if(na != nullptr) {
        printListR(na->Next);
        std::cout << na->Data << " | ";
    }
}

void clean(po na) {

    po it = na;
    po x = it;
    while(true) {
        if(x) {
            x = it->Next;
            delete it;
            it = x->Next;
        } else {
            delete it;
            break;
        }
    }
} // Memory management! todo

int main() {

    po na = createList(3);
    printListR(na);

    system("pause");


    po contr;

    // primeren element za manipulaciq
    po p = new Element;
    p->Data = 4;

    // vmukvane
    contr = na;
    while(contr != nullptr && contr->Data != 3 && contr->Next != nullptr) {
        contr = contr->Next;
    }
    if(contr != nullptr) {
        p->Next = contr->Next;
        contr->Next = p;
    } else {
        na = p;
        p->Next = nullptr;
    }
    printList(na);



    // izmukvane
    contr = na;
    while(contr != nullptr && contr->Next->Data != 3 && contr->Next != nullptr) {
        contr = contr->Next;
    }
    if(contr->Next->Data == 3) {
        p = contr->Next;
        contr->Next = p -> Next;
        delete p;
    }




    printList(na);



    //clean(na); //todo










    return 0;
}