#include <iostream>

using namespace std;

int main() { // Service Fee and Sales Tax
	float BillValue;
	cout << "Enter bill value: ";
	cin >> BillValue;
	BillValue *= 1.1;
	BillValue *= 1.16;
	cout << "The total Bill after adding taxes is: " << BillValue << endl;
	return 0;
}