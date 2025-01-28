#include <iostream>

using namespace std;

char GradeDeterminator(short grade) {
	if (grade <= 100 && grade >= 90) {
		return 'A';
	}
	else if (grade < 90 && grade >= 80) {
		return 'B';
	}
	else if (grade < 80 && grade >= 70) {
		return 'C';
	}
	else if (grade < 70 && grade >= 60) {
		return 'D';
	}
	else if (grade < 60 && grade >= 50) {
		return 'E';
	}
	else {
		return 'X';
	}
}

int main() {
	short grade;
	cout << "Enter your grade: ";
	cin >> grade;

	if (GradeDeterminator(grade) != 'X')
		cout << "Your mark is: " << GradeDeterminator(grade) << endl;
	else
		cout << "Invalid mark!" << endl;

	return 0;
}