#include <iostream>
#include <cmath>

using namespace std;

float RectangleArea(float a, float b) {
	const float Pi = 3.1415;
	return (Pi * pow(b, 2) / 4) * ((2 * a - b) / (2 * a + b));
}

int main() { // program that calculate Circle Area Inscribed in an Isosceles Triangle
	float a, b;
	cout << "Enter the sholder width of the triangle: ";
	cin >> a;
	cout << "Enter the base width of the triangle: ";
	cin >> b;
	cout << "The Area of the circle is: " << RectangleArea(a, b) << endl;
	return 0;
}