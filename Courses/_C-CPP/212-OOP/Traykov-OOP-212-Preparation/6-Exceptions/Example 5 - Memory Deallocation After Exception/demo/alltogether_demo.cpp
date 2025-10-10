//
// Created by ADMIN on 07-Oct-25.
//

#include <iostream>
#include <string.h>

using namespace std;

class Animal{
    public:
        Animal(const char * nm = "Animal")throw(int){
            animal_num = i++;

            memset(name, 0, sz);
            strncpy(name, nm, sz - 1);

            cout << "constructing Animal " << animal_num
                 << " name [" << name << "]" << endl;

            if(animal_num == 5)
                throw int(5);

            if(*nm == 'z')
                throw char('z');
        }

        ~Animal()
        {
            cout << "Destructing Animal " << animal_num
                 << " name [" << name << "]" << endl;
        }

        void* operator new[](size_t sz)
        {
            cout << "Animal::new[]" << endl;
            return ::new char[sz];
        }

        void operator delete[](void* p)
        {
            cout << "Animal::delete[]" << endl;
            ::delete []p;
        }
    protected:
        static int i;
        int animal_num;
        static const int sz = 40;
        char name[sz];
};
int Animal::i = 0;

class Cat : public Animal
{
    public:
        Cat(const char * nm = "Cat")throw(int) : Animal(nm) {
            cout << "Constructing Cat " << endl;
        }

        ~Cat()
        {
            cout << "Destructing Cat " << animal_num
                 << " name [" << name << "]" << endl;
        }

        void* operator new[](size_t sz)
        {
            cout << "Cat::new[]" << endl;
            return ::new char[sz];
        }

        void operator delete[](void* p)
        {
            cout << "Cat::delete[]" << endl;
            ::delete []p;
        }
};

class Dog:public Animal
{
    public:
        Dog(const char * nm = "Dog")throw(int):Animal(nm){
            cout << "Constructing Dog " << endl;
        }

        ~Dog()
        {
            cout << "Destructing Dog "
                 << animal_num << " name [" << name << "]" << endl;
        }

        void* operator new[](size_t sz)
        {
            cout << "Dog::new[]" << endl;
            return ::new char[sz];
        }

        void operator delete[](void* p)
        {
            cout << "Dog::delete[]" << endl;
            ::delete []p;
        }
};

void unexpexted_rethrow(){
	cout << "Unexpexted error occurred!!!" << endl;
	throw;
}

int main(){
	set_unexpected(unexpexted_rethrow);

	try{
		Animal n1("Animal before array");
		// Throws exception:
		Animal* arr = new Animal[7];
		Cat n2("Cat after array");
	}
	catch(int i){
		cout << "caught " << i << endl;
	}



	cout << "Testing unexpexted_rethrow"<< endl;

	try{
		Animal n3("Animal before unexpected");
		Cat n4("z");
		Dog n5("Dog after unexpected");
	}
	catch(char c){
		cout << "caught " << c << endl;
	}

	return 0;
}
