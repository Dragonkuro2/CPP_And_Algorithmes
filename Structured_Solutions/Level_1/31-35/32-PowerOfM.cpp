#include <iostream>

using namespace std;

int ReadNumber() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	return number;
}

int ReadPower() {
	int number;
	cout << "Enter the power: ";
	cin >> number;

	return number;
}

double power(int number, int power) {
	double result = 1;
	for (int i = 0; i < power; i++)
		result *= number;
	return result;
}

void PrintPower(int N, int M) {
	cout << N << " power of " << M << ": " << power(N, M) << endl;
}

int main() { // A program that calculate the factorial of a number
	int number = ReadNumber();
	int power = ReadPower();
	PrintPower(number, power);

	return 0;
}