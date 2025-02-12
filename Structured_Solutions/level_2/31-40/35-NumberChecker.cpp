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

void GenerateRandomTable(int array[MAX_SIZE], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = RnadomNumberInRange(1, 100);
	}
}

void PrintTable(int array[MAX_SIZE], int length) {
	cout << "Array elements: ";
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int GetIndex(int array[MAX_SIZE], int length, int searched) {
	for (int i = 0; i < length; i++) {
		if (array[i] == searched)
			return i;
	}
	return -1;
}

bool IsNumberInArray(int array[MAX_SIZE], int length, int searched) {
	return (GetIndex(array, length, searched) != -1);
}

void CheckNumber(int array[MAX_SIZE], int length, int searched) {
	cout << "The number you are looking for: " << searched << endl;
	if (IsNumberInArray(array, length, searched)) {
		cout << "Yes, the number is found (:" << endl;
	}
	else
		cout << "No, The number isn't found :(" << endl;
}

int main() {
	int array[MAX_SIZE], length, searched;
	srand((unsigned)time(NULL));

	length = ReadPositiveNumber("Enter the size of the array: ");
	GenerateRandomTable(array, length);

	cout << "\nThe elements of the array: " << endl;
	PrintTable(array, length);
	searched = ReadPositiveNumber("Enter the number you are looking for: ");
	CheckNumber(array, length, searched);

	return 0;
}