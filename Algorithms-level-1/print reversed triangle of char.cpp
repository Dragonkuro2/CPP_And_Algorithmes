#include <iostream>

using namespace std;

int main() { // program that prints reversed triangle of char
	for (char i = 'A'; i <= 'F'; i++) {
		for (char j = 'A'; j <= i; j++)
			cout << j;
		cout << endl;
	}

	return 0;
}