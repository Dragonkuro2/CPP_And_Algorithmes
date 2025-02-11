#include <iostream>

using namespace std;

void PrintLetters() {
	for (int i = 65; i < 91; i++) {
		for (int j = 65; j < 91; j++) {
			for (int z = 65; z < 91; z++)
				cout << (char)i << (char)j << (char)z << endl;
		}
	}
}

int main() {
	PrintLetters();
	return 0;
}