#include <iostream>

using namespace std;

int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number < 0);
	return number;
}

int ReverseNumber(int number) {
	int NewNumber = 0, Remainder;
	while (number) {
		Remainder = number % 10;
		number /= 10;
		NewNumber = NewNumber * 10 + Remainder;
	}
	return NewNumber;
}

void PrintNumberInOrder(int number) {
	number = ReverseNumber(number);
	int Remainder;
	while (number) {
		Remainder = number % 10;
		number /= 10;
		cout << Remainder << endl;
	}
}

int main() {
	PrintNumberInOrder(ReadPositiveNumber("Enter a positive number: "));
	return 0;
}