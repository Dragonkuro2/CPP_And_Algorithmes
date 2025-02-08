#include <iostream>

using namespace std;

int ReadNumber() {
	int N;
	cout << "Enter a number: ";
	cin >> N;
	return N;
}

void PrintNumbers(int N) {
	for (int i = N; i > 0; i--)
		cout << i << endl;
}



int main() { // A program that prints numbers from N to 1
	
	PrintNumbers(ReadNumber());
	return 0;
}