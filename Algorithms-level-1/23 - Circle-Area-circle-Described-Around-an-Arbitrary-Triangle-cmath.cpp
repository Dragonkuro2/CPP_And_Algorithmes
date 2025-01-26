#include <iostream>
#include <cmath>

using namespace std;

int main() { // A program that calculate Circle Area circle Described Around an Arbitrary Triangle
	const float Pi = 3.1415;
	float a, b, c, p;
	float area;
	cout << "Enter the sholder A: ";
	cin >> a;
	cout << "Enter the sholder B: ";
	cin >> b;
	cout << "Enter the sholder C: ";
	cin >> c;
	p = (a + b + c) / 2;
	area = Pi * pow((a*b*c/(4*sqrt(p*(p - a)*(p - b)*(p - c)))), 2);
	cout << "the area of the circle is: " << round(area) << endl;
	return 0;
}