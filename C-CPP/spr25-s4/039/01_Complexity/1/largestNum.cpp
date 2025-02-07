#include <iostream>


int n, maxn{}, maxy{};

void fillArr(int* a, int n){
	int f = n, i{}, x{};
	while(f--){
		std::cin >> x;
		a[i++] = x;
	}
}

int largestNum(int* a, int n){

	int maxi{}, thebig;
	for(int i = 1; i < n; i++){
		if(a[maxi] < a[i])
			maxi = i;
	}
	thebig = a[maxi];
	a[maxi] = -100000;
	return thebig;

}

int main(){

	int n;
	std::cin >> n;
	
	int a[n];
	fillArr(a, n);

	maxn = largestNum(a, n);
	maxy = largestNum(a, n-1);

	if(maxn > maxy)
		printf("%d %d", maxn, maxy);
	else
		printf("%d %d", maxy, maxn);
	return 0;
}
