#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber() {
	float number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

int MyFloor(float number) {
	int IntPart = (int)number;
	if (number >= 0)
		return IntPart;
	else
		return --IntPart;
}

int main() {
	float number = ReadNumber();
	cout << "Number before floor function: " << number << endl;
	cout << "Number after using floor function: " << floor(number) << endl;
	cout << "number after using my floor function: " << MyFloor(number) << endl;
	return 0;
}