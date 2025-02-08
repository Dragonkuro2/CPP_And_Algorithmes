#include <iostream>
#include <cmath>

using namespace std;

struct stTriangle {
	float A;
	float H;
};

stTriangle GetValues() {
	stTriangle triangle;
	cout << "Enter the base of the triangle: ";
	cin >> triangle.A;
	cout << "Enter the height of the triangle: ";
	cin >> triangle.H;
	return triangle;
}

float TriangleArea(stTriangle triangle) {
	float Area = 0.5 * triangle.A * triangle.H;
	return Area;
}

void PrintTriangleArea(stTriangle triangle) {
	cout << "The Triangle area is: " << TriangleArea(triangle) << endl;
}

int main() { // A program that calculates Triangle area

	PrintTriangleArea(GetValues());

	return 0;
}