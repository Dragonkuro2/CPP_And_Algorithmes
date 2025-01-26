#include <iostream>

using namespace std;

int SecondCalculator(int days, int houres, int minutes, int seconds) {
	int DaySeconds = 24 * 60 * 60;
	int HoureSeconds = 60 * 60;
	int MinuteSeconds = 60;

	return (days * DaySeconds + houres * HoureSeconds + minutes * MinuteSeconds + seconds);
}

int main() { // program that convert days, houres, minutes into seconds
	int days, houres, minutes, seconds;
	cout << "Enter the number of days: ";
	cin >> days;
	cout << "Enter the number of houres: ";
	cin >> houres;
	cout << "Enter the number of minutes: ";
	cin >> minutes;
	cout << "Enter the number of seconds: ";
	cin >> seconds;
	cout << "The totatl number of seconds that task will take is: " << SecondCalculator(days, houres, minutes, seconds) << endl;
	return 0;
}