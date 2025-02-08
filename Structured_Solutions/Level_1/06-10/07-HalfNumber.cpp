#include <iostream>

using namespace std;

float GetNumber() {
	float number;
	cout << "Enter a number: ";
	cin >> number;

	return (number);
}

float CalculateHalfNumber(float number) {
	return number / 2;
}

void PrintResult(float number) {
	cout << "Half of " << number << " is " << CalculateHalfNumber(number) << endl;
}

int main() {

	PrintResult(GetNumber());
	
	return 0;
}