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

bool IsPalindromeNumber(int number) {
	return number == ReverseNumber(number); // if the number equal it's reverse it's a palindrome number
}

void PrintResult(int number) {
	if (IsPalindromeNumber(number))
		cout << number << " is a palindrome number." << endl;
	else
		cout << number << " is Not a palindrome number." << endl;
}

int main() {
	int number = ReadPositiveNumber("Enter a positive number: ");
	PrintResult(number);
	return 0;
}