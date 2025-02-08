#include <iostream>

using namespace std;

void GetNumbers(int& number1, int& number2) {
	cout << "Enter the first number: ";
	cin >> number1;
	cout << "Enter the second number: ";
	cin >> number2;
}

void PrintNumbers(int number1, int number2) {
	cout << "the first number is: " << number1 << endl;
	cout << "the second number is: " << number2 << endl;
}

void SwapTwoNumbers(int& number1, int& number2) {
	int temp;
	temp = number1;
	number1 = number2;
	number2 = temp;
}

int main() { // A program that swap two numbers
	int number1, number2;
	GetNumbers(number1, number2);
	PrintNumbers(number1, number2);
	SwapTwoNumbers(number1, number2);
	PrintNumbers(number1, number2);

	return 0;
}