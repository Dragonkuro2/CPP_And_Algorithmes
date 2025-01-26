#include <iostream>
#include <cmath>

using namespace std;

int main() { // program that calculate Rectangle area Through Diagonal and Side Area
	float height, diagonal;
	float area;
	cout << "Enter the height of rectangle: ";
	cin >> height;
	cout << "Enter the diagonal of the rectangle: ";
	cin >> diagonal;

	area = height * sqrt(pow(diagonal, 2) - pow(height, 2));
	cout << "The area of the rectangle is: " << area << endl;
	
	return 0;
}