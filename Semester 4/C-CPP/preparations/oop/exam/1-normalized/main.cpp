

#include "./src/Stoka.h"
#include <iostream>
#include <fstream>



int main(){
 
 	Stoka s[5];
	for(int i = 0; i < 5; i++)
		std::cin >> s[i];

	std::fstream ofs("ofs", std::ios::out | std::ios::binary);
	if(!ofs){
		std::cout << "Error creating file!\n"; return 1;
	}
	for(int i = 0; i < 5; i++){
		ofs.write(reinterpret_cast<char*>(&s[i]), sizeof(Stoka));
	}
	ofs.close();




	std::fstream ifs("ofs", std::ios::in | std::ios::binary);
	if(!ifs){
		std::cout << "Error opening file!\n"; return 1;
	}
	Stoka rs[5];
	
	for(int i = 0; i < 5; i++){
		ifs.read(reinterpret_cast<char*>(&rs[i]), sizeof(Stoka));
	}
	ifs.close();
	



	for(int i = 0; i < 5; i++){
		std::cout << '[' << i+1 << ".]\n" << rs[i] << std::endl;
	}
	return 0;
}
