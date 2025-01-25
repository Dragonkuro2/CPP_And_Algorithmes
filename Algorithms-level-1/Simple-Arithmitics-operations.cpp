#include <iostream>

using namespace std;

int main() {
	int Number1 = 0;
	int Number2 = 0;

	cout << "Enter Number 1: ";
	cin >> Number1;
	cout << "Enter Number 2: ";
	cin >> Number2;

	cout << Number1 << " + " << Number2 << " = " << Number1 + Number2 << endl;
	cout << Number1 << " - " << Number2 << " = " << Number1 - Number2 << endl;
	cout << Number1 << " * " << Number2 << " = " << Number1 * Number2 << endl;
	cout << Number1 << " / " << Number2 << " = " << Number1 / Number2 << endl;
	return 0;
}