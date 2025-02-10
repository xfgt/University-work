#include <iostream>
#include <fstream>
#include <string>



int main(){

	std::string name{};
	std::cout << "file name: "; std::cin >> name;
	
	std::ifstream ifs;
	ifs.open(name);

	if(!ifs){
		std::cout << "Couldn't open file. Run gdb to debug.\n"; return -1;
	}
	std::string line{};
	int ln {1};


	std::cout << "[====" << ln++ << "====] ";
	while(std::getline(ifs, line)){
	
		if(line == "")
			std::cout << "[===="<< ln++ << "====] ";

		std::cout << line << std::endl;

	}
	return 0;
}
