#include <iostream>
#include <cmath>

using namespace std;

int main() { // A program that calculate circle Area Through Diameter
	const float Pi = 3.1415;
	float diametre;
	cout << "Enter the diametre of the circle: ";
	cin >> diametre;
	cout << "the area of the circle is: " << ceil(Pi * pow(diametre, 2) / 4) << endl; // ceil will give you the biggest number
	return 0;
}