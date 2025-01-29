#include <iostream>
#include <string>

using namespace std;

enum enStatus { Hired, Rejected };

struct stPerson {
	string name;
	short age = 18; // intialazing with age of 18
	bool HasDriverLicense = false; // intialazing with false
};

stPerson ReadInfo() {
	stPerson person;
	cout << "Enter your name: ";
	getline(cin, person.name);
	cout << "Enter your age: ";
	cin >> person.age;
	cout << "Do you have driver license (Yes = 1, No = 0): ";
	cin >> person.HasDriverLicense;

	return person;
}

enStatus GetStatus(stPerson person) {
	if (person.age > 21 && person.HasDriverLicense)
		return enStatus::Hired;
	else
		return enStatus::Rejected;
}

string GetStatusString(enStatus status) {
	return (status == enStatus::Hired) ? "Hired" : "Rejected";
}

void PrintInfo(stPerson person, enStatus status) {
	cout << "\n********************************\n";
	cout << "Name: " << person.name << endl;
	cout << "Age: " << person.age << endl;
	cout << "Has driver Licese: " << person.HasDriverLicense << endl;
	cout << "Status: " << GetStatusString(status) << endl;
	cout << "********************************\n";
}

void PrintStatus(stPerson person) {
	enStatus status = GetStatus(person);

	PrintInfo(person, status);
}


int main() { // A program that checks the status of the user and show his infos

	PrintStatus(ReadInfo());

	return 0;
}