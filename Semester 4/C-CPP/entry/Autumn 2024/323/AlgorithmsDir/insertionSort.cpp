#include "algorithms.h"
void insertionSort(int* a, unsigned n){
    for(int i = 1; i < n; ++i) {

        int buf = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > buf) {
            a[j+1] = a[j]; // shift right (up)
            j--;
        }
        a[j+1] = buf;

    }
}


