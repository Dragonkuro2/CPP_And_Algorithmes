#include <iostream>

using namespace std;

void PrintFactorial(int number) {
	double sum = 1;
	while (number > 0) {
		sum *= number;
		number--;
	}

	cout << "The factorial is: " << sum << endl;
}

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	PrintFactorial(number);
	return 0;
}