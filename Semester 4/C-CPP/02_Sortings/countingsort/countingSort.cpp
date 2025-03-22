
#include <iostream>


using namespace std;

#define N 10

	int a[N] = { 7, 9, 2, 2, 1, 9, 6, 10, 4, 8 };
	int b[N + 1]{};
	int c[N + 1];



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

	result();
	return 0;
}
