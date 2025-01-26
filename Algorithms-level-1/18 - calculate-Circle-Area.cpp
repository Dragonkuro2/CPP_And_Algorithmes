#include <iostream>
#include <cmath>

using namespace std;

int main() { // program that calculate Circle Area
	const float Pi = 3.1415;
	float reduis;
	cout << "Enter the reduis of the circle: ";
	cin >> reduis;
	cout << "the area of the circle is: " << ceil(Pi * pow(reduis, 2)) << endl; // ceil will give you the biggest number
	return 0;
}