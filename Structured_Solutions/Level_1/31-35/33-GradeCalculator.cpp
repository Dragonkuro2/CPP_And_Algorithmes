#include <iostream>

using namespace std;

short ReadGradeInRange(int From, int To) {
	int grade;
	do {
		cout << "Enter your grade (0-100): ";
		cin >> grade;
	} while (grade < From || grade > To);
	
	return grade;
}

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

void PrintGrade(short grade) {
	cout << "Your result is: " << GradeDeterminator(grade) << endl;
}

int main() { // A program that calculate the result of a student
	short grade = ReadGradeInRange(0, 100);
	PrintGrade(grade);
	return 0;
}