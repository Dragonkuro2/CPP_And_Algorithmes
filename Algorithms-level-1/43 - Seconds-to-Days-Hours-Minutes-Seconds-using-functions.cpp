#include <iostream>

using namespace std;

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

int main() { // program that convert seconds into days, houres, minutes
	int seconds;
	cout << "Enter the number of seconds: ";
	cin >> seconds;
	cout << "The task toke: " << DaysCalculator(seconds) << " Days " << HouresCalculator(seconds) << " Houres ";
	cout << MinutesCalculator(seconds) << " Minutes " << SecondsCalculator(seconds) << " Seconds." << endl;
	return 0;
}