#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber() {
	float number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

int MyCeil(float number) {
	int IntPart = (int)number;
	
	float FractianalPart = number - IntPart;
	if (FractianalPart > 0) {
		if (number > 0)
			return ++IntPart;
		else
			return IntPart;
	}
	else
		return IntPart;
}

int main() {
	float number = ReadNumber();
	cout << "Number before ceil function: " << number << endl;
	cout << "Number after using ceil function: " << ceil(number) << endl;
	cout << "number after using my ceil function: " << MyCeil(number) << endl;
	return 0;
}