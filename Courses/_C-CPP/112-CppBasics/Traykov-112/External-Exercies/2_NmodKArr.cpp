#include <iostream>
using namespace std;



int main() {

	int n{}, k{};


	std::cin >> n >> k;



	

	int x{}, sum{};
	for(int i = 0; i < n; i++){
	
		std::cin >> x;
		if (x % k == 0)
			sum += x;
	
	}


	cout << sum << '\n';
	



	return 0;
}