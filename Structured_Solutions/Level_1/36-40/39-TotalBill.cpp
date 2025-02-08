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

int main() {
    float TotalBill = ReadPositiveNumber("Enter the total Bill: ");
    float CashPaid = ReadPositiveNumber("Enter the total cash paid: ");

    cout << "\nTotalBill = " << TotalBill << endl;
    cout << "CashPaid  = " << CashPaid << endl;
    cout << "*****************\n";
    cout << "Remainder = " << CashPaid - TotalBill << endl;

    return 0;
}