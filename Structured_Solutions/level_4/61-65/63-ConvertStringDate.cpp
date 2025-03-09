#include <iostream>
#include <string>
#include <vector>

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

// we used here the Gregorian calendar.
int GetDayOrder(stDate date) {
	int a = (14 - date.month) / 12;
	int y = date.year - a;
	int m = date.month + 12 * a - 2;
	int d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

bool IsValidDate(stDate date) {
	return (date.month >= 1 && date.month <= 12) && (date.day >= 1 && date.day <= GetMonthDays(date.month, date.year));
}

string ReadStringDate() {
	string Date;
	cout << "Enter a date (dd/mm/yyyy): ";
	getline(cin >> ws, Date);
	return Date;
}

vector <string> SplitString(string text, string delim) {
	vector <string> vText;
	string sWord = "";
	int pos = 0;

	while ((pos = text.find(delim)) != string::npos) {
		sWord = text.substr(0, pos);
		if (sWord != "")
			vText.push_back(sWord);
		
		text.erase(0, pos + delim.length());
	}

	if (text != "")
		vText.push_back(text);

	return vText;
}

stDate StringToDate(string TextDate) {
	stDate Date;
	vector <string> vDate = SplitString(TextDate, "/");
	Date.day = stoi(vDate[0]);
	Date.month = stoi(vDate[1]);
	Date.year = stoi(vDate[2]);
	return Date;
}

int main() {
	string DateString = ReadStringDate();
	stDate Date = StringToDate(DateString);
	
	cout << "\nDay:" << Date.day << endl;
	cout << "Month:" << Date.month << endl;
	cout << "Year:" << Date.year << endl;
	
	cout << "\nPress Enter to exit...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
	return 0;
}