#include <iostream>

using namespace std;


int main() {
	int number = 0;
	int sum = 0;

	while (number != -99) {
		cout << "Enter a number: ";
		cin >> number;
		if (number != -99)
			sum += number;
	}

	cout << "The sum is: " << sum << endl;

	return 0;
}