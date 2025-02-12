#include <iostream>
#include <cmath>

using namespace std;

enum enAnswer { No, Yes };

int const MAX_SIZE = 100;

int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << endl << message;
		cin >> number;
	} while (number < 0);
	return number;
}

int RandomNumberInRange(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void GenerateRandomArray(int array[MAX_SIZE], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = RandomNumberInRange(1, 100);
	}
}

void AddToArray(int array[MAX_SIZE], int& length, int value) {
	if (length < MAX_SIZE) {
		array[length] = value;
		length++;
	}
	else
		cout << "The array is full" << endl;
}

void PrintArray(int array[MAX_SIZE], int length) {
	cout << "Array length: " << length << endl;
	cout << "Array elements: ";
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

bool IsPrimeNumber(int number) {
	if (number <= 1)
		return false;
	for (int i = 2; i <= sqrt(number); i++) {
		if (number % i == 0)
			return false;
	}

	return true; // if you reach here that's mean that number is a prime number
}

void CopyPrimeNumbersToArray(int array1[MAX_SIZE], int length, int array2[MAX_SIZE], int &length2) {
	for (int i = 0; i < length; i++) {
		if (IsPrimeNumber(array1[i]))
			AddToArray(array2, length2, array1[i]);
	}
}

int main() {
	int array1[MAX_SIZE], array2[MAX_SIZE], length = 0, length2 = 0;

	length = ReadPositiveNumber("Enter the size of the array: ");
	GenerateRandomArray(array1, length);
	PrintArray(array1, length);

	CopyPrimeNumbersToArray(array1, length, array2, length2);
	cout << "The array 2 after copying all prime numbers: " << endl;
	PrintArray(array2, length2);

	return 0;
}