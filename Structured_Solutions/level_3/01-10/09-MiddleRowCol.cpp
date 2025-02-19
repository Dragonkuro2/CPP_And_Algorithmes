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

void PrintMiddleRowOfMatrix(int matrix[3][3], stMatrixInfo matrixInfo) {
	int MiddleRow = matrixInfo.rows / 2;
	for (int j = 0; j < matrixInfo.cols; j++) {
		printf("%02d  ", matrix[MiddleRow][j]);
	}
	cout << endl;
}

void PrintMiddleColOfMatrix(int matrix[3][3], stMatrixInfo matrixInfo) {
	int MiddleCol = matrixInfo.cols / 2;
	for (int i = 0; i < matrixInfo.rows; i++) {
		printf("%02d  ", matrix[i][MiddleCol]);
	}
	cout << endl;
}

int main() {
	int matrix1[3][3];
	stMatrixInfo matrixInfo = {3, 3};
	srand((unsigned)time(NULL));

	FillMatrix(matrix1, matrixInfo);
	cout << "The first matrix:\n";
	PrintMatrix(matrix1, matrixInfo);

	cout << "\nMiddle row of the matrix is:" << endl;
	PrintMiddleRowOfMatrix(matrix1, matrixInfo);

	cout << "\nMiddle col of the matrix is:" << endl;
	PrintMiddleColOfMatrix(matrix1, matrixInfo);

	return 0;
}