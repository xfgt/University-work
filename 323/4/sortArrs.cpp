#include "../AlgorithmsDir/algorithms.h"

#include <iomanip>
#include <cstdlib>
#include <ctime>
unsigned sTime;
void startTimer() { sTime = clock(); }
void stopTimer() { std::cout << std::setprecision(7) << (float)(clock() - sTime) / CLOCKS_PER_SEC << "s. \n"; }

int main() {

    // slyvane na dva masiva

    int i{}, j{}, k{};

    int A[10] = {2, 4, 5, 6, 8, 9, 11, 17, 28, 34};
    int B[7] = {1, 2, 3, 7, 8, 9, 15};

    int C[10+7+1]{};

    startTimer();
    while(j < 7) {
        if(A[i] < B[j])     C[k++] = A[i++];
        else                C[k++] = B[j++];
    }
    stopTimer();

    startTimer();
    C[k++] = A[i];
    while(j < (sizeof(C) / sizeof(C[0]))) C[k++] = A[j++];
    stopTimer();

    printarr(C, 18);

    return 0;
}