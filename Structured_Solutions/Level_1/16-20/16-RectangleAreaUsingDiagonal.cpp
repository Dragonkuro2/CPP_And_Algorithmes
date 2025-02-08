#include <iostream>
#include <cmath>

using namespace std;

struct stRectangle {
	float A;
	float D;
};

stRectangle GetValues() {
	stRectangle rectangle;
	cout << "Enter the lenght of the rectangle: ";
	cin >> rectangle.A;
	cout << "Enter the diagonal of the rectangle: ";
	cin >> rectangle.D;
	return rectangle;
}

float RectangleArea(stRectangle rectangle) {
	float Area = rectangle.A * sqrt(pow(rectangle.D, 2) - pow(rectangle.A, 2));
	return Area;
}

void PrintRectangleArea(stRectangle rectangle) {
	cout << "The rectangle area is: " << RectangleArea(rectangle) << endl;
}

int main() { // A program that calculates rectangle area using diagonal and print it

	PrintRectangleArea(GetValues());

	return 0;
}