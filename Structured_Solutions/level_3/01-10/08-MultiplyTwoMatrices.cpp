#include <iostream>
#include <iomanip>
#include <cstdlib>

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
			matrix[i][j] = RandomNumberInRange(1, 10);
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

void MultiplyTwoMatrix(int matrix1[3][3], int matrix2[3][3], int matrix3[3][3], stMatrixInfo matrixInfo) {
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			matrix3[i][j] = matrix1[i][j] * matrix2[i][j];
		}
	}
}

int main() {
	int matrix1[3][3], matrix2[3][3], matrix3[3][3];
	stMatrixInfo matrixInfo = {3, 3};
	srand((unsigned)time(NULL));

	FillMatrix(matrix1, matrixInfo);
	cout << "the first matrix:\n";
	PrintMatrix(matrix1, matrixInfo);

	FillMatrix(matrix2, matrixInfo);
	cout << "\n\nThe second matrix:\n";
	PrintMatrix(matrix2, matrixInfo);

	MultiplyTwoMatrix(matrix1, matrix2, matrix3, matrixInfo);
	cout << "\n\nThe multiplication of the two matrices is:\n";
	PrintMatrix(matrix3, matrixInfo);
	return 0;
}