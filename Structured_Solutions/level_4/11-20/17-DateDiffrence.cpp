#include <iostream>
#include <iomanip>
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

stDate ReadDate() {
	stDate date;
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

bool IsDate1LessThanDate2(stDate date1, stDate date2) { // function that checks if date1 is less than date2
	if (date1.year != date2.year)
		return date1.year < date2.year;
	if (date1.month != date2.month)
		return date1.month < date2.month;
	return date1.day < date2.day;
}

bool IsDate1EqualDate2(stDate date1, stDate date2) { // function that checks if date1 is less than date2
	return ((date1.year == date2.year) && (date1.month == date2.month) && (date1.day == date2.day));
}

int NumberOfDaysFromTheBeginning(stDate date) {
	int sum = 0;
	for (int i = 1; i < date.month; i++) {
		sum += GetMonthDays(date.year, i); // here I'll add to the last month before the one that the user puts
	}
	sum += date.day; // here I'll add the number of days in that month
	return sum;
}

int GetYearDays(int year) {
	return IsLeapYear(year) ? 366 : 365;
}

int CalculateDays(stDate StartDate, stDate EndDate) {
	if (StartDate.year == EndDate.year)
		return NumberOfDaysFromTheBeginning(EndDate) - NumberOfDaysFromTheBeginning(StartDate);
	else if (StartDate.year < EndDate.year) {
		int days = 0;
		// Add remaining days in the start year
		days += GetYearDays(StartDate.year) - NumberOfDaysFromTheBeginning(StartDate);
		// Add days in the full years between start and end year
		for (int year = StartDate.year + 1; year < EndDate.year; year++) {
			days += GetYearDays(year);
		}
		// Add days in the end year
		days += NumberOfDaysFromTheBeginning(EndDate);
		return days;
	}
	else
		return 0;
}

int DiffrenceBetweenDates(stDate date1, stDate date2, bool IncludeEndDay = false) {
	if (IsDate1LessThanDate2(date1, date2)) {
		int DaysNumber = CalculateDays(date1, date2);
		cout << "Difference is: " << DaysNumber << " Day(s)." << endl;
		if (IncludeEndDay)// if we want to include end day the IncludeEndDay will be true.
			cout << "Difference (including End day): " << DaysNumber + 1 << " Day(s)." << endl;
	}
	else if (IsDate1EqualDate2(date1, date2)) {
		cout << "The dates are the same." << endl;
		return 0;
	}
	else {
		cout << "Operation can't be done. The first date is bigger than the second one." << endl;
		return 0;
	}
}

int main() {
	stDate date1;
	stDate date2;

	cout << "Enter the first date:\n";
	date1 = ReadDate();
	cout << "\nEnter the second date:\n";
	date2 = ReadDate();

	DiffrenceBetweenDates(date1, date2, true);// include end day

	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}