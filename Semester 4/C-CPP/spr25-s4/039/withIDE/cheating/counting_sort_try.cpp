#if 0
#include <iostream>
#include <cstdlib>

#define N 11

void printArray(const char* text, int* arr, int n){
	std::cout << text << (char) 32;
	std::cout << '[';
	for(int i = 0; i < n; i++){
		std::cout << arr[i] << ' ';
	}
	std::cout << ']';
	std::cout << '\n';
}

void initArrayRands(int* arr, int n, int min, int max) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		arr[i] = min + rand() / (RAND_MAX / (max - min + 1) + 1);
	}
}

int main(){
	
	int a[N];
	initArrayRands(a, N, 0, 10);

	int b[N]{};
	int c[N];
	printArray("a:", a, N);
	printArray("b:", b, N);
	printArray("c:", c, N);
	std::cout << "begin procedures...\n";


	for(int i = 0; i < N; i++){ // correnction: start from 1
		++b[   a[i]   ];		// c[a[j]] <- c[a[j]] + 1
		//b[a[i]] = b[a[i]] + 1;
	}
	printArray("a: ",a,N);
	printArray("Step 1: (b) ",b,N);



	for(int i = 0; i < N-1; i++){ // correction: start from 1, end to N
		b[i+1] += b[i];			// c[i] <- c[i] + c[i-1]
		//b[i] = b[i] + b[i - 1];
	}
	printArray("Step 2: (b)", b, N);




	for(int i = N-1; i >= 0; i--){ // correction: start from N, end to 1
		
		c[b[a[i]]] = a[i];		// b[c[a[j]]] <- a[j]
		
								// c[a[j]] <- c[a[j]] - 1

		/*b[c[a[i]]] = a[i];
		c[a[i]] = c[a[i]] - 1;*/
	}
	printArray("A: ", a, N);
	printArray("B: ", b, N);
	printArray("Step 3: ", c, N);
	
}
#endif