#include <iostream>

using namespace std;

int ReadPositiveNumber(const string& message) {
	int input;
	do {
		cout << message;
		cin >> input;
	} while (input < 0);

	return input;
}

int DaysCalculator(int seconds) { // number of seconds divided by the number of second per day
	return (int)(seconds / (24 * 60 * 60));
}

int HouresCalculator(int seconds) {
	return (seconds % (24 * 60 * 60)) / (60 * 60);
}

int MinutesCalculator(int seconds) {
	return (seconds % (60 * 60)) / 60;
}

int SecondsCalculator(int seconds) {
	return (seconds % 60);
}

void PrintTime(int seconds) {
	cout << "The task toke: " << DaysCalculator(seconds) << " Days " << HouresCalculator(seconds) << " Houres ";
	cout << MinutesCalculator(seconds) << " Minutes " << SecondsCalculator(seconds) << " Seconds." << endl;
}

int main() { // program that convert seconds into days, houres, minutes
	int seconds = ReadPositiveNumber("Enter the number of seconds: ");

	PrintTime(seconds);

	return 0;
}