#include <iostream>

using namespace std;

int main() {
	double number1, number2, number3;
	double result = 0;
	cout << "Enter the first number: ";
	cin >> number1;
	cout << "Enter the second number: ";
	cin >> number2;
	cout << "Enter the third number: ";
	cin >> number3;
	result = number1 + number2 + number3;
	cout << "the sum of these three numbers is: " << result << endl;
	return 0;
}