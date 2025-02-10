

#include "./src/Stoka.h"
#include <iostream>



int main(){

	Stoka s[5];
	for(int i = 0; i < 5; i++){
		std::cin >> s[i];
	}
	// todo read form file
	for(int i = 0; i < 5; i++){
		std::cout << s[i] << std::endl;
	}


	return 0;
}
