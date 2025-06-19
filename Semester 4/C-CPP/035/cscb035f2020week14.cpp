#include <iostream>

using namespace std;

bool inSet(char target, char* set, int power) {
	for (int i = 0; i < power; i++) {
		if (target == set[i]) {
			return true;
		}
	}
	return false;
}

int maxSequene(char* set, int setSize, char* inputString, int stringSize) {
	int maxSequentialCharacters = 0;
	int currentSequentialCharacters = 0;
	int j = 0;
	for (int i = 0; i < stringSize; i++) {
		if (inSet(inputString[i], set, setSize)) {
			currentSequentialCharacters++;
		}
		else {	
			currentSequentialCharacters = 0;
		}
		if (currentSequentialCharacters > maxSequentialCharacters) {
			maxSequentialCharacters = currentSequentialCharacters;
		}
	}
	return maxSequentialCharacters;
}

int maxElement(int* set, int setSize) {
	int max = set[0];
	for (int i = 1; i < setSize; i++) {
		if (max < set[i]) {
			max = set[i];
		}
	}
	return max;
}

int minElement(int* set, int setSize) {
	int min = set[0];
	for (int i = 1; i < setSize; i++) {
		if (min > set[i]) {
			min = set[i];
		}
	}
	return min;
}

int sumNumbers(int* set, int setSize, int min, int max) {
	int sum = 0;
	for (int i = 0; i < setSize; i++) {
		if (set[i] >= min && set[i] <= max) {
			sum += set[i];
		}
	}
	return sum;
}

bool isPrime(int number) {
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0) {
			return false;
		}
	}
	return true;
}

int minPrimeNumber(int bottom, int top) {
	if (bottom > top) {
		int temp = bottom;
		bottom = top;
		top = bottom;
	}
	for (int i = bottom; i <= top; i++) {
		if (isPrime(i)) {
			return i;
		}
	}
	return 0;
}

string codingWithPrimeNumbers(int bottom, int top, string message, int numberOfLetters) {
	int shiftNumber = minPrimeNumber(bottom, top) % numberOfLetters;
	string codedMessage = message;
	for (int i = 0; i < message.length(); i++) {
		if ((message[i] >= 65 && message[i] <= 90) || (message[i] >= 97 && message[i] <= 122)) {
			if ((message[i] >= 65 && message[i] <= 90 - shiftNumber) ||
				(message[i] >= 97 && message[i] <= 122 - shiftNumber)) {
				codedMessage[i] += shiftNumber;
			}
			else {
				codedMessage[i] -= (numberOfLetters - shiftNumber);
			}
		}
	}
	return codedMessage;
}


int main()
{
	/* ��� 1. ������ �� ��� ��������� set1 � set2. �� �� ������� �������, 
	����� ����� ������ �� ���������� � ������� ���������, 
	����� ����������� �� ���������� ��������
	����� ���-������ � ���-������� ������� �� ������� ���������.
	����:
	Set1: {5, 2, 3, 8, 1, 6, 4, 12, 9, 10}
	Set2: {6, 9, 4}
	�����:
	32 // ���������� 5, 8, 6, 4, 9 �� ������� ��������� ����������� �� ��������� [4, 9]
	*/

	int set1[] = { 5, 2, 3, 8, 1, 6, 4, 12, 9, 10 };
	int set2[] = { 6, 9, 4 };
	int min = minElement(set2, 3);
	int max = maxElement(set2, 3);
	cout << "Min elements: " << min << endl;
	cout << "Max elements: " << max << endl;
	cout << "Sum elements between " << min << " and " << max << ": " << sumNumbers(set1, 10, min, max) << endl;



	/* ��� 2. ������ �� ��������� �� ������� � �������� ���.
	�� �� ������ �������, ����� ����� ���� �� ��������� �
	���-������� ���������������� �� ������� � ���������
	���, ����� ����������� �� �����������.

	����:
	���������: { 'e', 't', 'i', 's' }
	�������� ��� : "This is one test string!"
	����� :
	4 // test � ���-������� ���������������� �� �������, 
	����� ����������� �� �����������*/

	int universalSetSize = 4;
	char universalSetOfCharacters[] = { 'e','t','i','s' };
	int size = 24;
	char charactersSet[] = "This is one test string!";
	cout << "The max sequence with set characters: " <<
		maxSequene(universalSetOfCharacters, universalSetSize, charactersSet, size) << endl;

	/* ��� 3.
	* �� �� ������� �������, ����� ������ ������ ��������� �� ������� �����.
	* � ���������� �������� ���� �������� � ������� �������� �����
	* �������� � ����������: ���-������� ������ ����� � ����� �������� �����
	* �� ��������� �� ���������� � �����. [30; 40] -> 31
	* ��� ������� � ��-�����o �� ���� �� ������� � ��������, �� �� �������� ��
	* ������� �����: [30; 40] -> 31 => ������������ � 5 ������� 31 % 26 = 5
	* A-Z, a-z
	*
	* A -> F, B -> G, C -> H, ..., Z -> E
	* a -> f, b -> g, c -> h, ..., z -> e
	*
	* ����:
		���������: bottom = 30, top = 40
		�������� ���: "This is one test string!"
    * �����:
	    ���������� ���: "Ymnx nx tsj yjxy xywnsl!"
	*/

	int bottom = 30;
	int top = 40;
	int numberOfLetters = 26;
	string message = "This is one test string!";
	string codedMessage = codingWithPrimeNumbers(bottom, top, message, numberOfLetters);
	cout << "codedMessage=" << codedMessage << endl;
}
