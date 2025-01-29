#include <iostream>

using namespace std;

enum enNumberStatus { even, odd };

int ReadNumber() {
	int number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

enNumberStatus NumberChecker(int number) {
	if (number % 2 == 0)
		return enNumberStatus::even;
	else
		return enNumberStatus::odd;
}

void PrintStatus(enNumberStatus status) {
	if (status == enNumberStatus::even)
		cout << "Even Number." << endl;
	else
		cout << "Odd Number." << endl;
}

int main() { // program that checks if a number is odd or even.

	PrintStatus(NumberChecker(ReadNumber()));

	return 0;
}