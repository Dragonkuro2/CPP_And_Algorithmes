#include <iostream>
#include <cmath>

using namespace std;

const float Pi = 3.1415;

float GetCircumference() {
	float circumference;
	cout << "Enter the circumference of the circle: ";
	cin >> circumference;
	return circumference;
}

float CircleArea(float circumference) {
	float Area = pow(circumference, 2) / (4 *Pi);
	return Area;
}

void PrintCircleArea(float circumference) {
	cout << "The Circle area is: " << CircleArea(circumference) << endl;
}

int main() { // A program that calculates circle area along the circumference

	PrintCircleArea(GetCircumference());

	return 0;
}