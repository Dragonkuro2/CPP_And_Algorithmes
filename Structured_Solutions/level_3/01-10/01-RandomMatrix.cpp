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

int main() {
	srand((unsigned)time(NULL));

	int matrix[3][3];

	FillMatrix(matrix, 3, 3);
	PrintMatrix(matrix, 3, 3);

	system("pause");

	return 0;
}