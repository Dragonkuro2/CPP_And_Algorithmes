#include <iostream>
#include <cmath> // For the ceil function

using namespace std;

float ReadPositiveNumber(const string& message) {
    float input;
    do {
        cout << message;
        cin >> input;
    } while (input <= 0);

    return input;
}

int CalculateMonthsToSettleLoan(float loanAmount, float monthlyPayment) {
    return ceil(loanAmount / monthlyPayment);
}

int main() {
    float loanAmount = ReadPositiveNumber("Enter the loan amount: ");
    float monthlyPayment = ReadPositiveNumber("Enter the monthly payment: ");

    int months = CalculateMonthsToSettleLoan(loanAmount, monthlyPayment);
    cout << "You need " << months << " months to settle the loan." << endl;

    return 0;
}