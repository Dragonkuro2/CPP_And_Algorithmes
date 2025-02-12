#include <iostream>
#include <cstdlib>

using namespace std;

int const MAX_SIZE = 100;

int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << endl << message;
		cin >> number;
	} while (number <= 0);
	return number;
}

int RnadomNumberInRange(int From, int To) {
	return rand() % (To - From + 1) + From;
}

char GenerateRandomCharater() {
	return (char)RnadomNumberInRange(65, 90);
}

string GenerateWord(int length) {
	string word = "";
	for (int i = 0; i < length; i++) {
		word += GenerateRandomCharater();
	}

	return word;
}

string GenerateKey() {
	string key = "";
	key += GenerateWord(4) + "-";
	key += GenerateWord(4) + "-";
	key += GenerateWord(4) + "-";
	key += GenerateWord(4);

	return key;
}

void GenerateRandomKeys(string array[MAX_SIZE], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = GenerateKey();
	}
}

void PrintTableKeys(string array[MAX_SIZE], int length) {
	for (int i = 0; i < length; i++) {
		cout << "Key [" << i + 1 << "] : " << array[i] << endl;
	}
	cout << endl;
}


int main() {
	int length;
	string array[MAX_SIZE];
	srand((unsigned)time(NULL));

	length = ReadPositiveNumber("How many keys do you want: ");

	GenerateRandomKeys(array, length);
	cout << "\nThe keys are:" << endl;
	PrintTableKeys(array, length);

	return 0;
}