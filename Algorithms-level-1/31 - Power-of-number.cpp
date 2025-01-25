#include <iostream>

using namespace std;

int main() { // program that calculate power of number in 2, 3 and 4
	int number;
	cout << "Enter a number: ";
	cin >> number;
	number *= number;
	cout << "Square (number^2): " << number << endl;
	number *= number;
	cout << "Cube (number^3): " << number << endl;
	number *= number;
	cout << "Fourth power (number^4): " << number << endl;
	return 0;
}