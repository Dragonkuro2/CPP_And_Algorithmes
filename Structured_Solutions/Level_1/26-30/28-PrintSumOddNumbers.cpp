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

int CalculateSumOddNumbers(int N) {
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (!IsEvenNumber(i))
			sum += i;
	}
	return sum;
}

void PrintSumOddNumbers(int N) { // A program that calculate the sum of odd numbers
	cout << "Sum of odd numbers between 1 and " << N << " is: " << CalculateSumOddNumbers(N) << endl;
}



int main() { // A program that prints numbers from N to 1
	
	PrintSumOddNumbers(ReadNumber());
	return 0;
}