#include <iostream>

using namespace std;

void PrintPower(int number, int power) {
	double sum = 1;
	while (power > 0) {
		sum *= number;
		power--;
	}

	cout << "The power of "<< number <<" is: " << sum << endl;
}

void ReadNumberAndPower(int& number, int& power) {
	cout << "Enter a number: ";
	cin >> number;
	cout << "Enter the power: ";
	cin >> power;
}

int main() {
	int number, power;
	
	ReadNumberAndPower(number, power);
	PrintPower(number, power);
	return 0;
}