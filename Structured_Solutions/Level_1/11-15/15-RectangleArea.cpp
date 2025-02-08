#include <iostream>

using namespace std;

struct stRectangle {
	float A;
	float B;
};

stRectangle GetValues() {
	stRectangle rectangle;
	cout << "Enter the lenght of the rectangle: ";
	cin >> rectangle.A;
	cout << "Enter the width of the rectangle: ";
	cin >> rectangle.B;
	return rectangle;
}

float RectangleArea(stRectangle rectangle) {
	return rectangle.A * rectangle.B;
}

void PrintRectangleArea(stRectangle rectangle) {
	cout << "The rectangle area is: " << RectangleArea(rectangle) << endl;
}

int main() { // A program that calculates rectangle area and print it

	PrintRectangleArea(GetValues());

	return 0;
}