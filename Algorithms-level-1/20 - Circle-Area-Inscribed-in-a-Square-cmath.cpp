#include <iostream>
#include <cmath>

using namespace std;

int main() { // A program that calculate Circle Area Inscribed in a Square
	const float Pi = 3.1415;
	float sholder;
	cout << "Enter the sholder of the square: ";
	cin >> sholder;
	cout << "the area of the circle is: " << ceil(Pi * pow(sholder / 2, 2)) << endl; // ceil will give you the biggest number
	return 0;
}