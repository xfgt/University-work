#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>


// algorithms

#include "D:\Documents\Personel\University\entry\323\AlgorithmsDir\algorithms.h"



// arr on heap
const unsigned GSIZE = 10000;
unsigned sTime;

void startTimer() { sTime = clock(); }
void stopTimer() { std::cout << std::setprecision(7) << "\n[" << (double)(clock() - sTime) / CLOCKS_PER_SEC << " s." << ']' << std::endl; }

void printArr(int* a, const unsigned sz){
	for(int i = 0; i < sz; i++)
		std::cout << a[i] << ' ';
}

int main(){
	srand(time(NULL));

	for(unsigned x = GSIZE; x <= GSIZE * 10; x += 1000){ // getting more samples
		int* A = new int[x];
		for(int i = 0; i < x; i++) A[i] = rand() % 100 + 1;
		std::cout << x << std::endl;
		startTimer();

        // put algorithm here.
		quickSort(A, 0, x);

		stopTimer();

		//printArr(A, x);
		delete[] A;
	}
	return 0;
}





