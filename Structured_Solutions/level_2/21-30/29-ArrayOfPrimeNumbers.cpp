#include <iostream>
#include <cstdlib>
#include <cmath>

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

void GenerateRandomTable(int array[MAX_SIZE], int &length) {
	length = ReadPositiveNumber("Enter the size of the array: ");
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

bool IsPrimeNumber(int number) {
	if (number <= 1)
		return false;
	for (int i = 2; i < sqrt(number); i++) {
		if ((number % i) == 0)
			return false;
	}

	return true;
}

void CopyOnlyPrimeNumbers(int Array1[MAX_SIZE], int length, int Array2[MAX_SIZE], int &length2) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (IsPrimeNumber(Array1[i])) {
			Array2[counter] = Array1[i];
			counter++;
		}
	}
	length2 = --counter;
}

int main() {
	int array[MAX_SIZE],SecondArray[MAX_SIZE], length, length2;
	srand((unsigned)time(NULL));

	GenerateRandomTable(array, length);
	PrintTable(array, length);

	CopyOnlyPrimeNumbers(array, length, SecondArray, length2);
	cout << "the second array after copying only prime numbers: " << endl;
	
	PrintTable(SecondArray, length2);
	return 0;
}