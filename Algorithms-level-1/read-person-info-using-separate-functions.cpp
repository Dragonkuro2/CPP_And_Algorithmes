#include <iostream>

using namespace std;

struct stPerson {
	string FirstName;
	string LastName;
	short Age;
	string PhoneNumber;
};

void ReadInfoOnePerson(stPerson &person) {
	cout << "Enter Your FirstName: ";
	cin >> person.FirstName;
	cout << "Enter your LastName: ";
	cin >> person.LastName;
	cout << "Enter your age: ";
	cin >> person.Age;
	cout << "Enter your phone number: ";
	cin >> person.PhoneNumber;
}

void PrintInfoOnePerson(stPerson person) {
	cout << "\n****************************************\n\n";
	cout << "FirstName: " << person.FirstName << endl;
	cout << "LastName: " << person.LastName << endl;
	cout << "Age: " << person.Age << endl;
	cout << "Phone Number: " << person.PhoneNumber << endl;
	cout << "\n****************************************\n";
}

void ReadInfoAllPersons(stPerson person[2]) {
	ReadInfoOnePerson(person[0]);
	ReadInfoOnePerson(person[1]);
}

void PrintInfoAllPersons(stPerson person[2]) {
	PrintInfoOnePerson(person[0]);
	PrintInfoOnePerson(person[1]);
}

int main() {
	stPerson person[2];
	/*ReadInfoOnePerson(person[0]);
	PrintInfoOnePerson(person[0]);*/

	ReadInfoAllPersons(person);
	PrintInfoAllPersons(person);

	return 0;
}