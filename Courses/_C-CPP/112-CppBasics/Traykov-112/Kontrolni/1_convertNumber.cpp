//
// Created by LOCAL_ADMIN on 16-Mar-26.
//


#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;



void printArr(const int arr[], const int sz) {
	for (int i = 0; i < sz; i++)
		cout << arr[i];
	cout << '\n';
}
void printCArr(const char arr[], const int sz) {
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


int fromBinToDec(char num[]) {

	// const size = 6
	//32 16 8 4 2 1
	int sum{};
	int mul = 32;
	for (int i = 0; i < 6; i++) {

		if (mul != 0 && num[i] == '1') {
			sum += mul;
		}

		mul /= 2;
	}

	return sum;
}


double fromHexToDec(char num[]) {

	// const sz
	const int size = strlen(num);



	double sum{};
	double converted{};
	for (int i = size-1, j = 0; i >= 0; --i, j++) {


			switch (num[i]) {
				default:
					converted = num[i] - '0';
					sum += converted * pow(16, j);
					break;

				case 'A':
				case 'a':
					sum += (10 * pow(16, j));
					break;
				case 'B':
				case 'b':
					sum += (11 * pow(16, j));
					break;
				case 'C':
				case 'c':
					sum += (12 * pow(16, j));
					break;
				case 'D':
				case 'd':
					sum += (13 * pow(16, j));
					break;
				case 'E':
				case 'e':
					sum += (14 * pow(16, j));
					break;
				case 'F':
				case 'f':
					sum += (15 * pow(16, j));
					break;
			}


	}

	return sum;
}


void fromOctToBin(char num[]) {

	const int size = strlen(num)-1;

	int sum{};

	for (int i = 0, j = size; i <= size; i++, j--) {
		int converted = num[i] - '0';
		sum += converted * pow(8, j);

	}



	cout << sum << endl;
	toBinary(sum);
	//nakraq to binary nested
}

int main() {

	int n = 45;

	// reference
	cout << dec << n << endl;
	cout << oct << n << endl;
	cout << hex << n << endl;
	
	cout << endl;

	// toBinary(n);
	// toOct(n);
	// toHex(n);


	// 2. Преобразувайте числото 101101₂ в десетична бройна система. (2 т.)

	int a = fromBinToDec("111111");
	cout << dec <<  a << endl;




	// 3. Преобразувайте числото 2F₁₆ в десетична бройна система. (2 т.)
	a = fromHexToDec("2F"); // 2F, F2
	cout << dec << a << endl;

	a = fromHexToDec("F2"); // 2F, F2
	cout << dec << a << endl;

	double b = fromHexToDec("BABACECA"); // 2F, F2
	cout << dec << fixed << b << endl;


	// 4. Преобразувайте числото 57₈ в двоична бройна система. (3 т.)
	fromOctToBin("57");
	fromOctToBin("173");
	fromOctToBin("2162");


	return 0;
}
