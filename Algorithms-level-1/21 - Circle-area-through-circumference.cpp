#include <iostream>

using namespace std;

int main() { // program that calculate a circle area along the circumference
	const float Pi = 3.14159;
	float circumference;
	cout << "Enter the circumference of the circle: ";
	cin >> circumference;
	cout << "The area of the circle is: " << circumference * circumference / (4 * Pi) << endl;
	return 0;
}