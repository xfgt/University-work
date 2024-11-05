#include "../AlgorithmsDir/algorithms.h"

void merge(int li, int mid, int mid1, int di) {
    //TODO w/ masters theory!
}


void mergeSort(int* A, int li, int di) {

    if(li < di) { // base case
        int mid = (li+di) / 2;
        mergeSort(A, li, mid ); // left
        mergeSort(A, mid+1, di); // right
        merge(li, mid, mid+1, di);
    }
}

