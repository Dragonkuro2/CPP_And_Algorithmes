#include <iostream>
#include <iomanip>
#include <ctime>

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

bool IsLastDayInMonth(stDate date) {
	int MonthDays = GetMonthDays(date.year, date.month);
	return MonthDays == date.day;
}

bool IsLastMonthInYear(int month) {
	return month == 12;
}

stDate IncreaseDate(stDate date) {
	if (IsLastDayInMonth(date)) {
		date.day = 1;
		if (IsLastMonthInYear(date.month)) {
			date.month = 1;
			date.year++;
		}
		else {
			date.month++;
		}
	}
	else {
		date.day++;
	}

	return date;
}

stDate IncreaseXDay(stDate date, int DaysToIncrease) {
	if (DaysToIncrease >= 0) { // check if the days to increase is a positve number
		for (int i = 0; i < DaysToIncrease; i++)
			date = IncreaseDate(date);
	}

	return date;
}

void PrintDate(string message, stDate date) {
	cout << message << ": " << date.day << "/" << date.month << "/" << date.year << endl;
}

int main() {
	stDate date;
	int DaysToIncrease;
	date = ReadDate("Enter The Date: ");
	DaysToIncrease = ReadPositiveNumber("Enter the number of days to add: ");
	date = IncreaseXDay(date, DaysToIncrease);
	PrintDate("Date After Adding X Days: ", date);
	
	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}