#include "headers/manageArray.h"
#include <iostream>
using namespace std;



int main() {
	
	int n = {};

	std::cin >> n;

	if (n < 1 || n > 1000)
		return 0;
	
	int* arr = new int[n];

	int x{};
	for (int i = 0; i < n; i++) {
		std::cin >> x;
		arr[i] = x;
	}
	print_int_Array_reversed(arr, n);



	delete[] arr;


	return 0;
}