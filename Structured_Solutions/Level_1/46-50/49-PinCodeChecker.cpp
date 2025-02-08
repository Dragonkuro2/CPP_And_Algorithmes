#include <iostream>

using namespace std;

string ReadPinCode() {
	string PinCode;
	cout << "Enter Your pinCode: ";
	cin >> PinCode;
	return PinCode;
}

bool Login() {
	string PinCode;
	do {
		PinCode = ReadPinCode();
		if (PinCode == "1234")
			return true;
		else {
			system("color 4F");
			cout << "Wrong PinCode!" << endl;
		}
	} while (PinCode != "1234");

	return false;
}

void ShowBlance() {
	int balance = 7500;
	cout << "Your balanace: $" << balance << endl;
}

int main() { // system function is not portabl nd it works just for windows

	if (Login()) {
		system("color 2F");
		ShowBlance();
	}

	return 0;
}