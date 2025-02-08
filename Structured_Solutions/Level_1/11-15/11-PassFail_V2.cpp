#include <iostream>

using namespace std;

void GetMarks(int& mark1, int& mark2, int& mark3) {
	cout << "Enter the mark 1: ";
	cin >> mark1;
	cout << "Enter the mark 2: ";
	cin >> mark2;
	cout << "Enter the mark 3: ";
	cin >> mark3;
}

int SumOf3Numbers(int number1, int number2, int number3) {
	return number1 + number2 + number3;
}

float Average3Numbers(int number1, int number2, int number3) {
	return (float)SumOf3Numbers(number1, number2, number3) / 3;
}

bool IsPassed(float average) {
	return (average >= 50);
}

void PrintResult(float average) {
	cout << "\nYour average is: " << average << endl;
	if (IsPassed(average))
		cout << "You passed" << endl;
	else
		cout << "You failed" << endl;
}

int main() {
	int mark1, mark2, mark3;
	GetMarks(mark1, mark2, mark3);
	PrintResult(Average3Numbers(mark1, mark2, mark3));

	return 0;
}