#include <iostream>


int findMax(int* a, int end){

	if(end > 0) return std::max(a[end], findMax(a, end-1));
	else return a[0];
}

int main(){
	
	
	int arr[] = {1, 7, 2, -8, 4, 6, 9, -2};
	std::cout << findMax(arr, (sizeof(arr) / sizeof(arr[0])-1)) << std::endl;

	return 0;
}
