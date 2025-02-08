#include <iostream>
#include <string>

using namespace std;

struct stPerson {
	string FirstName;
	string LastName;
};

stPerson GetInfo() {
	stPerson person;
	cout << "Enter you first name: ";
	cin >> person.FirstName;
	cout << "Enter your last name: ";
	cin >> person.LastName;
	return person;
}

void PrintName(stPerson person) {
	cout << "Your name is: " << person.FirstName << " " << person.LastName << endl;
}

int main() {

	PrintName(GetInfo());

	return 0;
}