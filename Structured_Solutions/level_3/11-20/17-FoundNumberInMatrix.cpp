#include <iostream>
#include <cstdlib>

using namespace std;

struct stMatrixInfo {
	int rows = 0;
	int cols = 0;
};

int ReadNumber(string message) {
	int number;
	cout << message;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!" << endl;
		cout << message;
		cin >> number;
	}

	return number;
}

int RandomNumberInRange(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrix(int matrix[3][3], stMatrixInfo matrixInfo) {
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			matrix[i][j] = RandomNumberInRange(0, 99);
		}
	}
}

void PrintMatrix(int matrix[3][3], stMatrixInfo matrixInfo) {
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			printf("%02d  ", matrix[i][j]);
		}
		cout << endl;
	}
}

bool IsNumberExist(int matrix1[3][3], stMatrixInfo matrixInfo, int searched) {
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			if (matrix1[i][j] == searched)
				return true;
		}
	}
	return false;
}

int main() {
	int number;
	int matrix1[3][3] = {
		{9, 0, 0},
		{0, 9, 0},
		{0, 0, 9}
	};

	stMatrixInfo matrixInfo = { 3, 3 };
	srand((unsigned)time(NULL));

	FillMatrix(matrix1, matrixInfo); // if you want to generate random matrix uncomment this line
	cout << "Matrix:\n";
	PrintMatrix(matrix1, matrixInfo);

	number = ReadNumber("Enter the number you are looking for: ");

	if (IsNumberExist(matrix1, matrixInfo, number))
		cout << "\nYes: the number is found.\n";
	else
		cout << "\nNo: The number doesn't exist\n";

	system("pause>0");

	return 0;
}