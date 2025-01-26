#include <iostream>
#include <cmath>

using namespace std;

int main() { // A program that calculate Circle Area Along the Circumference
	const float Pi = 3.1415;
	float circumference;
	cout << "Enter the circumference of the square: ";
	cin >> circumference;
	cout << "the area of the circle is: " << floor(pow(circumference, 2) / (4 * Pi)) << endl; // floor will give you the lowest number
	return 0;
}