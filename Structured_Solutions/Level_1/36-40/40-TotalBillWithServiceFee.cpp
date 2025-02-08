#include <iostream>

using namespace std;

float ReadPositiveNumber(const string& message) {
    float input;
    do {
        cout << message;
        cin >> input;
    } while (input < 0);
 
    return input;
}

float TotalBillWithServiceAndTax(float Bill) {
    Bill *= 1.1;
    Bill *= 1.16;

    return Bill;
}

int main() { // Service Fee and Sales Tax
	float BillValue = ReadPositiveNumber("Enter bill value: ");
	cout << "\nThe total Bill before adding taxes and service fee is: " << BillValue << endl;
    cout << "The total Bill after adding taxes and service fee is: " << TotalBillWithServiceAndTax(BillValue) << endl;
	return 0;
}