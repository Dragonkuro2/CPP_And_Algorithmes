#include <iostream>
#include <iomanip>

using namespace std;

int ReadNumber(string message) {
	int number;
	cout << message;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!\n";
		cout << message;
		cin >> number;
	}

	return number;
}

int ReadPositiveNumber(string message) {
	int number;
	do {
		number = ReadNumber(message);
		if (number < 0)
			cout << "Please enter a positive number.\n";
	} while (number < 0);
	return number;
}

void PrintFibonacciNumbers(int size) {
	int fiboNumber = 0;
	int prev1 = 1, prev2 = 0;

	if (size == 0) { // if the user wants 0 number, I'll print nothing
		cout << "Nothing to print" << endl;
		return;
	}

	cout << setw(6) << prev2; // print the first number that is 0
	if (size > 1) // and if the user wants more than 1 number I'll print the first element that is 1
		cout << setw(6) << prev1;
	
	for (int i = 2; i < size; i++) {
		fiboNumber = prev1 + prev2;
		cout << setw(6) << fiboNumber;
		prev2 = prev1;
		prev1 = fiboNumber;
	}
}

void EndScreen() {
	cout << "\nPress Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignor any remaining characters in the input buffer
	cin.get(); // wait for the user to press Enter
}

int main() {
	int size;
	size = ReadPositiveNumber("How many of fibonacci numbers do you want: ");
	PrintFibonacciNumbers(size);

	EndScreen();

	return 0;
}