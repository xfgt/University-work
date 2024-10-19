//
// Created by Slave on / Saturday / 19-Oct-24.
//


#include <iostream>


int bs(int* a, unsigned n, int x) {

    int start = 0;
    int _end = n;
    int mid = (start + _end)  / 2;



    while(a[mid] != x && _end >= start){    //  де Морган
        std::cout << a[mid] << std::endl;

        if(a[mid] < x)
            start = mid+1; // махам всичко от start до mid
         else
            _end = mid -1; // местим другия край

        mid = (start + _end)  / 2;
    }

    return mid;
}


int main() {


    int X[11] {1, 2, 3, 4, 5, 6, 7, 8, 18, 9, 10};



    std::cout << bs(X, 11, 18);

    return 0;
}