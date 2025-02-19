#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int RnadomNumberInRange(int From, int To) {
	return rand() % (To - From + 1) + From;
}

void FillMatrix(int matrix[3][3], int row, int cols) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			matrix[i][j] = RnadomNumberInRange(0, 99);
		}
	}
}

void PrintMatrix(int matrix[3][3], int row, int cols) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < cols; j++) {
			cout << setw(5) << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int SumCols(int matrix[3][3], int rows, int colNumbers) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		sum += matrix[i][colNumbers];
	}
	return sum;
}

void SumColsInArray(int matrix[3][3], int rows, int cols, int array[3]) {
	for (int i = 0; i < cols; i++) {
		array[i] = SumCols(matrix, rows, i);
	}
}

void PrintColSum(int matrix[3][3], int rows, int cols) {
	int array[3];
	SumColsInArray(matrix, rows, cols, array);
	for (int i = 0; i < cols; i++) {
		cout << "Col " << i + 1 << " Sum is: " << array[i] << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	int matrix[3][3];

	FillMatrix(matrix, 3, 3);
	PrintMatrix(matrix, 3, 3);
	cout << "\n\nthe following are the sum of each colum:" << endl;
	PrintColSum(matrix, 3, 3);

	return 0;
}