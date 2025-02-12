#include <iostream>
#include <cstdlib>

using namespace std;

int const MAX_SIZE = 10;

int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number < 0);
	return number;
}

int RandomNumberInRange(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillArray(int array[MAX_SIZE], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = RandomNumberInRange(1, 100);
	}
}

void PrintArray(int array[MAX_SIZE], int length) {
	cout << "Array length: " << length << endl;
	cout << "Array elements: ";
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

bool IsOddNumber(int number) {
	return number % 2 != 0;
}

int OddNumberCounter(int array[MAX_SIZE], int length) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (IsOddNumber(array[i]))
			counter++;
	}
	return counter;
}

int main() {
	int array1[MAX_SIZE], length = 0;

	srand((unsigned)time(NULL));

	length = ReadPositiveNumber("Enter the size of the array: ");
	FillArray(array1, length);
	PrintArray(array1, length);

	cout << "We have " << OddNumberCounter(array1, length) << " Odd number." << endl;

	return 0;
}