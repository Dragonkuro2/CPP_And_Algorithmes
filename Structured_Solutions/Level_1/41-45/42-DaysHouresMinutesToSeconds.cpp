#include <iostream>

using namespace std;

struct stTime {
	int days, houres, minutes, seconds;
};

int ReadPositiveNumber(const string& message) {
    int input;
    do {
        cout << message;
        cin >> input;
    } while (input < 0);

    return input;
}

stTime ReadTime() {
	stTime Time;
	Time.days = ReadPositiveNumber("Enter the number of days: ");
	Time.houres = ReadPositiveNumber("Enter the number of houres: ");
	Time.minutes = ReadPositiveNumber("Enter the number of minutes: ");
	Time.seconds = ReadPositiveNumber("Enter the number of seconds: ");
	return Time;
}

int SecondCalculator(stTime Time) {
	int DaySeconds = 24 * 60 * 60;
	int HoureSeconds = 60 * 60;
	int MinuteSeconds = 60;

	return (Time.days * DaySeconds + Time.houres * HoureSeconds + Time.minutes * MinuteSeconds + Time.seconds);
}

int main() { // program that convert days, houres, minutes into seconds
	
	
	cout << "The totatl number of seconds that task will take is: " << SecondCalculator(ReadTime()) << endl;
	return 0;
}