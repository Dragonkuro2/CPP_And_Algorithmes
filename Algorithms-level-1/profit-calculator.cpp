#include <iostream>

using namespace std;

float PercentCalculator(float amount) {
	if (amount > 1000000)
		return amount * 0.01;
	else if (amount <= 1000000 && amount > 500000)
		return amount * 0.02;
	else if (amount <= 500000 && amount < 100000)
		return amount * 0.03;
	else if (amount <= 100000 && amount > 50000)
		return amount * 0.05;
	else
		return 0;
}

int main() {
	float amount;
	cout << "Enter the total value fo sales: ";
	cin >> amount;
	cout << "Your value of " << amount << " is: " << PercentCalculator(amount) << endl;
	return 0;
}