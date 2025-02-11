#include <iostream>
#include <fstream>
#include <cstring>
#include <string>




class H{

	friend std::ostream& operator << (std::ostream&, H&);
	friend std::istream& operator >> (std::istream&, H&);
	

	private:

		char* a;
		int b;
		float c;


	public:

		H(){
			a = nullptr;
			b = 0;
			c = 0.f;
		}

//		~H(){
//			if(a != nullptr && strlen(a) != 0){
//					delete[] a;
//			}
//		}

		void  seta (char* q){
			if(a != nullptr){
				delete[] a;
			}
					
			a = new char[10+1];
			if(strlen(q) > 10){	
				strncpy(a, q, 10);
			}	
			else{
				strcpy(a, q);
			}

		}
		char* geta() { return a; }


		void setb(int w) { b = w; }
		int getb() 	{ return b; }

		void setc(float e) { c = e; }
		float getc() 	{ return c;}



};


std::ostream& operator << (std::ostream& out , H& obj){
	out << obj.geta() << std::endl
		<< obj.getb() << std::endl
		<< obj.getc() << std::endl;


	return out;
}
std::istream& operator >> (std::istream& in, H& obj){


	char x[100];
	in >> x;
	obj.seta(x);

	in.clear();
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
	in >> obj.b >> obj.c;

	return in;
}
	


void writeToBinFile(std::string name, H* objArr, int size){
	
	std::fstream ofs;
	ofs.open(name, std::ios::out | std::ios::binary);
	
	if(!ofs){
		std::cout << "Error creating file!\n"; return;
	}
		


	ofs.write(reinterpret_cast<char*>(objArr), size * sizeof(H));
	ofs.close();
}

void readBinFile(std::string name, int size){
	
	std::fstream ifs(name, std::ios::in | std::ios::binary);
	if(!ifs){
		std::cout << "Error opening file!\n"; return;
	}
	
	H h[size];
	ifs.read(reinterpret_cast<char*>(h), size * sizeof(H));
	ifs.close();

	for(H& g : h)
		std::cout << g << std::endl;
}



int main(){
		
	const int NUMBER_OBJECTS = 5;


	H h[NUMBER_OBJECTS];

	for(int i = 0; i < NUMBER_OBJECTS; i++)
		std::cin >> h[i];
	

	writeToBinFile("output.bin", h, NUMBER_OBJECTS);

	readBinFile("output.bin", NUMBER_OBJECTS);
	
	return 0;
}
