#include <iostream>

using namespace std;

float ReadAmount() {
	float amount;
	cout << "Enter the total amount: ";
	cin >> amount;

	return amount;
}

float PercentCalculator(float amount) {
	if (amount >= 1000000)
		return 0.01;
	else if (amount >= 500000)
		return 0.02;
	else if (amount >= 100000)
		return 0.03;
	else if (amount >= 50000)
		return 0.05;
	else
		return 0;
}

float ProfitCalculator(float amount) {
	return amount * PercentCalculator(amount);
}

void PrintProfit(float amount) {
	cout << "Your profit from " << amount << " is " << PercentCalculator(amount) * 100 << "%" << endl;
	cout << "Profit: " << ProfitCalculator(amount) << endl;
}

int main() { // A program tht clculate the profit
	float amount = ReadAmount();
	PrintProfit(amount);

	return 0;
}