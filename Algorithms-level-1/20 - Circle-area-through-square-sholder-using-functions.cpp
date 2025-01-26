#include <iostream>
#include <cmath>

using namespace std;

float RectangleArea(float sholder) {
	const float Pi = 3.1415;
	return Pi * pow(sholder/2, 2);
}

int main() { // program that calculate the area of the circle trought sholder of a square
	float sholder;
	cout << "Enter the sholder of the square: ";
	cin >> sholder;
	cout << "The Area of the circle is: " << RectangleArea(sholder) << endl;
	return 0;
}