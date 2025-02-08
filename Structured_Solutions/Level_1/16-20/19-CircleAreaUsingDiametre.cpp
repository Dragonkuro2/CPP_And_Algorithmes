#include <iostream>
#include <cmath>

using namespace std;

const float Pi = 3.1415;

float GetDiametre() {
	float diametre;
	cout << "Enter the diametre of the circle: ";
	cin >> diametre;
	return diametre;
}

float CircleArea(float diametre) {
	float Area = (Pi * pow(diametre, 2))/4;
	return Area;
}

void PrintCircleArea(float diametre) {
	cout << "The Circle area is: " << CircleArea(diametre) << endl;
}

int main() { // A program that calculates circle area

	PrintCircleArea(GetDiametre());

	return 0;
}