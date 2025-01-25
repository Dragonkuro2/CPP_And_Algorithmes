#include <iostream>

using namespace std;

int main() { // Monthly Loan Installment
	int loanAmount, monthsNumber;
	cout << "Enter the total loan amount: ";
	cin >> loanAmount;
	cout << "Enter the number of months: ";
	cin >> monthsNumber;
	cout << "You have to pay each month: " << loanAmount / monthsNumber << endl;
	return 0;
}