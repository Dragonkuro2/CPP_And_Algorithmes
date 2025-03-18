#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

enum enMenuOption { QiuckWithdraw = 1, NormalWithdraw = 2, Deposit = 3, CheckBalance = 4, Logout = 5};

const string filename = "ClientData.txt";
const string delim = "#//#";

struct stClient {
	string AccNumber;
	string PinCode;
	string Username;
	string PhoneNumber;
	float Balance;
};

struct stLoginInfo {
	string AccNumber;
	string PinCode;
};

struct stClientInfo {
	vector <stClient> vClients;
	short Index;
};

stClientInfo CurrentClient;

void PrintAtmMenuScreen();
void LogoutClient();

int ReadNumber(string message) {
	int number;
	cout << message;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!, " << message;
		cin >> number;
	}

	return number;
}

int ReadNumberInRange(string message, int From, int To) {
	int number;
	do {
		number = ReadNumber(message);
		if (number < From || number > To)
			cout << "Your choice is out of range, please enter a valid option." << endl;
	} while (number < From || number > To);

	return number;
}

int ReadPositiveNumber(string message) {
	int number;
	do {
		number = ReadNumber(message);
		if (number < 0)
			cout << "Please Enter a positive number, Try Again." << endl;
	} while (number < 0);
	return number;
}

vector <string> SplitLine(string line, string delim) {
	vector <string> vText;
	string sWord = "";
	int pos = 0;
	while ((pos = line.find(delim)) != string::npos) {
		sWord = line.substr(0, pos);
		vText.push_back(sWord);
		line.erase(0, pos + delim.length());
	}

	if (line != "")
		vText.push_back(line);

	return vText;
}

stClient ConvertLineToRecord(string line, string delim) {
	vector <string> vText = SplitLine(line, delim);
	stClient ClientInfo;

	ClientInfo.AccNumber = vText[0];
	ClientInfo.PinCode = vText[1];
	ClientInfo.Username = vText[2];
	ClientInfo.PhoneNumber = vText[3];
	ClientInfo.Balance = stof(vText[4]);

	return ClientInfo;
}

string ConvertRecordToLine(stClient ClinetInfo, string delim) {
	string line = "";
	line += ClinetInfo.AccNumber + delim;
	line += ClinetInfo.PinCode + delim;
	line += ClinetInfo.Username + delim;
	line += ClinetInfo.PhoneNumber + delim;
	line += to_string(ClinetInfo.Balance);

	return line;
}

vector <stClient> LoadRecordsFromFile(string filename, string delim) {
	vector <stClient> vClients;
	fstream MyFile;
	MyFile.open(filename, ios::in);
	if (MyFile.is_open()) {
		string line = "";
		while (getline(MyFile, line)) {
			vClients.push_back(ConvertLineToRecord(line, delim));
		}
		MyFile.close();
	}
	else { // if the file doesn't exist I'll create it
		MyFile.open(filename, ios::out);
		if (MyFile.is_open())
			MyFile.close();
		else // if the file doesn't want to be created I'll say that it doesn't want to open.
			cout << "\nError opening the file " << filename << endl;
	}

	return vClients;
}

bool UpdateClientDataFile(vector <stClient> &vClients, string filename) {
	fstream MyFile;
	MyFile.open(filename, ios::out);
	if (MyFile.is_open()) {
		for (stClient& client : vClients) {
			MyFile << ConvertRecordToLine(client, delim) << endl;
		}
		MyFile.close();
		return true;
	}
	else
		return false;
}

void PrintCurrentBalance() {
	cout << "\nYour current balanace is: " << CurrentClient.vClients[CurrentClient.Index].Balance << "\n\n";
}

void ResetScreen() {
	system("cls");
}

void PrintQiuckWithdrawMenu() {
	cout << "===================================================\n";
	cout << "\t\t Quick Withdraw Screen:\n";
	cout << "===================================================\n";
	cout << "\t[1] 20      [2] 50\n";
	cout << "\t[3] 100     [4] 200\n";
	cout << "\t[5] 400     [6] 600\n";
	cout << "\t[7] 800     [8] 1000\n";
	cout << "\t[9] Exit.\n";
	cout << "===================================================" << endl;
}

bool WithdrawMoney(float amount) {
	if (amount > CurrentClient.vClients[CurrentClient.Index].Balance)
		return false;
	else {
		CurrentClient.vClients[CurrentClient.Index].Balance -= amount;
		return true;
	}
}

void BackToMainMenu() {
	cout << "Enter any key to back to main menu...";
	system("Pause>0");
	PrintAtmMenuScreen();
}

void ExecuteWithdraw(int amount) {
	if (WithdrawMoney(amount)) {
		if (UpdateClientDataFile(CurrentClient.vClients, filename)) {
			cout << "\nOperation Done Successfully.\n";
			PrintCurrentBalance();
		}
		else
			cout << "Error modifying your balance, please try later.\n";
	}
	else {
		cout << "Operation failed, the amount you choose is bigger than your balance.\n";
	}
}

void PrintQuickWithdrawScreen() {
	ResetScreen();
	PrintQiuckWithdrawMenu();
	PrintCurrentBalance();
	int option = ReadNumberInRange("Enter your option: ", 1, 9);

	int amounts[] = { 20, 50, 100, 200, 400, 600, 800, 1000 };
	
	if (option != 9) {
		int choice = ReadNumberInRange("Are you sure you want to performe this transaction [0]:No [1]:Yes : ", 0, 1);
		if (choice == 1) {
			ExecuteWithdraw(amounts[option - 1]);
		}
		else {
			cout << "Operation cancelled successfully.\n";
		}
	}
	BackToMainMenu();
}

bool IsFiveMutiple(int number) {
	return number % 5 == 0;
}

void PrintNormalWithdrawScreen() {
	int amount;

	ResetScreen();
	cout << "===================================================\n";
	cout << "\t\t Normal Withdraw Screen:\n";
	cout << "===================================================\n";
	
	PrintCurrentBalance(); // print the balance of the client to let him know what operation can do

	do {
		amount = ReadPositiveNumber("Enter an amount mutiple of 5's: ");
	} while (!IsFiveMutiple(amount)); // keep asking the client to enter the amount while the number isn't 5's mutiple
	
	int choice = ReadNumberInRange("Are you sure you want to performe this transaction [0]:No [1]:Yes : ", 0, 1);
	if (choice == 1)
		ExecuteWithdraw(amount);
	else
		cout << "Operation cancelled successfully.\n";

	BackToMainMenu(); // back to main menu after transaction done.
}

void PrintCheckBalanceScreen() {
	ResetScreen();
	cout << "===================================================\n";
	cout << "\t\t Check Balance Screen:\n";
	cout << "===================================================\n";
	PrintCurrentBalance();
	BackToMainMenu();
}

void PrintDepositScreen() {
	ResetScreen();
	cout << "===================================================\n";
	cout << "\t\t Deposit Screen:\n";
	cout << "===================================================\n";
	PrintCurrentBalance();

	int amount = ReadPositiveNumber("Enter the amount to deposit: ");
	int choice = ReadNumberInRange("Are you sure you want to perform this transaction [0]:No [1]:Yes ", 0, 1);
	if (choice == 1) {
		CurrentClient.vClients[CurrentClient.Index].Balance += amount;
		if (UpdateClientDataFile(CurrentClient.vClients, filename)) {
			cout << "\nOperation Done Successfully.\n";
			PrintCurrentBalance();
		}
		else
			cout << "Error modifying your balance, please try later.\n";
	}
	else
		cout << "Operation Cancelled Successfully.\n";
	
	BackToMainMenu();
}

void PrintAtmMenu() {
	cout << "===================================================\n";
	cout << "\t\t ATM Main Menu Screen:\n";
	cout << "===================================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "===================================================" << endl;
}

void ExecuteOption(enMenuOption option) {
	switch (option) {
	case enMenuOption::QiuckWithdraw:
		PrintQuickWithdrawScreen();
		break;
	case enMenuOption::NormalWithdraw:
		PrintNormalWithdrawScreen();
		break;
	case enMenuOption::Deposit:
		PrintDepositScreen();
		break;
	case enMenuOption::CheckBalance:
		PrintCheckBalanceScreen();
		break;
	case enMenuOption::Logout:
		LogoutClient();
		break;
	default:
		cout << "Invalid Option!\n";
		break;
	}
}

void PrintAtmMenuScreen() {
	short choice;

	ResetScreen();
	PrintAtmMenu();
	choice = ReadNumberInRange("Enter your choice: ", 1, 5);
	ExecuteOption((enMenuOption)choice);
}

void PrintLoginScreen() {
	ResetScreen();
	cout << "---------------------------------------------------\n";
	cout << "\t\t Login Screen:\n";
	cout << "---------------------------------------------------\n";
}

string StringToLower(string text) {
	for (int i = 0; i < text.length(); i++)
		text[i] = tolower(text[i]);
	return text;
}

int SearchClientIndex(vector <stClient> &vClients, stLoginInfo logInfo) {
	int counter = 0;
	for (stClient& client : vClients) {
		if ((StringToLower(client.AccNumber) == StringToLower(logInfo.AccNumber)) &&
			(StringToLower(client.PinCode) == StringToLower(logInfo.PinCode)))
			return counter;

		counter++;
	}
	return -1;
}

stLoginInfo ReadLoginInfo() {
	stLoginInfo info;
	cout << "\nEnter Your Account Number: ";
	getline(cin >> ws, info.AccNumber);
	cout << "Enter Your Pin Code      : ";
	getline(cin >> ws, info.PinCode);
	return info;
}

void Login() {
	stLoginInfo logInfo;
	
	PrintLoginScreen();
	logInfo = ReadLoginInfo();

	CurrentClient.vClients = LoadRecordsFromFile(filename, delim);
	CurrentClient.Index = SearchClientIndex(CurrentClient.vClients, logInfo);

	while (CurrentClient.Index == -1) {
		PrintLoginScreen();
		cout << "\nInvalid Account Number or Password!\n";
		logInfo = ReadLoginInfo();
		CurrentClient.Index = SearchClientIndex(CurrentClient.vClients, logInfo);
	}

	PrintAtmMenuScreen();
}

void LogoutClient() {
	ResetScreen();
	Login();
}


int main() {

	Login();

	return 0;
}