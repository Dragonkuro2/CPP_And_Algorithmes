#include <iostream>
#include <cmath>

using namespace std;

int const MAX_SIZE = 10;

void PrintArray(int array[MAX_SIZE], int length) {
	cout << "Array length: " << length << endl;
	cout << "Array elements: ";
	for (int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

bool IsPalindromArray(int array[MAX_SIZE], int length) {
	for (int i = 0; i < length / 2; i++) {
		if (array[i] != array[length - 1 - i])
			return false;
	}
	return true;
}

int main() {
	int array1[MAX_SIZE] = { 10, 20, 30, 20, 10 };

	PrintArray(array1, 6);

	if (IsPalindromArray(array1, 5))
		cout << "Yes, the array is palindrom." << endl;
	else
		cout << "No, the array isn't palindrom." << endl;
	return 0;
}