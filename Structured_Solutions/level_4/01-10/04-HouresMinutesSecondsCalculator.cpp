#include <iostream>
#include <cmath>

using namespace std;

struct stYear {
	int yearNumber;
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

stYear FillYearInfo(int YearNumber) {
	stYear year;
	year.yearNumber = YearNumber;
	year.days = IsLeapYear(YearNumber) ? 366 : 365; // check if the year is a leap year or not
	year.houres = year.days * 24;
	year.minutes = year.houres * 60;
	year.seconds = year.minutes * 60;
	return year;
}

void PrintYearInfo(stYear year) {
	cout << "\n\t\tYear [" << year.yearNumber << "] Info:" << endl;
	cout << "____________________________________________\n";
	cout << "Number of days in year    : " << year.days << endl;
	cout << "Number of houres in year  : " << year.houres << endl;
	cout << "Number of minutes in year : " << year.minutes << endl;
	cout << "Number of seconds in year : " << year.seconds << endl;
	cout << "____________________________________________\n";
}

int main() {
	int YearNumber = ReadPositiveNumber("Enter a year: ");
	stYear year = FillYearInfo(YearNumber);
	PrintYearInfo(year);

	return 0;
}