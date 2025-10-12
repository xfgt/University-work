#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Person{
	int id;
	char name[16];
	int age;
	double weight;
};

void fillFileWithPersons(ofstream & f){
	Person p={0, " ", 0, 0.};
	for(int i=0; i<150; i++){
		f.write(reinterpret_cast<const char *>(&p), sizeof(Person)); // първо се записват всички байтове от празни обекти със съръзмерността на типа (Person)
	}
}

void modifyFileWithPersons(fstream & f){ // презаписва се сектор по избор на потребителя
	cout << "Enter person number from 1 to 150 and 0 for end.\n";
	Person p;
	cin >> p.id;
	while(p.id >=1 && p.id <=150){
		cout << "Enter name, age, weight.\n";
		cin >> p.name >> p.age >> p.weight;
		f.seekp((p.id-1)*sizeof(Person));
		f.write(reinterpret_cast<const char*>(&p), sizeof(Person));
		cout << "Enter person's number\n?";
		cin >> p.id;
	}
}

void outLine(ostream & f, const Person & p){
	f << left << setw(10) << p.id
	  << setw(16) << p.name
	  << setw(10) << p.age
	  << setw(10) << right << setprecision(2) << fixed << showpoint << p.weight << endl;
}

void writeFile(fstream & f){
	cout << left << setw(10) << "ID"
	  << setw(16) << "Name"
	  << setw(10) << "Age"
	  << setw(10) << right << "Weight" << endl;
	Person p;
	f.seekg(0);
	f.read(reinterpret_cast<char*>(&p), sizeof(Person));
	while(!f.eof()){
		if(p.id != 0){
			outLine(cout, p);
		}
		f.read(reinterpret_cast<char*>(&p), sizeof(Person));
	}
	f.close();
}

int main(){
	ofstream file;
	fstream file2;

//	Закоментирай блока, само ако искаш да редактираш файла. Иначе ще се загуби
	{
		file.open("fill_persons.dat", ios::out); // може да промениш начина на четене.
		if(!file){
			cerr << "File could not be opened!\n";
			return 1;
		}
		fillFileWithPersons(file);
	} // когато излезе от обхват, автоматично прави file.close();

	std::cout << "Reading now?...";
	std::cin.get();


	{
		file2.open("fill_persons.dat", ios::in | ios::out | ios::binary);
		if(!file2){
			cerr << "File could not be opened!\n";
			return 1;
		}
		modifyFileWithPersons(file2);
		writeFile(file2);
	} // автоматично file2.close();

	return 0;
}
