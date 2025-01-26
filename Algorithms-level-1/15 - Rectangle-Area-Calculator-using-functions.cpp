#include <iostream>

using namespace std;

float RectangleAreaCalculator(float lenght, float width) {
	return lenght * width;
}


int main() { // program that swap two numbers using procedures
	float lenght, width;
	cout << "Enter the lenght of the rectangle: ";
	cin >> lenght;
	cout << "Enter the width of the rectangle: ";
	cin >> width;
	cout << "The area of the rectangle is: " << RectangleAreaCalculator(lenght, width) << endl;
	return 0;
}