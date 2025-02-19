#include <iostream>
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
			matrix[i][j] = RandomNumberInRange(0, 9);
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

bool IsMatrixScalar(int matrix1[3][3], stMatrixInfo matrixInfo) {
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			if ((i == j) && (matrix1[i][j] != matrix1[0][0]))
				return false;
			else if (i != j && matrix1[i][j] != 0)
				return false;
		}
	}

	return true;
}

void ValidateMatrixScalarety(int matrix1[3][3], stMatrixInfo matrixInfo) {
	if (IsMatrixScalar(matrix1, matrixInfo))
		cout << "\nYes: matrices is scalar.\n";
	else
		cout << "\nNo: matrices is not scalar.\n";
}

int main() {
	int matrix1[3][3] = {
		{9, 0, 0},
		{0, 9, 0},
		{0, 0, 9}
	};

	stMatrixInfo matrixInfo = {3, 3};
	srand((unsigned)time(NULL));

	// FillMatrix(matrix1, matrixInfo); // if you want to generate random matrix uncomment this line
	cout << "Matrix:\n";
	PrintMatrix(matrix1, matrixInfo);

	ValidateMatrixScalarety(matrix1, matrixInfo);

	system("pause>0");

	return 0;
}