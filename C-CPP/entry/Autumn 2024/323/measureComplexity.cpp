#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>



// algorithms

#include "D:/Documents/Personel/University/entry/323/AlgorithmsDir/algorithms.h"


// arr on heap
const unsigned GSIZE = 200000;
unsigned sTime;

void startTimer() { sTime = clock(); }
void stopTimer() { std::cout << std::setprecision(7) << (float)(clock() - sTime) / CLOCKS_PER_SEC << "\t"; }

int main(){
	srand(time(NULL));

	for(int x = 1000; x <= GSIZE ; x+= 1000) {
		// getting more samples
		int* A = new int[x];
		int* B = new int[x];
		for(int i = 0; i < x; i++){
			A[i] = rand() % 100 + 1;
			B[i] = A[i];
		}
		std::cout << x << std::endl;
// Print arrays
		// printarr(A, x);
		// printarr(B, x);

// Algorithms
		//std::cout << "QuickSort\t";
		startTimer();
		quickSort(A, 0, x);
		stopTimer();

		// std::cout << "MergeSort\t";
		// startTimer();
		// mergeSort(B, 0, x);
		// stopTimer();


// Print arrays [sorted]
		// printarr(A, x);
		// printarr(B, x);
		 //system("pause");


		delete[] A;
		delete[] B;
	}

	return 0;
}





