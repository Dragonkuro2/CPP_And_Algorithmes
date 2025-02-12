#include <iostream>

using namespace std;

int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << endl << message;
		cin >> number;
	} while (number < 0);
	return number;
}

void ReadTable(int array[100], int &length) {
	length = ReadPositiveNumber("Enter the size of the array: ");
	for (int i = 0; i < length; i++) {
		cout << "Enter element [" << i + 1 << "] : ";
		cin >> array[i];
	}
}

void PrintTable(int array[100], int length) {
	cout << "Array elements: ";
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int FrequencyChecker(int array[100], int length, int searched) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] == searched)
			counter++;
	}

	return counter;
}

int main() {
	int array[100], length, searched;
	ReadTable(array, length);
	searched = ReadPositiveNumber("Enter the number you want to search for: ");
	PrintTable(array, length);
	cout << searched << " repeated " << FrequencyChecker(array, length, searched) << " time(s)." << endl;
	return 0;
}