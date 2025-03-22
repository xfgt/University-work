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

	std::fstream fout;
	unsigned short x = 1234;
	
	fout.open("file.bin", std::ios::out | std::ios::binary);
	if(!fout){
		std::cout << "Error opening file!\n"; return 1;
	}

	// we write to a binary file as follows:
	

	// char* memory address of x, sizeof(type)
	fout.write(reinterpret_cast<char*>(&x), sizeof(unsigned short));

	// gets sizeof(type) bytes
	// dump it into the file 
	// write x on top of it.


	fout.close();

	return 0;
}
