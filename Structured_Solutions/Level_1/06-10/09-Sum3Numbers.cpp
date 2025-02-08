#include <iostream>

using namespace std;

void GetNumbers(int& number1, int& number2, int& number3) {
	cout << "Enter the number 1: ";
	cin >> number1;
	cout << "Enter the number 2: ";
	cin >> number2;
	cout << "Enter the number 3: ";
	cin >> number3;
}

int SumOf3Numbers(int number1, int number2, int number3) {
	return number1 + number2 + number3;
}

void PrintTotal(int total) {
	cout << "Total of the 3 numbers is: " << total << endl;
}

int main() { // program that calculate the sum of three numbers
	int number1, number2, number3;

	GetNumbers(number1, number2, number3);
	PrintTotal(SumOf3Numbers(number1, number2, number3));

	return 0;
}