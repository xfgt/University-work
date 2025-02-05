// main
#include "D:\Documents\Personel\University\entry\323\AlgorithmsDir\algorithms.h"
#include <time.h>


unsigned sz = 20;


int main() {

    srand(time(NULL));

    int A[sz];
    printf("Vuzhodyashti: ");
    for(int i = 0; i < sz; i++) A[i] = i+1;
    printarr(A, sz);
    quickSort(A, 0, sz);
    printarr(A, sz);

    printf("Nizhodyashti: ");
    for(int i = sz-1; i >= 1; i--) A[i] = i+1;
    printarr(A, sz);
    quickSort(A, 0, sz);
    printarr(A, sz);

    printf("Random: ");
    for(int i = 0; i < sz; i++) A[i] = rand() % sz+1;
    printarr(A, sz);
    quickSort(A, 0, sz);
    printarr(A, sz);

    return 0;
}

