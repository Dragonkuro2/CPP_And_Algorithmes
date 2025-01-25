#include <iostream>

using namespace std;

int main() { // Seconds to Days Hours Minutes Seconds
	int seconds = 0;
	const int daySeconds = 24 * 60 * 60;
	const int hourSeconds = 60 * 60;

	cout << "Enter the task duration in seconds: ";
	cin >> seconds;
	cout << "Task takes: " << seconds / daySeconds << " days, " << (seconds % daySeconds) / hourSeconds << " hours, " << (seconds % hourSeconds) / 60 << " minutes, " << seconds % 60 << " seconds." << endl;
	return 0;
}