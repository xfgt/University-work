#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char** argv){

	std::ofstream ofs;
	ofs.open("ofs_output_file", std::ofstream::app);
	if(!ofs)
		std::cout << "File wasn't created!\n";
	std::cout << "File created successfully! :)\n";
	
	ofs << "hello there! I come from std::ofstream! He told me to stay here! :D" << std::endl;
	ofs << 42 << " " << 0.2389817 << std::endl;


	std::cout << "Press enter to proceed the reading procedure\n";
	getchar();

	std::ifstream ifs;
	ifs.open("ofs_output_file");
	if(!ifs)
		std::cout << "File can't be opened! There some error messing up something! Run gdb on ./<binary>\n";
	std::string line{};
	while(std::getline(ifs, line))
			std::cout << line << std::endl;






	return 0;
}
