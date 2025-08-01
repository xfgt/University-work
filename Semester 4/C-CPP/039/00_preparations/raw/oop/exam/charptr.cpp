
#include <iostream>
#include <string.h>

char* function(char* e){
	return e;
}



int main(){
	
	const char* a = "const char* string\0"; // doesn't compile when variable is passed as an argument 
	char charr[] = "chararraay string";		// compiles!
	char* chptr = new char;					// compiles!
//	char** doubleChar = "char** string";	doesn't compile (cannot convert char** to const char*)

	char* emptyChptr;						// compiles!; 8 bytes by default on my machine!
	
	emptyChptr = new char[5];
	strcpy(emptyChptr, "asdf\0");			// compiles!
	

//	emptyChptr = " asdf";					C++ ISO forbits..




										// does not allow
			char* t = function(charr); 		// const char* (variable or raw)
											// char**

										// allows
											// char[]
											// char*

	std::cout << t << std::endl;	
	std::cout << &t << std::endl;	
	std::cout << sizeof(t) << std::endl;
	std::cout << emptyChptr << std::endl;	
	std::cout << &emptyChptr << std::endl;	
	std::cout << sizeof(emptyChptr) << std::endl;

	delete[] emptyChptr;


	emptyChptr = new char[6];
	strcpy(emptyChptr, "hello\0");

	std::cout << t << std::endl;	
	std::cout << &t << std::endl;	
	std::cout << sizeof(t) << std::endl;
	std::cout << emptyChptr << std::endl;	
	std::cout << &emptyChptr << std::endl;	
	std::cout << sizeof(emptyChptr) << std::endl;





	delete chptr;
	delete[] emptyChptr;
	return 0;
}
