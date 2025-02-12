#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber() {
	float number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

float MySqrt(int number) {
	return pow(number, 0.5);
}

int main() {
	float number = ReadNumber();
	cout << "Number before sqrt function: " << number << endl;
	cout << "Number after using sqrt function: " << sqrt(number) << endl;
	cout << "number after using my sqrt function: " << MySqrt(number) << endl;
	return 0;
}