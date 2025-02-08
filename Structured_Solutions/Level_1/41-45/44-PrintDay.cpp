#include <iostream>

using namespace std;

enum enDays {Sunday =1 , Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7};

int ReadPositiveNumber(const string& message) {
	int input;
	do {
		cout << message;
		cin >> input;
	} while (input < 0);

	return input;
}

void PrintDay(int day) {
	switch ((enDays)day) {
	case enDays::Sunday:
		cout << "Sunday" << endl;
		break;
	case enDays::Monday:
		cout << "Monday" << endl;
		break;
	case enDays::Tuesday:
		cout << "Tuesday" << endl;
		break;
	case enDays::Wednesday:
		cout << "Wednesday" << endl;
		break;
	case enDays::Thursday:
		cout << "Thursday" << endl;
		break;
	case enDays::Friday:
		cout << "Friday" << endl;
		break;
	case enDays::Saturday:
		cout << "Saturday" << endl;
		break;
	default:
		cout << "Wrong Day!" << endl;
	}
}

int main() { // program that convert seconds into days, houres, minutes

	PrintDay(ReadPositiveNumber("Enter a day number [Sun = 1, Mon = 2, Tues = 3, Wed = 4, Thur = 5, Friday = 6, Sat = 7]: "));

	return 0;
}