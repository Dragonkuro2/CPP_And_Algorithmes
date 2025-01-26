#include <iostream>
#include <cmath>

using namespace std;

int main() { // A program that calculate Power of 2,3,4 of entred number
	float number;
	cout << "Enter a number: ";
	cin >> number;
	cout << "Power of 2 of the number " << number << " is: " << round(pow(number, 2)) << endl;
	cout << "Power of 3 of the number " << number << " is: " << round(pow(number, 3)) << endl;
	cout << "Power of 4 of the number " << number << " is: " << round(pow(number, 4)) << endl;
	return 0;
}