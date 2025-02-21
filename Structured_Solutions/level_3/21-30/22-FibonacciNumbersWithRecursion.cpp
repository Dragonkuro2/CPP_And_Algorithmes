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

void EndScreen() {
	cout << "\nPress Enter to continue...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignor any remaining characters in the input buffer
	cin.get(); // wait for the user to press Enter
}

void PrintFibonacciNumbers(int number, int prev1 = 0, int prev2 = 1) {
	int FiboNumber = 0;
	if (number > 0) {
		FiboNumber = prev1 + prev2;
		prev2 = prev1;
		prev1 = FiboNumber;
		cout << FiboNumber << "     ";

		PrintFibonacciNumbers(number - 1, prev1, prev2);
	}
}

int main() {
	int size;
	size = ReadPositiveNumber("How many of fibonacci numbers do you want: ");
	PrintFibonacciNumbers(size);

	EndScreen();

	return 0;
}