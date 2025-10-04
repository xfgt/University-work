
#include <iostream>
#include <fstream>


int main(){



	int b[7];

	std::fstream fs;
	fs.open("file.bin", std::ios::in | std::ios::binary);


	if(!fs){
		std::cout << "Error opening file!\n"; return 1;
	}

	fs.read(reinterpret_cast<char*>(b), sizeof(b));
	fs.close();

	for(const auto& i : b)
		std::cout << i << ' ';
	std::cout << std::endl;


	return 0;
}
