

#include <iostream>
#include <cstring>


int  main(){
	

	char* x = new char;

	std::cout << strlen(x) << std::endl;
	delete x;
	std::cout << strlen(x) << std::endl;
	x = new char [3];

	std::cout << strlen(x) << std::endl;
	delete [] x;


	x = new char[10];
	memset(x, 'f', 10);

	std::cout << strlen(x) << std::endl;
	delete [] x;

	std::cout << strlen(x) << std::endl;
	return 0;
}
