#include <iostream>

using namespace std;

int main() { // program that calculate a circle area through the diameter
	const float Pi = 3.14159;
	float diametre;
	cout << "Enter the diameter of the circle: ";
	cin >> diametre;
	cout << "The area of the circle is: " << Pi * diametre * diametre / 4 << endl;
	return 0;
}