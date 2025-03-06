#include <iostream>
#include "A.h"


int main(){

    A f;
    A g[MAX_SIZE];

    A oa{"", 0, 7.542};
    A ob{"%", 1, 5.32};
    A oc{"123456", 2, 153.6572};

    std::cout << oa.getName() << std::endl << oa.getNumber() << std::endl << oa.getPoint() << std::endl;
    std::cout << ob.getName() << std::endl << ob.getNumber() << std::endl << ob.getPoint() << std::endl;
    std::cout << oc.getName() << std::endl << oc.getNumber() << std::endl << oc.getPoint() << std::endl;






    return 0;
}
