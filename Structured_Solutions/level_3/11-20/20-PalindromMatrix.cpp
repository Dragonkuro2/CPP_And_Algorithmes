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

bool IsPalindromeMatrix(int Matrix1[3][3], stMatrixInfo matrixInfo)
{
	for (short i = 0; i < matrixInfo.rows; i++)
	{
		for (short j = 0; j < matrixInfo.cols / 2; j++)
		{
			if (Matrix1[i][j] != Matrix1[i][matrixInfo.cols - 1 - j])
				return false;
		}
	}
	return true;
}


int main() {
	int number;
	int matrix1[3][3];

	stMatrixInfo matrixInfo = { 3, 3 };
	srand((unsigned)time(NULL));

	FillMatrix(matrix1, matrixInfo); // if you want to generate random matrix uncomment this line
	cout << "Matrix 1:\n";
	PrintMatrix(matrix1, matrixInfo);

	if (IsPalindromeMatrix(matrix1, matrixInfo))
		cout << "\nThe matrix is palindrom\n";
	else
		cout << "\nThe matrix isn't palindrom\n";

	system("pause>0");

	return 0;
}