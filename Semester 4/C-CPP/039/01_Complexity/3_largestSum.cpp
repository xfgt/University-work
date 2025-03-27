#include <iostream>
#include <algorithm>
int n, m{};

void fillArr(int* a, int n){
	int f = n, i{}, x{};
	while(f--){
		std::cin >> x;
		a[i++] = x;
	}
}

int largestNum(int* a, int n){

	int maxi{};
	for(int i = 1; i < n; i++){
		if(a[maxi] < a[i])
			maxi = i;
	}
	a[maxi] = -100000;
	return maxi;

}

int main(){

	std::cin >> n >> m;
	int a[n], b[n], indexes[m];

	fillArr(a, n);
	for(int i = 0; i < n; i++)		 b[i] = a[i]; // b = a
	
	for(int i = 0; i < m; i++)		indexes[i] = largestNum(a, n);

	std::sort(indexes, indexes + n-1); // program time depends on this.

	for(int i = 0; i < m; i++)		std::cout << b[indexes[i]] << ' ';


	return 0;
}
