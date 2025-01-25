#include <iostream>

using namespace std;

int main() { // Piggy Bank Calculator
	int pennis, nickels, dimes, quaters, dollars;
	int totalPennis = 0;
	cout << "Enter the number of pennis: ";
	cin >> pennis;
	cout << "Enter the number of nickels: ";
	cin >> nickels;
	cout << "Enter the number of dimes: ";
	cin >> dimes;
	cout << "Enter the number of quaters: ";
	cin >> quaters;
	cout << "Enter the number of dollars: ";
	cin >> dollars;
	totalPennis = pennis + nickels * 5 + dimes * 10 + quaters * 25 + dollars * 100;
	cout << "Total amount in pennis: " << totalPennis << endl;
	cout << "Total amount in dollars: " << totalPennis / 100 << endl;
	return 0;
}