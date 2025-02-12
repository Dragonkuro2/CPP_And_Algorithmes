#include <iostream>
#include <cmath>

using namespace std;

int ReadNumber() {
	int number;
	cout << "Enter a number: ";
	cin >> number;
	return number;
}

int MyABS(int number) {
	return (number < 0) ? number * -1 : number;
}

int main() {
	int number = ReadNumber();
	cout << "Number before ABS function: " << number << endl;
	cout << "Number after using ABS function: " << abs(number) << endl;
	cout << "number after using my abs function: " << MyABS(number) << endl;
	return 0;
}