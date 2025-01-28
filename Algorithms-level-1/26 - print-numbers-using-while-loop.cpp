#include <iostream>

using namespace std;

void PrintNumbers(int number) {
	int i = 1;
	while (number > 0) {
		cout << i << endl;
		i++;
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