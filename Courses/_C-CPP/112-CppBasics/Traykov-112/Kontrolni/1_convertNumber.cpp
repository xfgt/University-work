#include <iostream>
#include <cmath>

using namespace std;







void printArr(const int arr[], const int sz) {
	for (int i = 0; i < sz; i++)
		cout << arr[i];
	cout << '\n';
}
void printArr(const char arr[], const int sz) {
	for (int i = 0; i < sz; i++)
		cout << arr[i];
	cout << '\n';
}
void toBinary(int n) {
	
	
	int binaryNum[7]{};
	int i = 0;
	while (n != 0) {

		binaryNum[i++] = (n % 2);
		n /= 2;

	}
	printArr(binaryNum, 7);
}

void toOct(int n) {
	int octNum[7]{};
	int i = 0;
	while (n != 0) {

		octNum[i++] = (n % 8);
		n /= 8;

	}

	printArr(octNum, 7);
}

void toHex(int n) {

	int i = 0;
	int pair[2]{};
	while (n != 0) {

		pair[i++] = (n % 16);
		n /= 16;

	}
	
	for (int i = 1; i >= 0; --i) {
		switch (pair[i]) {
			case 10:
				cout << 'A';
				break;
			case 11:
				cout << 'B';
				break;
			case 12:
				cout << 'C';
				break;
			case 13:
				cout << 'D';
				break;
			case 14:
				cout << 'E';
				break;
			case 15:
				cout << 'F';
				break;

			default:
				cout << pair[i];
				break;
		}
	}
	


}



int main() {

	int n = 45;

	// reference
	cout << dec << n << endl;
	cout << oct << n << endl;
	cout << hex << n << endl;
	
	cout << endl;
	// binary 101101
	
	
	toBinary(n);	
	toOct(n);
	toHex(n);


	// 2. Преобразувайте числото 101101₂ в десетична бройна система. (2 т.)
	// 3. Преобразувайте числото 2F₁₆ в десетична бройна система. (2 т.)
	// 4. Преобразувайте числото 57₈ в двоична бройна система. (3 т.)


	return 0;
}
