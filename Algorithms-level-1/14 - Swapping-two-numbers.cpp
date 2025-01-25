#include <iostream>

using namespace std;

int main() {
	float number1, number2, temp;
	cout << "Enter the first number: ";
	cin >> number1;
	cout << "Enter the second number: ";
	cin >> number2;
	temp = number1;
	number1 = number2;
	number2 = temp;
	cout << "After swapping, the first number is: " << number1 << endl;
	cout << "After swapping, the second number is: " << number2 << endl;
	return 0;
}