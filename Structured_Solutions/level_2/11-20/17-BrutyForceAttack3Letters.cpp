#include <iostream>

using namespace std;

string ReadPassword() {
	string passwd;
	cout << "Please enter a password of 3 latters, All capital: ";
	cin >> passwd;
	return passwd;
}

bool GuessPassword(string OriginalPassword) {
	string password = "";
	int counter = 0;
	for (int i = 65; i < 91; i++) {
		for (int j = 65; j < 91; j++) {
			for (int z = 65; z < 91; z++) {
				password = ""; // Reset password for each new combination
				password += char(i);
				password += char(j);
				password += char(z);
				cout << "Trail[" << ++counter << "]: " << password << endl;
				if (password == OriginalPassword) {
					cout << "\nPassword is: " << password << endl;
					cout << "Found after " << counter << " Trial(s)." << endl;
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	string originalPassword = ReadPassword();
	GuessPassword(originalPassword);
	return 0;
}