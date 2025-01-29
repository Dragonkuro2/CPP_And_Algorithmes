#include <iostream>
#include <string>

using namespace std;

string ReadName() {
	string name;
	cout << "Enter your name: ";
	getline(cin, name);

	return (name);
}

void PrintName(string name) {
	cout << "\nYour name is: " << name << endl;
}

int main() { // program that prints the name that the user enter.

	PrintName(ReadName());
	
	return 0;
}