#include <iostream>
#include <cmath>

using namespace std;

const float Pi = 3.1415;

float GetReduis() {
	float reduis;
	cout << "Enter the reduis of the circle: ";
	cin >> reduis;
	return reduis;
}

float CircleArea(float reduis) {
	float Area = Pi * pow(reduis, 2);
	return Area;
}

void PrintCircleArea(float reduis) {
	cout << "The Circle area is: " << CircleArea(reduis) << endl;
}

int main() { // A program that calculates circle area

	PrintCircleArea(GetReduis());

	return 0;
}