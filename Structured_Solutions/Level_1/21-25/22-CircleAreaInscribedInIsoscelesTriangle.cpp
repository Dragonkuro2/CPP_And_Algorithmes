#include <iostream>
#include <cmath>

using namespace std;

const float Pi = 3.1415926535897932384626433832795;

void GetTriangleInfo(float &A, float &B) {
	cout << "Enter the triangle side A: ";
	cin >> A;
	cout << "Enter the triangle side B: ";
	cin >> B;
}

float CircleArea(float A, float B) {
	float Area = Pi * pow(B, 2)/4 * ((2*A - B)/(2*A + B));
	return Area;
}

void PrintCircleArea(float A, float B) {
	cout << "The Circle area is: " << CircleArea(A, B) << endl;
}

int main() { // A program that calculates circle area inscribed in an isosceles triangle
	float A, B;
	GetTriangleInfo(A, B);
	PrintCircleArea(A, B);

	return 0;
}