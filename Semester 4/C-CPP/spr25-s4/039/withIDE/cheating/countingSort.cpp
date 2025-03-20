#if 0

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>

using namespace std;

#define N 10

#if 0
	int a[N] = { 7, 9, 2, 2, 1, 9, 6, 10, 4, 8 };
	int b[N + 1]{};
	int c[N + 1];
#endif

#if 1
	int a[N];
	int b[N + 1]{}; // frequency array
	int c[N + 1];
#endif

void printArray(const char* text, int* arr, int start, int n, char open, char close) {
	if(text)
		std::cout << text << (char)32;

	std::cout << open << ' ';

		if (arr) {
			for (int i = start; i < n; i++) {
				std::cout << arr[i] << ' ';
			}
		}
		else {
			for (int i = start; i < n; i++) {
				std::cout << i << ' ';
			}
		}
	
	std::cout << close;
	std::cout << '\n';
}

void initArrayRands(int* arr, int n, int min, int max) {
	srand(time(0));
	for (int i = 0; i < n; i++) {
		arr[i] = min + rand() % max + 1;
	}
}

void counting_sort(int* a, int* b, int* c) {
	
	// step 1
	for (int i = 0; i < N; i++) {
		++b[a[i]];
	}
	printArray("number frequency:\t", b, 1, N + 1, '{', '}');
	

	// step 2
	for (int i = 1; i < N; i++) {
		b[i + 1] += b[i];
	}
	printArray("b[i+1] += b[i]:\t\t", b, 1, N + 1, '{', '}');
	

	// step 3 final
	for (int i = N-1; i >= 0; i--) {
		c[b[a[i]]] = a[i];
		b[a[i]]--;
	}
	printf("after the magic:\n c[b[a[i]]] = a[i];\n b[a[i]]--; \n");
	
}


void result() {
	printArray("*COUNTING SORT\n\n\nOriginal array:\t\t", a, 0, N, '{', '}');
	printArray("indexes:\t\t", nullptr, 0, N, '[', ']');
	std::cout << '\n';
	counting_sort(a, b, c);
	printArray("*Sorted array (C):\t", c, 1, (N + 1), '{', '}');
	printArray("\nindexes:\t\t", nullptr, 1, (N + 1), '[', ']');
}

int main() {

	
#if 0
	while (true) {
		initArrayRands(a, N, 0, N);
		result();
		this_thread::sleep_for(chrono::seconds(1));
	}
#endif


	for (int i = 0; i < 10; i++) {
		initArrayRands(a, N, 0, N);
		result();
	}

	
	
	return 0;
}



#endif