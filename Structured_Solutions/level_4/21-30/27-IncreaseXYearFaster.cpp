#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

struct stDate {
	int year;
	int month;
	int day;
};

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

stDate ReadDate(string message) {
	stDate date;
	cout << message << endl;
	date.year = ReadYear();
	date.month = ReadMonth();
	date.day = ReadDay(date.year, date.month);
	return date;
}

stDate IncreaseOneYear(stDate date) {
	date.year++;
	// check if we are in feb because it'll be a problem if we didn't handel that case
	if ((date.month == 2) && (date.day == 29) && (!IsLeapYear(date.year)))
		date.day = 28;

	return date;
}

stDate IncreaseXYearFaster(stDate date, int NumberOfYearsToAdd) {
	date.year += NumberOfYearsToAdd;
	// check if we are in feb because it'll be a problem if we didn't handel that case
	if ((date.month == 2) && (date.day == 29) && (!IsLeapYear(date.year)))
		date.day = 28;

	return date;
}

void PrintDate(string message, stDate date) {
	cout << message << ": " << date.day << "/" << date.month << "/" << date.year << endl;
}

int main() {
	stDate date;
	int NumberOfYearsToAdd;

	date = ReadDate("Enter The Date: ");
	NumberOfYearsToAdd = ReadPositiveNumber("Enter the number of years to add: ");
	date = IncreaseXYearFaster(date, NumberOfYearsToAdd);
	PrintDate("Date After Adding " + to_string(NumberOfYearsToAdd) + " Year: ", date);
	
	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}