#include <iostream>

using namespace std;

struct stPiggyBank {
	int pennis, nickels, dimes, quaters, dollars;
};

stPiggyBank ReadPiggyBankContent() {
	stPiggyBank piggy;
	cout << "Enter the number of pennis: ";
	cin >> piggy.pennis;
	cout << "Enter the number of nickels: ";
	cin >> piggy.nickels;
	cout << "Enter the number of dimes: ";
	cin >> piggy.dimes;
	cout << "Enter the number of quaters: ";
	cin >> piggy.quaters;
	cout << "Enter the number of dollars: ";
	cin >> piggy.dollars;

	return piggy;
}

int CalculateTotalPennis(stPiggyBank piggy) {
	int totalPennis = 0;

	totalPennis = piggy.pennis + piggy.nickels * 5 + piggy.dimes * 10 + piggy.quaters * 25 + piggy.dollars * 100;
	return totalPennis;
}

int main() { // Piggy Bank Calculator
	int TotalPennis = CalculateTotalPennis(ReadPiggyBankContent());
	cout << "Total amount in pennis: " << TotalPennis << endl;
	cout << "Total amount in dollars: " << (float)TotalPennis / 100 << endl;
	return 0;
}