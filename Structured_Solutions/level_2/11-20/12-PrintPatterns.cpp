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
	for (int i = number; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			cout << i;
		}
		cout << endl;
	}
}

int main() {
	PrintPatterns(ReadPositiveNumber("Enter a positive number: "));
	return 0;
}