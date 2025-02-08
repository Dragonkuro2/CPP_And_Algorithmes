#include <iostream>

using namespace std;

void PrintLettersAtoZ() {
	for (char ch = 'A'; ch <= 'Z'; ch++)
		cout << ch << endl;
}

int main() {
	PrintLettersAtoZ();
	return 0;
}