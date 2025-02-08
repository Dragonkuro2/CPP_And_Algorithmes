#include <iostream>

using namespace std;

float ReadPositiveNumber(const string& message) {
    float input;
    do {
        cout << message;
        cin >> input;
    } while (input <= 0);

    return input;
}

float CalculateMonthlyInstallment(float loanAmount, int months) {
    return loanAmount / months;
}

int main() {
    float loanAmount = ReadPositiveNumber("Enter the loan amount: ");
    int months = ReadPositiveNumber("Enter the number of months to settle the loan: ");

    float monthlyInstallment = CalculateMonthlyInstallment(loanAmount, months);
    cout << "The monthly installment amount is: " << monthlyInstallment << endl;

    return 0;
}