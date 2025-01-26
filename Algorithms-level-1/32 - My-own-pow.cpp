#include <iostream>
#include <cmath>

using namespace std;

int power(int number, int powr) { // my own pow function
	int result = 1;
	for (int i = 0; i < powr; i++)
		result *= number;
	return result;
}

int main() {
	int number, M;
	cout << "Enter a number: ";
	cin >> number;
	cout << "Enter the power: ";
	cin >> M;
	cout << number << " power " << M <<  " is: " << power(number, M) << endl;
	return 0;
}