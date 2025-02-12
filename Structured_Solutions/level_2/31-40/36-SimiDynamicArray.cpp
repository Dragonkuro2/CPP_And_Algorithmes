#include <iostream>

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

enAnswer GetAnswer() {
	short answer;
	cout << "Do you want to continue No[0] Yes[1]: ";
	do{
		cin >> answer;
		if (answer < 0 || answer > 1)
			cout << "Please enter a valid option: ";
	} while (answer < 0 || answer > 1);

	return (enAnswer)answer;
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

void FillArray(int array[MAX_SIZE], int &length) {
	int number = ReadPositiveNumber("Enter a positive number: ");
	AddToArray(array, length, number);

	while (GetAnswer() == enAnswer::Yes) {
		number = ReadPositiveNumber("Enter a positive number: ");
		AddToArray(array, length, number);
	}
}

int main() {
	int array[MAX_SIZE], length = 0;

	FillArray(array, length);
	PrintArray(array, length);

	return 0;
}