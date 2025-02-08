#include <iostream>

using namespace std;

int ReadNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number < 0);

	return number;
}

bool IsPerfectNumber(int number) {
	int sum = 0;
	for (int i = 1; i <= round(number / 2); i++) {
		if (number % i == 0)
			sum += i;
	}

	return (sum == number);
}

void PerfectNumber(int number) {
	if (IsPerfectNumber(number))
		cout << number << " is a perfect number." << endl;
	else
		cout << number << " is not a perfect number." << endl;
}

int main() {

	int number = ReadNumber("Enter a positive number: ");

	PerfectNumber(number);

	return 0;
}