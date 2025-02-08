#include <iostream>

using namespace std;

int ReadNumber() {
	int N;
	cout << "Enter a number: ";
	cin >> N;
	return N;
}

bool IsEvenNumber(int number) {
	return ((number % 2) == 0);
}

int CalculateSumEvenNumbers(int N) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (IsEvenNumber(i))
			sum += i;
	}
	return sum;
}

void PrintSumEvenNumbers(int N) {
	cout << "Sum of even numbers between 1 and " << N << " is: " << CalculateSumEvenNumbers(N) << endl;
}



int main() { // A program that prints sum of even numbers from 1 to N
	
	PrintSumEvenNumbers(ReadNumber());
	return 0;
}