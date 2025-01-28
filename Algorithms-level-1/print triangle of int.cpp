#include <iostream>

using namespace std;

int main() { // program that prints a triangle of integares
	for (size_t i = 10; i > 0; i--) {
		for (size_t j = 0; j < i; j++)
			cout << j + 1;
		cout << endl;
	}

	return 0;
}