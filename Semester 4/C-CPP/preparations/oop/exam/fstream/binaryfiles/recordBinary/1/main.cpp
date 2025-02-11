
#include <iostream>
#include <fstream>



struct Record{

	char name[40];
	unsigned short age;
	float gp;
};



int main(){

	
	Record records[3] {{"Jeff", 16, 2.3}, {"Melony", 18, 5.2}, {"HansDerFlammenWefer", 20, 5.95}};

//	Writing
	std::fstream f("records.bin", std::ios::out | std::ios::binary);
	if(!f){
		std::cout << "Error!\n"; return 1;
	}
	f.write(reinterpret_cast<char*>(records), 3* sizeof(Record));
	f.close();


	
	
//	reading
	std::fstream ofs("records.bin", std::ios::in | std::ios::binary);
	if(!ofs){
		std::cout << "Error!\n"; return 1;
	}


	Record rsr[3];
	ofs.read(reinterpret_cast<char*>(rsr), 3 * sizeof(Record));
	ofs.close();

	for(Record& p : rsr ){
		
		std::cout << p.name << std::endl;
		std::cout << p.age << std::endl;
		std::cout << p.gp << std::endl;

	}

		




	return 0;
}

