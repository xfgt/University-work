#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

void throw_except(){
	throw logic_error("exception thrown here");
}

int main(){
	bool more = true;

	while(more){
		try{
			throw_except();
		}
		catch (logic_error & e){
			cout << "A logic error has occurred:" << e.what() << "\n" << "Retry?(y/n)";
			string input;
			getline(cin, input);
			if(input == "n") more = false;
		}
	}
	return 0;
}
