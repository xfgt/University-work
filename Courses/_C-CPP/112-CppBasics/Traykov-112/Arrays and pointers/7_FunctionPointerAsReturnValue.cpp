//
// Created by LOCAL_ADMIN on 20-Mar-26.
//


#include <iostream>


int(*fun(int, int))(int*, int); // this returns a type of int(*)(int*, int) [ a function pointer ]

typedef int (*funPoint)(int*, int);
funPoint fun(int, int);
int main() {




    return 0;
}