#include <iostream>
#include <iomanip>

using namespace std;

void FillMatrixWithOrderNumbers(int matrix[3][3], int rows, int cols) {
	int counter = 1;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = counter;
			counter++;
		}
	}
}

void PrintMatrix(int matrix[3][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(5) << matrix[i][j];
		}
		cout << endl;
	}
}

void TransposMatrix(int matrix[3][3], int TransposMatrix[3][3], int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			TransposMatrix[i][j] = matrix[j][i];
		}
	}
}

int main() {
	int matrix[3][3], transMatrix[3][3];
	FillMatrixWithOrderNumbers(matrix, 3, 3);
	cout << "The following is 3x3 ordred matrix:" << endl;
	PrintMatrix(matrix, 3, 3);
	cout << "\n\nMatrix aftre transposing:" << endl;
	TransposMatrix(matrix, transMatrix, 3, 3);
	PrintMatrix(transMatrix, 3, 3);
	return 0;
}