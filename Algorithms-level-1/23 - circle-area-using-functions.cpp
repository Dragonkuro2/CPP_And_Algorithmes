#include <iostream>
#include <cmath>

using namespace std;

float RectangleArea(float a, float b, float c) {
	const float Pi = 3.1415;
	float p = (a + b + c) / 2;
	float area = Pi * pow((a * b * c / (4 * sqrt(p * (p - a) * (p - b) * (p - c)))), 2);
	return area;
}

int main() { // program that calculate Circle Area circle Described Around an Arbitrary Triangle
	float a, b, c;
	cout << "Enter sholder A: ";
	cin >> a;
	cout << "Enter sholder B: ";
	cin >> b;
	cout << "Enter sholder C: ";
	cin >> c;
	cout << "The Area of the circle is: " << RectangleArea(a, b, c) << endl;
	return 0;
}