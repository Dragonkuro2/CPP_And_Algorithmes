#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct stUserInfo {
	string AccNumber;
	string PinCode;
	string UserName;
	string Phone;
	double balance;
};

int ReadNumber(string message) {
	int number;
	cout << message;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Option!" << endl;
		cout << message;
		cin >> number;
	}
	return number;
}

int ReadNumberInRange(string message, int From, int To) {
	int number;
	do {
		number = ReadNumber(message);
		if (number < From || number > To)
			cout << "Please enter a valid option.\n";
	} while (number < From || number > To);
	return number;
}

void ResetScreen() {
	system("cls");
}

stUserInfo GetNewUserData() {
	stUserInfo info;
	cout << "Enter Client informations: \n\n";
	cout << "Enter your account number: ";
	cin >> info.AccNumber;
	cout << "Enter Your pin code: ";
	cin >> info.PinCode;
	cin.ignore();
	cout << "Enter your name: ";
	getline(cin, info.UserName);
	cout << "Enter your phone number: ";
	cin >> info.Phone;
	cout << "Enter your balance: ";
	cin >> info.balance;

	return info;
}

string ConvertRecordToLine(stUserInfo info, string separator = "#//#") {
	string text = "";
	text += info.AccNumber + separator;
	text += info.PinCode + separator;
	text += info.UserName + separator;
	text += info.Phone + separator;
	text += to_string(info.balance);

	return text;
}

void SaveInfoToFile(stUserInfo client, string filename) {
	string userData = ConvertRecordToLine(client);
	fstream MyFile;
	MyFile.open(filename, std::ios::out | std::ios::app);
	if (MyFile.is_open()) {
		MyFile << userData << endl;
		MyFile.close();
		cout << "Data added succefully: ";
	}
	else
		cerr << "Error opening file for writing: " << filename << endl;
}

void AddUser() {
	stUserInfo info = GetNewUserData();
	SaveInfoToFile(info, "Data.txt");

	int option = ReadNumberInRange("Do you want to add more clients [0]:No [1]:Yes : ", 0, 1);
	if (option == 1) {
		ResetScreen();
		AddUser();
	}
}

int main() {
	stUserInfo info;
	
	AddUser();

	return 0;
}