
#include <iostream>
#include <fstream>



void writeArray(int* a, int size){ // can be included file name and it can be templated

	std::fstream fs ("file.bin", std::ios::out | std::ios::binary);
	fs.write(reinterpret_cast<char*>(a), size*sizeof(int));
	fs.close();

}

void readArray(int* a, int size){ // can be included file name and it can be templated

	std::fstream fs ("file.bin", std::ios::in | std::ios::binary);
	fs.read(reinterpret_cast<char*>(a), size*sizeof(int));
	fs.close();

}



int main(){

	int a[] = { 2, 3, 5, 7, 63 };
	writeArray(a, sizeof(a) / sizeof(a[0]));

	int b[sizeof(a) / sizeof(a[0])];
	readArray(b, sizeof(b) / sizeof(b[0]));

	for (const auto& x : b)
		std::cout << x << ' ';
	std::cout << std::endl;
	return 0;
}
