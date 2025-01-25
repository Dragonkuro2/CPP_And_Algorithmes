#include <iostream>

using namespace std;

int main() { // program that calculate a circle area inscribed in a square
	const float Pi = 3.14159;
	float sholder;
	cout << "Enter the sholder of the square: ";
	cin >> sholder;
	cout << "The area of the circle is: " << Pi * sholder * sholder / 4 << endl;
	return 0;
}