#include <iostream>

using namespace std;

int main() { // program that prints reversed triangle of int
	for (size_t i = 0; i < 10; i++) {
		for (size_t j = 0; j <= i; j++)
			cout << j + 1;
		cout << endl;
	}

	return 0;
}