#include <iostream>

using namespace std;

int main() { // Task Duration In Seconds
	int days, houres, minutes, seconds;
	cout << "\n\t\tTime the task takes \n";
	cout << "Enter the number of days: ";
	cin >> days;
	cout << "Enter the number of houres: ";
	cin >> houres;
	cout << "Enter the number of minutes: ";
	cin >> minutes;
	cout << "Enter the number of seconds: ";
	cin >> seconds;
	cout << "The task takes: " << days * 24 * 60 * 60 + houres * 60 * 60 + minutes * 60 + seconds << " seconds\n";
	return 0;
}