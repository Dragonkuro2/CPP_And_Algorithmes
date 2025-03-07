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

stDate DecreaseOneYear(stDate date) {
	date.year--;
	if ((date.month == 2) && (date.day > GetMonthDays(date.year, date.month)))
		date.day = 28;

	return date;
}

stDate DecreaseXYear(stDate date, int NumberOfYearsToDecrease) {
	if (NumberOfYearsToDecrease > 0) {
		for (int i = 0; i < NumberOfYearsToDecrease; i++) {
			date = DecreaseOneYear(date);
		}
	}

	return date;
}

stDate DecreaseOneDecade(stDate date) {
	// we'll decrease 10 years that mean a decade.
	return DecreaseXYear(date, 10);
}

stDate DecreaseXDecade(stDate date, int NumberOfDecades) {
	if (NumberOfDecades > 0) {
		for (int i = 0; i < NumberOfDecades; i++) {
			date = DecreaseOneDecade(date);
		}
	}

	return date;
}

void PrintDate(string message, stDate date) {
	cout << message << ": " << date.day << "/" << date.month << "/" << date.year << endl;
}

int main() {
	stDate date;
	int NumberOfDecadesToDecrease;

	date = ReadDate("Enter The Date: ");
	NumberOfDecadesToDecrease = ReadPositiveNumber("Enter the number of decades to decrease: ");
	date = DecreaseXDecade(date, NumberOfDecadesToDecrease);
	PrintDate("Date After Decreasing " + to_string(NumberOfDecadesToDecrease) + " Decade: ", date);
	
	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}