#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>



// algorithms

#include "D:/Documents/Personel/University/entry/323/AlgorithmsDir/algorithms.h"



// arr on heap
const unsigned GSIZE = 2000;
unsigned sTime;

void startTimer() { sTime = clock(); }
void stopTimer() { std::cout << std::setprecision(7) << (float)(clock() - sTime) / CLOCKS_PER_SEC << "\n"; }

void printArr(int* a, const unsigned sz){
	for(int i = 0; i < sz; i++)
		std::cout << a[i] << ' ';
}

int main(){
	srand(time(NULL));

	for(int x = GSIZE; x <= GSIZE * 5; x += 1000){ // getting more samples
		int* A = new int[x];
		int* B = new int[x];
//		for(int i = 0; i < x; i++){
//                 A[i] = rand() % 100 + 1;
//                 B[i] = A[i];
//       }
		for(int i = 0; i < x; i++){
			A[i] = i;
			B[i] = i;
		}
		std::cout << x << std::endl;

		std::cout << "quick" << std::endl;
		startTimer();
		quickSort(A, 0, x);
		stopTimer();


		std::cout << "selection" << std::endl;
		startTimer();
		selectionSort(B, x);
		stopTimer();

		// printArr(A, x);
		// printArr(B, x);
		delete[] A;
		delete[] B;
	}
	return 0;
}





