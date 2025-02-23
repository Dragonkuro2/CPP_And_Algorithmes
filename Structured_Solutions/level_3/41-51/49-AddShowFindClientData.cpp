#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

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
		cout << "Data added succefully: " << endl;
	}
	else
		cerr << "Error opening file for writing: " << filename << endl;
}

void AddUser(string FileName) {
	stUserInfo info = GetNewUserData();
	SaveInfoToFile(info, FileName);

	int option = ReadNumberInRange("Do you want to add more clients [0]:No [1]:Yes : ", 0, 1);
	if (option == 1) {
		ResetScreen();
		AddUser(FileName);
	}
}

// the functions from here are for getting info from our file data
vector <string> SplitStringToVector(string text, string delim) {
	vector <string> vText;
	string sWord = "";
	int pos = 0;
	while ((pos = text.find(delim)) != string::npos) {
		sWord = text.substr(0, pos);
		vText.push_back(sWord);
		text.erase(0, pos + delim.length());
	}
	if (text != "")
		vText.push_back(text);
	return vText;
}

stUserInfo ConvertLineToRecord(string text, string delim) {
	stUserInfo info;
	vector <string> vText = SplitStringToVector(text, delim);
	info.AccNumber = vText[0];
	info.PinCode = vText[1];
	info.UserName = vText[2];
	info.Phone = vText[3];
	info.balance = stod(vText[4]);
	return info;
}

vector <stUserInfo> LoadClientsData(string filename) {
	vector <stUserInfo> vClients;
	string line;

	fstream MyFile;
	MyFile.open(filename, ios::in);
	if (MyFile.is_open()) {
		
		while (getline(MyFile, line)) {
			vClients.push_back(ConvertLineToRecord(line, "#//#")); // convert from vector to struct and then push the data to the vector
		}
		MyFile.close();
	}
	return vClients;
}

void PrintClientData(stUserInfo info) {
	cout << "| " << setw(15) << left << info.AccNumber;
	cout << "| " << setw(10) << left << info.PinCode;
	cout << "| " << setw(40) << left << info.UserName;
	cout << "| " << setw(12) << left << info.Phone;
	cout << "| " << setw(12) << left << info.balance;
	cout << endl;
}

void PrintAllClientData(string FileName) {
	vector <stUserInfo> vClients = LoadClientsData(FileName);
	cout << "\n\t\t\t\tClient List (" << vClients.size() << ") Client(s).";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	cout << "| " << left << setw(15) << "Accout Number";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n_______________________________________________________";
	cout << "_________________________________________\n" << endl;
	for (int i = 0; i < vClients.size(); i++) {
		PrintClientData(vClients[i]);
	}
	cout << "_______________________________________________________";
	cout << "_________________________________________\n" << endl;
}

void PrintClientDetails(stUserInfo client) {
	cout << "\nThe following are the client details:\n\n";
	cout << "Account number : " << client.AccNumber << endl;
	cout << "Pin code       : " << client.PinCode << endl;
	cout << "Name           : " << client.UserName << endl;
	cout << "Phone          : " << client.Phone << endl;
	cout << "Account Balance: " << client.balance << endl;
}

int FindClientAddress(vector <stUserInfo> vClients, string AccNumber) {
	for (int i = 0; i < vClients.size(); i++) {
		if (vClients[i].AccNumber == AccNumber)
			return i;
	}
	return -1;
}

void FindClient(string filename) {
	vector <stUserInfo> vClients = LoadClientsData(filename);
	string AccNumber;

	cout << "Enter the account number of the client: ";
	cin >> AccNumber;

	int ClientAddress = FindClientAddress(vClients, AccNumber);
	if (ClientAddress != -1) {
		PrintClientDetails(vClients[ClientAddress]);
	}
	else
		cout << "Client with account number (" << AccNumber << ") Not Found!" << endl;
}

int main() {
	stUserInfo info;
	const string FileName = "Data.txt"; // enter here the name of the file you want to use

	AddUser(FileName);
	FindClient(FileName);
	PrintAllClientData(FileName);

	return 0;
}