#include <iostream>
#include <iomanip>
#include <string>

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

int ReadNumberInRange(string message, int From, int To) {
	int number;
	do {
		number = ReadNumber(message);
		if (number < From || number > To)
			cout << "Invalid Input! Try Again.\n";
	} while (number < From || number > To);
	return number;
}

bool IsLeapYear(int year) {
	return (year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0);
}

int GetDayOrder(int year, int month, int day) {
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

int GetMonthDays(int year, int month) {
	if (month < 1 || month > 12)
		return 0;
	int MonthDays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? IsLeapYear(year) ? 29 : 28 : MonthDays[month - 1];
}

int ReadYear() {
	return ReadPositiveNumber("Enter a year: ");
}

int ReadMonth() {
	return ReadNumberInRange("Enter a month: ", 1, 12);
}

int ReadDay(int year, int month) { // limit the user to enter just the number of days in that month
	return ReadNumberInRange("Enter a day: ", 1, GetMonthDays(year, month));
}

string AddDaysToDate(int NumberOfDaysToAdd, int year, int month, int day) {
	int CurrentMonthDays;

	if (GetMonthDays(year, month) < NumberOfDaysToAdd) {
		NumberOfDaysToAdd -= (GetMonthDays(year, month) - day); // reduce the remaining days
		month++;
	}
	else
		NumberOfDaysToAdd += day;

	while (true) {
		CurrentMonthDays = GetMonthDays(year, month);
		if (CurrentMonthDays >= NumberOfDaysToAdd)
			break;
		else
			NumberOfDaysToAdd -= CurrentMonthDays;
		month++;

		if (month > 12) {
			year++;
			month = 1;
		}
	}
	string NextDate = to_string(NumberOfDaysToAdd) + "/" + to_string(month) + "/" + to_string(year);
	return NextDate;
}

int main() {
	int year = ReadYear();
	int month = ReadMonth();
	int day = ReadDay(year, month);
	int NumberOfDaysToAdd = ReadPositiveNumber("Enter the number of days to add: ");

	cout << "Date after adding [" << NumberOfDaysToAdd << "] is: " << AddDaysToDate(NumberOfDaysToAdd, year, month, day) << endl;

	cout << "Press Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}