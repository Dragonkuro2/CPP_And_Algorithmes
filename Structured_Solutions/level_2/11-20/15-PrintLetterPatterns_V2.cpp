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

void PrintPatterns(int number) {
	for (int i = 1; i <= number; i++) {
		for (int j = 0; j < i; j++) {
			cout << (char)(i + 64);
		}
		cout << endl;
	}
}

int main() {
	PrintPatterns(ReadPositiveNumber("Enter a positive number: "));
	return 0;
}