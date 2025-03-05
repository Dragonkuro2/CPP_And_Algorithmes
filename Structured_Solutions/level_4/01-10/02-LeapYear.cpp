#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber(string message) {
	int number;
	cout << message;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!" << endl;
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
			cout << "\nEnter a positive number! please try again.\n" << endl;
	} while (number < 0);
	return number;
}

bool IsLeapYear(int year) {
	if (year % 400 == 0)
		return true;
	else {
		if ((year % 4 == 0) && (year % 100 != 0))
			return true;
		else
			return false;
	}
}

int main() {
	int Year = ReadPositiveNumber("Enter a positive number: ");

	if (IsLeapYear(Year))
		cout << "Yes, the year " << Year << " is a leap year." << endl;
	else
		cout << "No, the year " << Year << " isn't a leap year." << endl;

	return 0;
}