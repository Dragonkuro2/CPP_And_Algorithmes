#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber() {
	float number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

int MyRound(float number) {
	float Remainder = number - (int)number;
	int IntPart = (int)number;
	if (abs(Remainder) >= 0.5) {
		if (number > 0)
			return ++IntPart;
		else
			return --IntPart;
	}
	else
		return IntPart;
}

int main() {
	float number = ReadNumber();
	cout << "Number before round function: " << number << endl;
	cout << "Number after using round function: " << round(number) << endl;
	cout << "number after using my round function: " << MyRound(number) << endl;
	return 0;
}