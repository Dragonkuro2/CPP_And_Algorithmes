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

void SumOfTwoArrays(int array1[MAX_SIZE], int array2[MAX_SIZE], int array3[MAX_SIZE], int length) {
	for (int i = 0; i < length; i++) {
		array3[i] = array1[i] + array2[i];
	}
}

int main() {
	int array1[MAX_SIZE], array2[MAX_SIZE], array3[MAX_SIZE], length;
	srand((unsigned)time(NULL));

	length = ReadPositiveNumber("Enter the size of the array: ");

	GenerateRandomTable(array1, length);
	cout << "\nThe first array:" << endl;
	PrintTable(array1, length);
	
	GenerateRandomTable(array2, length);
	cout << "\nThe second array:" << endl;
	PrintTable(array2, length);

	SumOfTwoArrays(array1, array2, array3, length);
	cout << "\nThe sum of array1 and array2:" << endl;
	PrintTable(array3, length);
	return 0;
}