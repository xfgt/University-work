#include <iostream>
#include <iomanip>
#include <string>

int main(){

	int t, strs;
	std::cin >> t;
	while (t--){
		std::cin >> strs;
		std::cin.ignore();

		std::string str{}; // test string
		std::getline(std::cin, str);

		while(strs--){
			std::string sample{};
			std::getline(std::cin, sample);

			if(str[0] == sample[0] && str[str.size()-1] == sample[sample.size()-1])
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}

	return 0;
}
