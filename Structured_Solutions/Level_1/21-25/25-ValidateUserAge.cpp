#include <iostream> 

using namespace std;

int ReadAge() {
	int age;
	cout << "Enter your age: ";
	cin >> age;
	return age;
}

bool ValidateNumberInRange(int Number, int From, int To) {
	return (Number >= From && Number <= To);
}

void ValidateAge(int &Age, int From, int To) {
	while (!ValidateNumberInRange(Age, From, To)) {
		cout << Age << " Is invalid age!" << endl;
		Age = ReadAge();
	}
}

void PrintResult(int Age) {
	cout << "Your age is: " << Age << endl;
}

int main() {
	int age = ReadAge();
	ValidateAge(age, 18, 45);
	PrintResult(age);
	return 0;
}