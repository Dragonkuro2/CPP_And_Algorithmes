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

int SumOfMatrixNumbers(int matrix[3][3], stMatrixInfo matrixInfo) {
	int sum = 0;
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			sum += matrix[i][j];
		}
	}
	return sum;
}

bool IsEqualMatrices(int matrix1[3][3], int matrix2[3][3], stMatrixInfo matrixInfo) {
	return SumOfMatrixNumbers(matrix1, matrixInfo) == SumOfMatrixNumbers(matrix2, matrixInfo);
}

void PrintResult(int matrix1[3][3], int matrix2[3][3], stMatrixInfo matrixInfo) {
	if (IsEqualMatrices(matrix1, matrix2, matrixInfo))
		cout << "\nYes: Both matrices are equal.\n";
	else
		cout << "\nNo: matrices are not equal.\n";
}

int main() {
	int matrix1[3][3], matrix2[3][3];
	stMatrixInfo matrixInfo = {3, 3};
	srand((unsigned)time(NULL));

	FillMatrix(matrix1, matrixInfo);
	cout << "The first matrix:\n";
	PrintMatrix(matrix1, matrixInfo);

	FillMatrix(matrix2, matrixInfo);
	cout << "The Second matrix:\n";
	PrintMatrix(matrix2, matrixInfo);

	cout << "\nThe sum of the elements of the matrix1 is: " << SumOfMatrixNumbers(matrix1, matrixInfo);
	cout << "\nThe sum of the elements of the matrix2 is: " << SumOfMatrixNumbers(matrix2, matrixInfo);

	PrintResult(matrix1, matrix2, matrixInfo);

	system("pause>0");

	return 0;
}