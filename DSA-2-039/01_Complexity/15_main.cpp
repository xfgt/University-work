#include <iostream>


void showInReverse(int* a, size_t sz){
	
	if(sz == 0){
		return;
	}
	std::cout << a[sz-1] << ' ';
	showInReverse(a, sz-1);
	


}


int main(){
	
	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	showInReverse(arr, sizeof(arr) / sizeof(arr[0]));

	return 0;
}
