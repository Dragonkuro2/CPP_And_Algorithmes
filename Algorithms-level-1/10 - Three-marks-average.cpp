#include <iostream>

using namespace std;

int main() {
	float mark1, mark2, mark3;
	float result = 0;
	cout << "Enter the mark number 1: ";
	cin >> mark1;
	cout << "Enter the mark number 2: ";
	cin >> mark2;
	cout << "Enter the mark number 3: ";
	cin >> mark3;
	result = (mark1 + mark2 + mark3)/3;
	cout << "the average of marks is: " << result << endl;
	return 0;
}