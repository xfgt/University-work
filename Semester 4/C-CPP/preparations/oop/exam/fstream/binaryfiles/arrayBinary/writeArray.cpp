

#include <iostream>
#include <fstream>



int main(){

	std::fstream fs;
	fs.open("file.bin", std::ios::out | std::ios::binary);
	if(!fs){
		std::cout << "Error opening file!\0"; return 1;
	}

	
	// we have this array that we wanna write into our binary file as raw data
	
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };

	// fs.write(starting address, number of bytes to write);
	
	//a[] is a*, so we need a and not &a
	fs.write(reinterpret_cast<char*>(a), sizeof(a));
	fs.close();


	return 0;
}
