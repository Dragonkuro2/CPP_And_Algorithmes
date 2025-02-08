#include <iostream>

using namespace std;

float GetMark() {
	float mark;
	cout << "Enter your mark (0-100): ";
	cin >> mark;

	while (mark < 0 || mark > 100) {
		cout << "Invalid input!\nEnter a valid mark: ";
		cin >> mark;
	}

	return mark;
}

bool IsValidResult(float mark) {
	return (mark >= 50);
}

void PrintResult(float mark) {
	if (IsValidResult(mark))
		cout << "You pass." << endl;
	else
		cout << "You fail." << endl;
}

int main() {

	PrintResult(GetMark());

	return 0;
}