#include <iostream>
#include <cmath>

using namespace std;

const float Pi = 3.1415;

float GetWidth() {
	float width;
	cout << "Enter the width of the square: ";
	cin >> width;
	return width;
}

float CircleArea(float width) {
	float Area = Pi * pow(width/2, 2);
	return Area;
}

void PrintCircleArea(float diametre) {
	cout << "The Circle area is: " << CircleArea(diametre) << endl;
}

int main() { // A program that calculates circle area inscribed in a square

	PrintCircleArea(GetWidth());

	return 0;
}