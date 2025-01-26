#include <iostream>
#include <cmath>

using namespace std;

float RectangleArea(float reduis) {
	const float Pi = 3.1415;
	return Pi * pow(reduis, 2);
}

int main() { // program that calculate the area of the circle
	float reduis;
	cout << "Enter the reduis of the circle: ";
	cin >> reduis;
	cout << "The Area of the circle is: " << RectangleArea(reduis) << endl;
	return 0;
}