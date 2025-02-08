#include <iostream> 

using namespace std;

void GetValues(int& number1, int& number2, int &number3) {
	cout << "Enter the number 1: ";
	cin >> number1;
	cout << "Enter the number 2: ";
	cin >> number2;
	cout << "enter the number 3: ";
	cin >> number3;
}

int MaxOfThreeNumbers(int number1, int number2, int number3) {
	if (number1 > number2) {
		if (number1 > number3)
			return number1;
		else
			return number3;
	}
	else {
		if (number2 > number3)
			return number2;
		else
			return number3;
	}
}

void PrintMaxNumber(int number1, int number2, int number3) {
	cout << "Max of " << number1 << ", " << number2 << " and " << number3 << " is : " << MaxOfThreeNumbers(number1, number2, number3) << endl;
}

int main() { // program that calculate the max of three numbers
	int number1, number2, number3;
	GetValues(number1, number2, number3);
	PrintMaxNumber(number1, number2, number3);

	return 0;
}