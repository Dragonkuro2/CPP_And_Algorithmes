#include <iostream>
#include <cmath>

using namespace std;

int const MAX_SIZE = 10;

void AddToArray(int array[MAX_SIZE], int& length, int value) {
	if (length < MAX_SIZE) {
		array[length] = value;
		length++;
	}
	else
		cout << "The array is full" << endl;
}

void PrintArray(int array[MAX_SIZE], int length) {
	cout << "Array length: " << length << endl;
	cout << "Array elements: ";
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

bool IsExistInArray(int array[MAX_SIZE], int value, int length) {
	for (int i = 0; i < length; i++) {
		if (array[i] == value)
			return true;
	}

	return false;
}

void CopyUnrepeatedElements(int array1[MAX_SIZE], int array2[MAX_SIZE], int &length2) {
	for (int i = 0; i < 10; i++) {
		if (!IsExistInArray(array2, array1[i], length2))
			AddToArray(array2, length2, array1[i]);
	}
}

int main() {
	int array1[MAX_SIZE] = { 10, 10, 10, 50, 50, 70, 70, 70, 70, 90 };
	int array2[MAX_SIZE] = {};
	int length2 = 0;

	cout << "The first array elements: " << endl;
	PrintArray(array1, 10);

	CopyUnrepeatedElements(array1, array2, length2);
	cout << "The second array aftre copying: " << endl;
	PrintArray(array2, length2);

	return 0;
}