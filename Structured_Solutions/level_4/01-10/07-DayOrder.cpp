#include <iostream>
#include <cmath>
#include <cmath>

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
	return (year % 400 == 0) || (year % 4 == 0) && (year % 100 != 0);
}

stDate GetDate() {
	stDate date;
	date.year = ReadPositiveNumber("Enter the year: ");
	date.month = ReadNumberInRange("Enter the month: ", 1, 12);
	date.day = IsLeapYear(date.year) ? ReadNumberInRange("Enter the day: ", 1, 29) : ReadNumberInRange("Enter the day: ", 1, 29);
	return date;
}

int GetDayOrder(stDate date) {  
	int a = (14 - date.month) / 12;  
	int y = date.year - a;  
	int m = date.month + 12 * a - 2;  
	int d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;  
}

int main() {
	stDate date = GetDate();
	short DayOrder = GetDayOrder(date);

	cout << "\n\nDate      : " << date.day << "/" << date.month << "/" << date.year << endl;
	cout << "Day Order : " << DayOrder + 1 << endl;
	cout << "Day name  : " << Days[DayOrder];

	system("pause>0");
	return 0;
}