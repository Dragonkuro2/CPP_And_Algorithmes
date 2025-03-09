#include <iostream>
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

stDate IncreaseOneDay(stDate date) {
	date.day++;
	if (date.day > GetMonthDays(date.year, date.month)) {
		date.month++;
		date.day = 1;
	}

	if (date.month > 12) {
		date.year++;
		date.month = 1;
	}

	return date;
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
	return (date1.year > date2.year) || (date1.year == date2.year && (date1.month > date2.month || (date1.month == date2.month && date1.day > date2.day)));
}

enum enDateCompare { Before = -1, Equal = 0, After = 1 };

enDateCompare CompareTwoDates(stDate date1, stDate date2) {
	if (IsDate1AfterDate2(date1, date2))
		return enDateCompare::After;
	
	if (IsDate1EqualDate2(date1, date2))
		return enDateCompare::Equal;

	return enDateCompare::Before;
}

struct stPeroid {
	stDate StartDate;
	stDate EndDate;
};

stPeroid ReadPeroid(string message) {
	stPeroid period;
	cout << message << endl << endl;
	period.StartDate = ReadDate("Enter the start date: ");
	cout << endl;
	period.EndDate = ReadDate("Enter the end date: ");

	while (IsDate1AfterDate2(period.StartDate, period.EndDate)) {
		cout << "\nInvalid period! Try again.\n";
		cout << endl << message << endl;
		period.StartDate = ReadDate("Enter the first period: ");
		cout << endl;
		period.EndDate = ReadDate("Enter the second period: ");
	}

	return period;
}

bool IsDateInPeriod(stPeroid period, stDate date) {
	return ((CompareTwoDates(date, period.StartDate) == enDateCompare::After) &&
		(CompareTwoDates(date, period.EndDate) == enDateCompare::Before));
}

void PrintDate(string message, stDate date) {
	cout << message << ": " << date.day << "/" << date.month << "/" << date.year << endl;
}

int main() {
	stPeroid period;
	stDate date;

	period = ReadPeroid("\tPeriod info:");
	cout << endl;
	date = ReadDate("Enter a date: ");

	if (IsDateInPeriod(period, date)) {
		cout << "Yes, the date is within period.\n";
	}
	else
		cout << "No, the date isn't on period.\n";

	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}