/*
 *
 *
 * 	When we write characters in a text file, we would need a byte for each character.
 *	The longer the sequence the longer the size of the file.
 *
 *
 *	If we have the number 1234, we would need 4*4 bytes for the number;
 * 
 *	If we try to store the same number as
 *	unsigned short we would need the sizeof(unsigned short) bytes, which is smaller than the ascii version.
 *
 *
 */


#include <iostream>
#include <fstream>




int main(){

	unsigned short x = 0;
	std::fstream fin;

	//						IN
	fin.open("file.bin", std::ios::in | std::ios::binary);
	if(!fin){
		std::cout << "Error opening file!\n"; return 1;
	}



	//			READ
	fin.read(reinterpret_cast<char*>(&x), sizeof(unsigned short));
	fin.close();

	std::cout << x << std::endl;

	return 0;
}
