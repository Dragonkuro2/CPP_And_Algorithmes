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
	int counter = 3;
	do {
		counter--;
		PinCode = ReadPinCode();
		if (PinCode == "1234")
			return true;
		else {
			system("color 4F");
			if (counter == 0)
				return false;

			cout << "Wrong PinCode!, Your have " << counter << " Tries." << endl;
		}
	} while ((PinCode != "1234") && counter > 0);

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
	else {
		cout << "Your card is blocked, please contact the bank for help!" << endl;
	}

	return 0;
}