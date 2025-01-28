#include <iostream>

using namespace std;

void PrintNumbers(int number) {
	int sum = 0;
	while (number > 0) {
		if (number % 2 == 1)
			sum += number;
		number--;
	}

	cout << "The sum is: " << sum << endl;
}

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	PrintNumbers(number);
	return 0;
}