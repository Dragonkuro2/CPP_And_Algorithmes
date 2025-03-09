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

// In Morocco the end of the week is sunday that's why i used the order of the day 0
// because the gregorian calender return 0 for sunday
bool IsItEndOfWeek(stDate date) {
	int DayOrder = GetDayOrder(date);
	return DayOrder == 0;
}


// the weekend in Morocco on Saturday and Sunday
bool IsItWeekend(stDate date) {
	int DayOrder = GetDayOrder(date);
	// check if today is sunday or saturday
	return (DayOrder == 0) || (DayOrder == 6);
}

bool IsItBussinessDay(stDate date) {
	// if it's not the weekend that's mean we are on bussiness day
	return !IsItWeekend(date);
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

int VocationDays(stDate StartDate, stDate EndDate) {
	if (IsDate1LessThanDate2(StartDate, EndDate)) {
		int counter = 0;
		while (!IsDate1EqualDate2(StartDate, EndDate)) {
			if (IsItBussinessDay(StartDate)) // check if the current day is a bussiness day, then increament the vocation days
				counter++;
			StartDate = IncreaseOneDay(StartDate);
		}
		return counter;
	}
	else
		return -1; // return -1 if the date1 is bigger than the date2
}

stDate EndOfVocationDate(stDate StartDate, int NumberOfVocationDays) {
	int counter = 0;
	while (counter != NumberOfVocationDays) {
		if (IsItBussinessDay(StartDate))
			counter++;

		StartDate = IncreaseOneDay(StartDate);
	}

	return StartDate;
}

void PrintDate(string message, stDate date) {
	cout << message << ": " << date.day << "/" << date.month << "/" << date.year << endl;
}

int main() {
	stDate StartDate, EndDate;
	StartDate = ReadDate("Enter the start of vocation date: ");
	EndDate = ReadDate("Enter the End of vocation date: ");
	
	int VocationDaysNumber = VocationDays(StartDate, EndDate);

	cout << endl;
	PrintDate("Vocation Starts From", StartDate);
	cout << endl;
	PrintDate("Vocation Ends on", EndDate);

	if (VocationDaysNumber != -1) {
		cout << "\nActucal Vocation days is: " << VocationDaysNumber << endl;
	}
	else
		cout << "\nInvalid date! the end date is less than start date." << endl;

	StartDate = EndOfVocationDate(StartDate, VocationDaysNumber);

	PrintDate("The vocation ends in", StartDate);

	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}