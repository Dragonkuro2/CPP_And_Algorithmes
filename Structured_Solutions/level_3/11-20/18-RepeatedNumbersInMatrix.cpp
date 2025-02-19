#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct stMatrixInfo {
	int rows = 0;
	int cols = 0;
};

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

void PrintIntersectedNumbers(int matrix1[3][3], int matrix2[3][3], stMatrixInfo matrixInfo) {
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			if (IsNumberExist(matrix2, matrixInfo, matrix1[i][j]))
				cout << setw(4) << matrix1[i][j];
		}
	}
}

int main() {
	int number;
	int matrix1[3][3], matrix2[3][3];

	stMatrixInfo matrixInfo = { 3, 3 };
	srand((unsigned)time(NULL));

	FillMatrix(matrix1, matrixInfo); // if you want to generate random matrix uncomment this line
	cout << "Matrix 1:\n";
	PrintMatrix(matrix1, matrixInfo);

	FillMatrix(matrix2, matrixInfo); // if you want to generate random matrix uncomment this line
	cout << "Matrix 2:\n";
	PrintMatrix(matrix2, matrixInfo);

	cout << "the repeated numbers are: ";
	PrintIntersectedNumbers(matrix1, matrix2, matrixInfo);

	system("pause>0");

	return 0;
}