#include <iostream>

using namespace std;

enum enDay {
	Sunday = 1,
	Monday = 2,
	Tuesday = 3,
	Wendnesday = 4,
	Thursday = 5,
	Friday = 6,
	Saturday = 7
};

void PrintList() {
	cout << "****************************************\n";
	cout << "(1) Sunday\n";
	cout << "(2) Monday\n";
	cout << "(3) Tuesday\n";
	cout << "(4) Wendnesday\n";
	cout << "(5) Thursday\n";
	cout << "(6) Friday\n";
	cout << "(7) Saturday\n";
	cout << "****************************************\n";
}

void PrintDay(enDay day) {
	switch (day) {
	case enDay::Sunday:
		cout << "Sunday" << endl;
		break;
	case enDay::Monday:
		cout << "Monday" << endl;
		break;
	case enDay::Tuesday:
		cout << "Tuesday" << endl;
		break;
	case enDay::Wendnesday:
		cout << "Wendnesday" << endl;
		break;
	case enDay::Thursday:
		cout << "Thursday" << endl;
		break;
	case enDay::Friday:
		cout << "Friday" << endl;
		break;
	case enDay::Saturday:
		cout << "Saturday" << endl;
		break;
	default:
		cout << "Invalid day!" << endl;
		break;
	}
}

int main() { // program that writes the name of the month of the screen
	short option;
	enDay day;

	PrintList();
	cout << "Enter number a number of a day: ";
	cin >> option;

	day = (enDay)option;

	PrintDay(day);


	return 0;
}