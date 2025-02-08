#include <iostream>

using namespace std;

int ReadPositiveNumber(string message = "Enter a positive Number: ") {
	int N;
	do {
		cout << message;
		cin >> N;
	} while (N < 0);
	return N;
}

double Factorial(int N) {
	double result = 1;
	for (int counter = N; counter > 0; counter--)
		result *= counter;

	return result;
}

void PrintResult(int N) {
	cout << "Factorial of " << N << " is: " << Factorial(N) << endl;
}

int main() { // A program that calculate the factorial of a number
	
	PrintResult(ReadPositiveNumber("Enter a positive number: "));

	return 0;
}