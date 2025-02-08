#include <iostream>

using namespace std;

int ReadNumber() {
	int N;
	cout << "Enter a number: ";
	cin >> N;
	return N;
}

void PrintNumbers(int N) {
	for (int i = 0; i < N; i++)
		cout << i + 1 << endl;
}



int main() { // A program that prints numbers from 1 to N
	
	PrintNumbers(ReadNumber());
	return 0;
}