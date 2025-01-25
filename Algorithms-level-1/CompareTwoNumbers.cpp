#include <iostream>

using namespace std;

int main() { // program that compare two numbers
	float number1, number2;
	cout << "Enter the first number: ";
	cin >> number1;
	cout << "Enter the second number: ";
	cin >> number2;
	cout << number1 << " == " << number2 << " is: " << (number1 == number2) << endl;
	cout << number1 << " != " << number2 << " is: " << (number1 != number2) << endl;
	cout << number1 << " > " << number2 << " is: " << (number1 > number2) << endl;
	cout << number1 << " < " << number2 << " is: " << (number1 < number2) << endl;
	cout << number1 << " >= " << number2 << " is: " << (number1 >= number2) << endl;
	cout << number1 << " <= " << number2 << " is: " << (number1 <= number2) << endl;
	return 0;
}