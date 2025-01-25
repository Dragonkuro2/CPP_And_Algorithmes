#include <iostream>

using namespace std;

int main() { // Loan Instalment Months
	int loanAmount = 0;
	int monthlyPayment = 0;
	cout << "Enter the loan amount: ";
	cin >> loanAmount;
	cout << "Enter the monthly payment: ";
	cin >> monthlyPayment;
	cout << "You'll take " << loanAmount / monthlyPayment << " months to pay off the loan." << endl;
	return 0;
}