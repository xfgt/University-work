#include <iostream>
#include <fstream>
#include "A.h"
int main() {

//    A f;
    A g[MAX_SIZE];
//
//    A oa{ "", 0, 7.542 };
//    A ob{ "%", 1, 5.32 };
//    A oc{ "LONGERSTRINGER", 2, 153.6572 };
//
//
//    A j(oc);
//    A k = j;
//
//
////    std::cin >> f;
//    std::cout << f << std::endl;
//    std::cout << j << std::endl;
//    std::cout << oa << std::endl;
//    std::cout << ob << std::endl;
//    std::cout << "K\n" << k << std::endl;
//    std::cout << oc << std::endl;


	for (int i = 0; i < MAX_SIZE; i++)
		std::cin >> g[i];


	// writing
	std::fstream ofs;
	ofs.open("ofs.bin", std::ios::out | std::ios::binary);
	if (!ofs) {
		std::cout << "Error creating file!\n"; return 1;
	}	
	for (int i = 0; i < MAX_SIZE; i++) {
		ofs.write(reinterpret_cast<char*>(&g[i]), sizeof(A));
	}
	ofs.close();


	// reading
	std::fstream ifs;
	ifs.open("ofs.bin", std::ios::in | std::ios::binary);
	if (!ifs) {
		std::cout << "Error reading file!\n"; return 1;
	}
	A temp[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		ofs.read(reinterpret_cast<char*>(&temp[i]), sizeof(A));
	}
	ofs.close();


	for (A& h : temp)
		std::cout << h << std::endl;






	return 0;
}