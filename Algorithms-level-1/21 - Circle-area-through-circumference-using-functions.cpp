#include <iostream>
#include <cmath>

using namespace std;

float RectangleArea(float Circumference) {
	const float Pi = 3.1415;
	return pow(Circumference, 2) / (4 * Pi);
}

int main() { // program that calculate Circle Area Along the Circumference
	float Circumference;
	cout << "Enter the Circumference of the circle: ";
	cin >> Circumference;
	cout << "The Area of the circle is: " << RectangleArea(Circumference) << endl;
	return 0;
}