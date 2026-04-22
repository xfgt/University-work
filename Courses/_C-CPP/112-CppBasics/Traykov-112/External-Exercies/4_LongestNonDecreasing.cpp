#include <iostream>
using namespace std;


int main() {

	int n{};


	std::cin >> n;

	int x{};
	int* arr = new int[n];

	for (int i = 0; i < n; i++) {

		cin >> x;
		arr[i] = x;
	}

	// 8 
	// 1 2 2 -1 0 0 0 5

	int sum = 1;
	for (int i = 0; i < n; i++) {
		
		if (arr[i] <= arr[i + 1]) {
			sum++;
		}
		else {
			i++;
		}


	}
	
	cout << sum << endl;
	



	delete[] arr;
	


	return 0;
}