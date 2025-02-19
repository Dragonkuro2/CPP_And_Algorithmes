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

int MaxNumberInMatrix(int matrix[3][3], stMatrixInfo matrixInfo) {
	int max = matrix[0][0];
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			if (matrix[i][j] > max)
				max = matrix[i][j];
		}
	}
	return max;
}

int MinNumberInMatrix(int matrix[3][3], stMatrixInfo matrixInfo) {
	int min = matrix[0][0];
	for (int i = 0; i < matrixInfo.rows; i++) {
		for (int j = 0; j < matrixInfo.cols; j++) {
			if (matrix[i][j] < min)
				min = matrix[i][j];
		}
	}
	return min;
}

int main() {
	int number;
	int matrix1[3][3], matrix2[3][3];

	stMatrixInfo matrixInfo = { 3, 3 };
	srand((unsigned)time(NULL));

	FillMatrix(matrix1, matrixInfo); // if you want to generate random matrix uncomment this line
	cout << "Matrix 1:\n";
	PrintMatrix(matrix1, matrixInfo);

	cout << "\nthe min of this matrix is: " << MinNumberInMatrix(matrix1, matrixInfo) << endl;
	cout << "\nthe max of this matrix is: " << MaxNumberInMatrix(matrix1, matrixInfo) << endl;

	system("pause>0");

	return 0;
}