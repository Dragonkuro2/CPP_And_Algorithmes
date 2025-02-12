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

void ReadTable(int array[MAX_SIZE], int &length) {
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

int MaxOfArray(int array[MAX_SIZE], int length) {
	int max = array[0];
	for (int i = 0; i < length; i++) {
		if (array[i] > max)
			max = array[i];
	}

	return max;
}

int main() {
	int array[MAX_SIZE], length;
	srand((unsigned)time(NULL));

	ReadTable(array, length);
	PrintTable(array, length);
	cout << "the max of the array is: " << MaxOfArray(array, length) << endl;
	return 0;
}