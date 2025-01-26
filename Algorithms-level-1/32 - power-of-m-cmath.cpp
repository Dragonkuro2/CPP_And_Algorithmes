#include <iostream>
#include <cmath>

using namespace std;

int main() { // A program that calculate Power of M
	float number;
	int M;
	cout << "Enter a number: ";
	cin >> number;
	cout << "Enter it's power: ";
	cin >> M;
	cout << number << " power " << M << " equal: " << round(pow(number, M)) << endl;
	return 0;
}