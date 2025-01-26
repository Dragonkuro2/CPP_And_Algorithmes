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
	int number;
	cout << "Enter a number: ";
	cin >> number;
	cout << number << " power 2 is: " << power(number, 2) << endl;
	cout << number << " power 3 is: " << power(number, 3) << endl;
	cout << number << " power 4 is: " << power(number, 4) << endl;
	return 0;
}