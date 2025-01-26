#include <iostream>
#include <cmath>

using namespace std;

float RectangleArea(float diamtre) {
	const float Pi = 3.1415;
	return Pi * pow(diamtre, 2) / 4;
}

int main() { // program that calculate the area of the circle
	float diametre;
	cout << "Enter the diametre of the circle: ";
	cin >> diametre;
	cout << "The Area of the circle is: " << RectangleArea(diametre) << endl;
	return 0;
}