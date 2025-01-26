#include <iostream>
#include <cmath>

using namespace std;

float RectangleAreaCalculator(float lenght, float diametre) {
	return lenght * sqrt(pow(diametre, 2) - pow(lenght, 2));
}


int main() { // program that swap two numbers using functions
	float lenght, diametre;
	cout << "Enter the lenght of the rectangle: ";
	cin >> lenght;
	cout << "Enter the diametre of the rectangle: ";
	cin >> diametre;
	cout << "The area of the rectangle is: " << RectangleAreaCalculator(lenght, diametre) << endl;
	return 0;
}