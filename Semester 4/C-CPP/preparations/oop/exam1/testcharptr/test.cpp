

#include <iostream>
#include <cstring> 
char* n;
char* hold;



void setn(char* h){

	if(n != nullptr) delete[] n;

	n = new char[std::strlen(h)+1];
	strcpy(n, h);
}




int main(){

	
	hold = new char[20];
	strcpy(hold, "asdfiugbfpa");

	setn(hold);
	
	std::cout << n << std::endl;
	std::cout << hold << std::endl;


	delete[] n;
	delete[] hold;

		
	return 0;
}
