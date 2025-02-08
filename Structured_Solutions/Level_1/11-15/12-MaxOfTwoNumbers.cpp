#include <iostream> 

using namespace std;

void GetValues(int& number1, int& number2) {
	cout << "Enter the first number: ";
	cin >> number1;
	cout << "Enter the second number: ";
	cin >> number2;
}

int MaxOfTwoNumbers(int number1, int number2) {
	return (number1 > number2) ? number1 : number2;
}

void PrintMaxNumber(int number1, int number2) {
	cout << "Max of " << number1 << " and " << number2 << " is : " << MaxOfTwoNumbers(number1, number2) << endl;
}

int main() {
	int number1, number2;
	GetValues(number1, number2);
	PrintMaxNumber(number1, number2);

	return 0;
}