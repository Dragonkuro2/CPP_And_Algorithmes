#include <iostream>
#include <cmath>

using namespace std;

struct stMonth {
	int monthNumber;
	int days;
	int houres;
	int minutes;
	int seconds;
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

bool IsLeapYear(int year) {
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int NumberOfDaysInMonth(int year, int month) {
	if (month < 1 || month > 12)
		return 0;
	if (month == 2)
		return IsLeapYear(year) ? 29 : 28;
	int MonthsOf31Days[] = { 1, 3, 5, 7, 8, 10, 12 };
	for (int i = 0; i < 7; i++) {
		if (month == MonthsOf31Days[i])
			return 31;
	}
	return 30;
}

stMonth FillMonthInfo(int year, int monthNumber) {
	stMonth month;
	month.monthNumber = monthNumber;
	month.days = NumberOfDaysInMonth(year, monthNumber);
	month.houres = month.days * 24;
	month.minutes = month.houres * 60;
	month.seconds = month.minutes * 60;
	return month;
}


void PrintMonthInfo(stMonth month) {
	cout << "\n\t\tMonth [" << month.monthNumber << "] Info:" << endl;
	cout << "____________________________________________\n";
	cout << "Number of days in month    : " << month.days << endl;
	cout << "Number of houres in month  : " << month.houres << endl;
	cout << "Number of minutes in month : " << month.minutes << endl;
	cout << "Number of seconds in month : " << month.seconds << endl;
	cout << "____________________________________________\n";
}


int main() {
	int YearNumber = ReadPositiveNumber("Enter a year: ");
	int MonthNumber = ReadPositiveNumber("Enter a month to check: ");
	stMonth month = FillMonthInfo(YearNumber, MonthNumber);
	PrintMonthInfo(month);

	return 0;
}