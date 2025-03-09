#include <iostream>
#include <string>
#include <ctime>

#pragma warning(disable : 4996)

using namespace std;

struct stDate {
	int year;
	int month;
	int day;
};

const string Days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

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
	return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
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

// we used here the Gregorian calendar.
int GetDayOrder(stDate date) {
	int a = (14 - date.month) / 12;
	int y = date.year - a;
	int m = date.month + 12 * a - 2;
	int d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

bool IsDate1LessThanDate2(stDate date1, stDate date2) {
	if (date1.year != date2.year)
		return date1.year < date2.year;
	else if (date1.month != date2.month)
		return date1.month < date2.month;
	else
		return date1.day < date2.day;
}

bool IsDate1EqualDate2(stDate date1, stDate date2) {
	return ((date1.year == date2.year) && (date1.month == date2.month) && (date1.day == date2.day));
}

bool IsDate1AfterDate2(stDate date1, stDate date2) {
	return ((date1.year >= date2.year) && (date1.month >= date2.month) && (date1.day > date2.month));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareTwoDates(stDate date1, stDate date2) {
	if (IsDate1AfterDate2(date1, date2))
		return enDateCompare::After;
	
	if (IsDate1EqualDate2(date1, date2))
		return enDateCompare::Equal;

	return enDateCompare::Before;
}

void PrintDate(string message, stDate date) {
	cout << message << ": " << date.day << "/" << date.month << "/" << date.year << endl;
}

int main() {
	stDate date1, date2;
	date1 = ReadDate("Enter the first date: ");
	date2 = ReadDate("Enter the second date: ");
	
	cout << "Compare result: " << CompareTwoDates(date1, date2) << endl;

	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}