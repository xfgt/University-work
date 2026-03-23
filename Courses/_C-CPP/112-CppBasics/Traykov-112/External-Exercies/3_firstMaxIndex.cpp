#include <iostream>
using namespace std;


int main() {

	int n{};


	std::cin >> n;

	int x{}, largest{}, index{};

	for (int i = 1; i < n; i++) {

		std::cin >> x;
		if (x > largest) {
			largest = x;
			index = i;
		}
			

	}

	cout << index << '\n';


	return 0;
}