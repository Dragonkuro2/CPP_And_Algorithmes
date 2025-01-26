#include <iostream>
#include <cmath>

using namespace std;

int main() { // A program that calculate Circle Area Inscribed in an Isosceles Triangle
	const float Pi = 3.1415;
	float triangleBase, sholder;
	float area;
	cout << "Enter the triangle base: ";
	cin >> triangleBase;
	cout << "Enter the triangle sholder: ";
	cin >> sholder;
	area = (Pi * pow(triangleBase, 2) / 4) * ((2 * sholder - triangleBase) / (2 * sholder + triangleBase));
	cout << "the area of the circle is: " << floor(area) << endl; // floor will give you the lowest number
	return 0;
}