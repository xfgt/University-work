

#include "./src/Stoka.h"
#include <iostream>
#include <fstream>



int main(){
 
 	Stoka s[5];
 	for(int i = 0; i < 5; i++)
 		std::cin >> s[i];
 	

	std::ofstream ofs;
	ofs.open("output"); 
	if(!ofs){
		std::cout << "File wasn't created!"; return -1;
	}

	for(int i = 0; i < 5; i++)
		ofs << s[i] << std::endl;
 	
 	
	return 0;
}
