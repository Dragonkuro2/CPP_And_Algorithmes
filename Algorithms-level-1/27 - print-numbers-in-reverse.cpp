#include <iostream>

using namespace std;

void PrintNumbers(int number) {
	while (number > 0) {
		cout << number << endl;
		number--;
	}
}

int main() {
	int number;
	cout << "Enter a number: ";
	cin >> number;

	PrintNumbers(number);
	return 0;
}