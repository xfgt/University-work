#include "headers/manageArray.h"
#include <iostream>
#include <iomanip>
#include <cstring>



void print_int_Array(int* arr, const int n) {
	for (int i = 0; i < n; i++)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

void print_int_Array_reversed(int* arr, const int n) {
	for (int i = n-1; i >= 0; i--)
		std::cout << arr[i] << ' ';
	std::cout << std::endl;
}

