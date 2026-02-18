//
// Created by LOCAL_ADMIN on 18.2.2026 г..
//

#include <iostream>
#define SEPERATE std::cout << "=======================\n";


int main() {


    int a = 5;
    int b = 3;
    int* pA = &a;


    const int e = 3;        // value could not be changed, cannot do e++;


    {
        std::cout << e << '\n';
        // cannot do e++

        // address of e (&e) can be assigned to a pointer
    }





    const int* eP = &e;     // value could not be changed, cannot do (*eP)++, but can do *(++eP) which moves the address to the next segment and dereferences it
    {
        // cannot *eP = 2;
        std::cout << eP << '\n';
        std::cout << *eP << '\n';
        ++eP;
        std::cout << eP << '\n';
        std::cout << *eP << '\n';
        ++eP;
        std::cout << eP << '\n';
        std::cout << *eP << '\n';
        SEPERATE
    }




    
    int const* ep_ = &e;    // value could not be changed (identical with line 18)
    {
        // cannot ep_ = 2;
        std::cout << ep_ << '\n';
        std::cout << *ep_ << '\n';
        ++ep_;
        std::cout << ep_ << '\n';
        std::cout << *ep_ << '\n';
        ++ep_;
        std::cout << ep_ << '\n';
        std::cout << *ep_ << '\n';
        SEPERATE
    }
    // const int* eP    and     int const* eP.     are functionally identical!



    int* const iPc = &a;            // cannot point to another address, but can change value
    {
        // cannot iPc++;
        std::cout << iPc << '\n';
        std::cout << *iPc << '\n';
        std::cout << ++(*iPc)  << '\n'; // can increment the value, not the address
        SEPERATE
    }





    const int* const ciPc = &b;     // value could not be changed and cannot point to another address

    {
        // cant do *(++ciPc);, nor ++(*ciPc);


    }


    /*
    *           const before the type*: The data is constant.
    *           const after the type*: The pointer (address) is constant. (cannot point to another address)
    */





    std::flush(std::cout);
    return 0;
}