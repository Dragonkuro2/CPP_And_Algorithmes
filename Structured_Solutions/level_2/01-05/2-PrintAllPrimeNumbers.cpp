#include <iostream>

using namespace std;

int ReadNumber() {
	int number;
	do {
		cout << "Enter a number >= 2: ";
		cin >> number;
	} while (number < 2);

	return number;
}

bool IsPrimeNumber(int number) {
	for (int i = 2; i < number; i++) {
		if (number % i == 0)
			return false;
	}
	return true;
}

void CheckAllNumbers(int number) {
	for (int i = 2; i <= number; i++) {
		if (IsPrimeNumber(i))
			cout << i << " is a prime number." << endl;
	}
}

int main() {
	int number = ReadNumber();
	CheckAllNumbers(number);
	return 0;
}