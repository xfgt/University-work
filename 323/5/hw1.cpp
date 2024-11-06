
#include "../AlgorithmsDir/algorithms.h"

int main() {
    const unsigned sz = 7;

    int A[sz] = {11, 3, 6, 20, 4, 5, 2};
    int B[sz] = {11, 3, 6, 20, 4, 5, 2};

    std::cout << "A:\tquickSort" << std::endl;
    printarr(A, sz);
    quickSort(A, 0, sz);
    printarr(A, sz);

    std::cout << "\nB:\tmergeSort" << std::endl;
    printarr(B, sz);
    mergeSort(B, 0, sz);
    printarr(B, sz);


    return 0;
}
