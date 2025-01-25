#include <iostream>

using namespace std;

int main() { // program that calculate a circle area inscribed in an isosceles triangle
	const float Pi = 3.14159;
	float base_weight, sholder;
	cout << "Enter the sholder of the isosceles triangle: ";
	cin >> sholder;
	cout << "Enter the base weight of the isosceles triangle: ";
	cin >> base_weight;
	cout << "The area of the circle is: " << Pi * base_weight * base_weight / 4 *((2 * sholder - base_weight)/(2*sholder + base_weight)) << endl;
	return 0;
}