#include <iostream>

using namespace std;

int main() { // ATM PIN 3 Times
	short pinCode = 1234;
	short UserpinCode;
	int balance = 7500;
	short counter = 0;
	while (counter < 3) {
		cout << "Enter your pin code: ";
		cin >> UserpinCode;
		if (pinCode == UserpinCode) {
			cout << "Your balance is: " << balance << endl;
			return 0;
		}
		else {
			cout << "Wrong pin!" << endl;
		}

		counter++;
	};

	cout << "card is locked!";

	return 0;
}