#include <iostream>
#include <cstring>


const size_t MAX_STR {50};

class Name{

	friend std::ostream& operator << (std::ostream&, Name&);
	friend std::istream& operator >> (std::istream&, Name&);

	char* fname{};
	char* lname{};

	public:
		
		Name() : fname(new char[MAX_STR]), lname(new char[MAX_STR]){}
		Name(const char* fn, const char* ln) : Name(){
			setFn(fn);
			setLn(ln);
		}

		~Name(){
			delete[] fname;
			delete[] lname;
		}

		Name(const Name& obj) : Name(obj.fname, obj.lname) {}
		Name& operator =(const Name& rhs) {
			setFn(rhs.fname);
			setLn(rhs.lname);
		}

		void setFn(const char* fn){
			std::snprintf(fname, MAX_STR, "%s", fn);
		}
		void setLn(const char* ln){
			std::snprintf(lname, MAX_STR, "%s", ln);
		}

		char* getFn()	{ return fname; }
		char* getLn()	{ return lname; }

};

std::ostream& operator << (std::ostream& out, Name& rhs){

	out << rhs.getFn() << ' ' << rhs.getLn() << std::endl;

	return out;

}
std::istream& operator >> (std::istream& in, Name& rhs){

	char bufferfn[100], bufferln[100];
	in.getline(bufferfn, 100);
	rhs.setFn(bufferfn);
	in.getline(bufferln, 100);
	rhs.setLn(bufferln);
	return in;

}



int main(){

	Name n;
	std::cout << n << std::endl;
	std::cin >> n;
	std::cout << n << std::endl;


	Name names[3];
	std::cout << "Names:\n";
	for(int i = 0; i < 3; i++){
		std::cin >> names[i];
		std::cout << names[i] << std::endl;
	}


	Name otherNames[3] {{"Hristo", "Semerdzhyev"}, {"Robert", "Sams"}, {"Ghazali", "Al-Muqaddas Al-Safa"}};

	std::cout << "Other names\n";
	for(int i = 0; i < 3; i++){
		std::cout << otherNames[i] << std::endl;
	}

	Name thirdOption[3](names);

	for(int i = 0; i < 3; i++)
		otherNames[i] = names[i];

	std::cout << "Other names after copy\n";
	for(int i = 0; i < 3; i++){
		std::cout << otherNames[i] << std::endl;
	}

	std::cout << "Third option\n";
	for(int i = 0; i < 3; i++){
		std::cout << thirdOption[i] << std::endl;
	}






	return 0;
}
