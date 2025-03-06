#include <iostream>
#include <iomanip>

using namespace std;

const string Days[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
const string Months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

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

int ReadYear() {
	return ReadPositiveNumber("Enter a year: ");
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

void PrintDays(int FirstDayOrder, int DaysNumber) {
	int counter = 0;
	for (int i = 0; i < FirstDayOrder; i++) {
		cout << setw(5) << "";
		counter++;
	}

	for (int i = 1; i <= DaysNumber; i++) {
		cout << setw(5) << i;
		counter++;
		if (counter % 7 == 0)
			cout << endl;
	}
	cout << endl;
}

void PrintMonthCalender(int year, int month) {
	cout << "\n  _______________" << Months[month - 1] << "_______________\n\n";

	for (int i = 0; i < 7; i++)
		cout << setw(5) << Days[i];
	cout << endl;

	int DaysNumber = GetMonthDays(year, month);
	int FirstDayOrder = GetDayOrder(year, month, 1);// get the order of the first day of the month

	PrintDays(FirstDayOrder, DaysNumber);
	cout << "  _________________________________\n";
}

void PrintYearCalender(int year) {
	cout << "\n  _________________________________\n\n";
	cout << "  \t   Calender - " << year << endl;
	cout << "  _________________________________\n";
	for (int i = 1; i <= 12; i++) {
		PrintMonthCalender(year, i);
		cout << endl;
	}
}

int main() {
	int year = ReadYear();
	PrintYearCalender(year);

	cout << "Press Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}