#include <iostream>

using namespace std;

int main() { // Pay Remainder
	float totalBill, cashPaid;
	cout << "Enter total bill: ";
	cin >> totalBill;
	cout << "Enter cash paid: ";
	cin >> cashPaid;
	cout << "Change: " << cashPaid - totalBill << endl;
	return 0;
}