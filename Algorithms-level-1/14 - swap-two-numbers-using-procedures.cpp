#include <iostream>

using namespace std;

void SwapNumbers(int Number1, int Number2) {
	int temp;
	temp = Number1;
	Number1 = Number2;
	Number2 = temp;
	cout << "Number 1 after swapping is: " << Number1 << endl;
	cout << "Number 2 after swapping is: " << Number2 << endl;
}

int main() { // program that swap two numbers using procedures
	int Number1, Number2;
	cout << "Enter the first number: ";
	cin >> Number1;
	cout << "Enter the second number: ";
	cin >> Number2;
	SwapNumbers(Number1, Number2);

	return 0;
}