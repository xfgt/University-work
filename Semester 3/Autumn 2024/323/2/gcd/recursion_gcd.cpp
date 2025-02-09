#include <iostream>

int res{};

void gcd(int a, int b){
	
	if(b != 0){
		res = a;

		std::cout << res << '\\';
		gcd(b, a % b);
		std::cout << b << '/';
	}

	//good 140 16
	// bad 2465%288

}




int main(){


	int a{}, b{};

	std::cin >> a >> b;

	gcd(a,b);
	std::cout << std::endl << "Result: " << res << std::endl;

	return 0;
}
