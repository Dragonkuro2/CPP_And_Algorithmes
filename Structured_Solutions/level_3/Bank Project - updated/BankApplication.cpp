#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

enum enMenuOptions { ShowList = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transaction = 6, ExistMenu = 7};

// Function prototypes (declarations)
void MainMenuScreen();
void BackToMenu();
void PrintClientsListMenuScreen();
void ExecuteMenuOption(enMenuOptions option);
void PrintAddScreen();
void PrintDeleteScreen();
void PrintUpdateScreen();
void PrintFindScreen();
void PrintEndScreen();
void BackToTransactionScreen();
void PrintTransactionsMenuScreen();

struct stClient {
	string AccNumber;
	string PinCode;
	string UserName;
	string Phone;
	double Balance = 0;
};

string filename = "ClientData.txt"; // you can change the storage file from here
string delim = "#//#"; // for me I prefer the delemetre to be like that if you want to change it's okay

int ReadNumber(string message) {
	int number;
	cout << message;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!" << endl;
		cout << message;
		cin >> number;
	}
	return number;
}

double ReadDouble(string message) {
	double number;
	cout << message;
	cin >> number;

	// Clear input buffer if invalid (e.g., user enters text)
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input! Enter a numeric value: ";
		cin >> number;
	}

	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer after valid input
	return number;
}

int ReadNumberInRange(string message, int From, int To) {
	int number;
	do {
		number = ReadNumber(message);
		if (number < From || number > To)
			cout << "Enter a valid option!" << endl;
	} while (number < From || number > To);

	return number;
}

void ResetScreen() {
	system("cls");
}

vector <string> SplitString(string line, string delim) {
	vector <string> vLine;
	string sWord = "";
	int pos = 0;

	while ((pos = line.find(delim)) != string::npos) {
		sWord = line.substr(0, pos);
		vLine.push_back(sWord);
		line.erase(0, pos + delim.length());
	}
	if (line != "")
		vLine.push_back(line);

	return vLine;
}

stClient ConvertLineToRecord(string line, string delim) {
	stClient client;
	vector <string> vLine = SplitString(line, delim);
	client.AccNumber = vLine[0];
	client.PinCode = vLine[1];
	client.UserName = vLine[2];
	client.Phone = vLine[3];
	client.Balance = stod(vLine[4]);

	return client;
}

vector <stClient> LoadRecordsFromFile(string filename, string delim) {
	vector <stClient> vClients;
	fstream MyFile;
	string line;

	MyFile.open(filename, ios::in);
	if (MyFile.is_open()) { // check if the file exist
		while (getline(MyFile, line)) {
			vClients.push_back(ConvertLineToRecord(line, delim)); //convert the line to a record before pushing to the vector
		}
		MyFile.close();
	}
	else { // if it doesn't exist I'll try to create one
		MyFile.open(filename, ios::out);
		if (MyFile.is_open())
			MyFile.close();
		else
			cout << "\nError openning file: " << filename << endl;
	}

	return vClients;
}

void PrintClientInfo(stClient client) {
	cout << "| " << left << setw(20) << client.AccNumber;
	cout << "| " << left << setw(14) << client.PinCode;
	cout << "| " << left << setw(40) << client.UserName;
	cout << "| " << left << setw(16) << client.Phone;
	cout << "| " << left << fixed << setprecision(2) << setw(14) << client.Balance;
	cout << endl;
}

void PrintClientsList(string filename, string delim) {
	vector <stClient> vClients = LoadRecordsFromFile(filename, delim);

	cout << "\n\t\t\t\t\t\tClient List (" << vClients.size() << ") Clients:\n";
	cout << "\n______________________________________________________________________";
	cout << "__________________________________________\n\n";
	cout << "| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(14) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(16) << "Phone";
	cout << "| " << left << setw(12) << "Balance";
	cout << "\n______________________________________________________________________";
	cout << "__________________________________________\n\n";

	for (int i = 0; i < vClients.size(); i++) {
		PrintClientInfo(vClients[i]);
	}

	cout << "______________________________________________________________________";
	cout << "__________________________________________\n";
}

int GetClientAddress(string AccNumber) {
	vector <stClient> vClients = LoadRecordsFromFile(filename, delim);
	for (int i = 0; i < vClients.size(); i++) {
		if (vClients[i].AccNumber == AccNumber)
			return i;
	}
	return -1;
}

stClient GetNewClientInfo() {
	stClient client;
	while (true) {
		cout << "Enter Account Number: ";
		getline(cin >> ws, client.AccNumber);
		if (GetClientAddress(client.AccNumber) == -1) { // check if the account number is already exist
			break;
		}
		cout << "Client with [" << client.AccNumber << "] is Already exist!" << endl;
	}

	cout << "Enter Pin Code: ";
	getline(cin >> ws, client.PinCode);
	cout << "Enter client name: ";
	getline(cin >> ws, client.UserName);
	cout << "Enter Phone Number: ";
	getline(cin, client.Phone);
	client.Balance = ReadDouble("Enter balance: ");

	return client;
}

string ConvertRecordToLine(stClient client, string delim) {
	string line = "";
	line += client.AccNumber + delim;
	line += client.PinCode + delim;
	line += client.UserName + delim;
	line += client.Phone + delim;
	line += to_string(client.Balance);
	return line;
}

bool UpdateDataFile(string filename, string delim, vector <stClient>& vClients) {
	fstream MyFile;
	MyFile.open(filename, ios::out);
	if (MyFile.is_open()) {
		for (stClient& Record : vClients) {
			MyFile << ConvertRecordToLine(Record, delim) << endl;
		}
		MyFile.close();
	}
	else {
		cout << "Error openning file: " << filename << endl;
		return false;
	}

	return true;
}

void AddClient(string filename, string delim) {
	while (true) {
		stClient client = GetNewClientInfo();
		vector <stClient> vClients = LoadRecordsFromFile(filename, delim); // get the existing clients and convert them to vectors

		vClients.push_back(client); // then add to this vector our new client
		if (UpdateDataFile(filename, delim, vClients)) { // and then update our data file
			int choice = ReadNumberInRange("Client added successfully. Do you want to add more clients [0]:No [1]:Yes : ", 0, 1);
			if (choice == 0)
				break;
		}
	}
}

string ReadAccNumber() {
	string AccNumber;
	cout << "Enter Account Number: ";
	cin >> AccNumber;
	return AccNumber;
}

void PrintClientDetails(stClient client) {
	cout << "\nThe following are the client details:\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Account Number: " << client.AccNumber << endl;
	cout << "Pin Code      : " << client.PinCode << endl;
	cout << "Client name   : " << client.UserName << endl;
	cout << "Phone         : " << client.Phone << endl;
	cout << "Balance       : " << client.Balance << endl;
	cout << "-----------------------------------------------------------\n\n";
}

void DeleteClient(string filename, string delim) {
	string AccNumber = ReadAccNumber();
	int ClientAddress = GetClientAddress(AccNumber); // check if this client is exist
	int choice;

	if (ClientAddress != -1) {
		vector <stClient> vClients = LoadRecordsFromFile(filename, delim);
		PrintClientDetails(vClients[ClientAddress]);

		choice = ReadNumberInRange("Are You SURE you want to delete this user [0]:No [1]:Yes : ", 0, 1);

		if (choice == 1) {
			vClients.erase(vClients.begin() + ClientAddress);
			if (UpdateDataFile(filename, delim, vClients)) {
				cout << "Client deleted successfully.\n";
			}
			else
				cout << "Error deleting client [" << AccNumber << "].\n";
		}
		else
			cout << "Operation cancelled." << endl;
		
	}
	else
		cout << "Client doesn't exist";
}

void UpdateClientDetails(stClient& client) {
	cout << "\nEnter Pin code    : ";
	cin >> client.PinCode;
	cout << "Enter client name : ";
	cin.ignore();
	getline(cin, client.UserName);
	cout << "Enter phone number: ";
	cin >> client.Phone;
	client.Balance = ReadDouble("Enter balance     : "); // read balance
}

void UpdateClient(string filename, string delim) {
	string AccNumber = ReadAccNumber();
	int ClientAddress = GetClientAddress(AccNumber); // check if this client is exist
	int choice;

	if (ClientAddress != -1) {
		vector <stClient> vClients = LoadRecordsFromFile(filename, delim);
		PrintClientDetails(vClients[ClientAddress]);

		choice = ReadNumberInRange("Are You SURE you want to update this user info's [0]:No [1]:Yes : ", 0, 1);

		if (choice == 1) {
			UpdateClientDetails(vClients[ClientAddress]); // update the client details by reference
			if (UpdateDataFile(filename, delim, vClients)) { // regenerate to data file
				cout << "Client updated successfully.\n";
			}
			else
				cout << "Error updating client [" << AccNumber << "].\n";
		}
		else
			cout << "Operation cancelled." << endl;
	}
	else
		cout << "Client doesn't exist";
}

void FindClient(string filename, string delim) {
	string AccNumber = ReadAccNumber();
	int ClientAddress = GetClientAddress(AccNumber);
	if (ClientAddress != -1) {
		vector <stClient> vClient = LoadRecordsFromFile(filename, delim);
		PrintClientDetails(vClient[ClientAddress]);
	}
	else
		cout << "Client didn't found!" << endl;
}

// menu functions
void PrintMainMenu() {
	cout << "================================================\n";
	cout << "\t\tMain Menu Screen:\n";
	cout << "================================================\n";
	cout << "\t[1] Show Clinets List.\n";
	cout << "\t[2] Add New Client.\n";
	cout << "\t[3] Delete Client.\n";
	cout << "\t[4] Update Client Info.\n";
	cout << "\t[5] Find Client.\n";
	cout << "\t[6] Transactions.\n";
	cout << "\t[7] Exit.\n";
	cout << "================================================\n";
}

void MainMenuScreen() {
	short option;
	PrintMainMenu();
	option = ReadNumberInRange("Enter your option: ", 1, 7);
	ExecuteMenuOption(enMenuOptions(option));
}

void BackToMenu() {
	cout << "\n\nPress any key to go back to menu...";
	system("pause>0");
	ResetScreen();
	MainMenuScreen();
}

void PrintClientsListMenuScreen() {
	ResetScreen(); //clear the screen
	PrintClientsList(filename, delim);
	BackToMenu();
}

void PrintAddScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\tAdd New Client Screen:\n";
	cout << "-----------------------------------------------------------\n\n";
	cout << "Adding New Client:" << endl;
	AddClient(filename, delim);
	cout << "\n-----------------------------------------------------------\n";
	BackToMenu();
}

void PrintDeleteScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\tDelete Client Screen:\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Delete Client:\n";
	DeleteClient(filename, delim);
	cout << "\n-----------------------------------------------------------\n";
	BackToMenu();
}

void PrintUpdateScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\tUpdate Client Info Screen:\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Update Client Info:\n";
	UpdateClient(filename, delim);
	cout << "\n-----------------------------------------------------------\n";
	BackToMenu();
}

void PrintFindScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\tFind Client Screen:\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Client Info:\n";
	FindClient(filename, delim);
	BackToMenu();
}

enum enTransation { deposit = 1, withdraw = 2, totalBalance = 3, mainMenu = 4 };


void BackToTransactionScreen() {
	cout << "\nEnter any key to back to transaction menu...";
	system("pause>0");
	ResetScreen();
	PrintTransactionsMenuScreen();
}

void DepositMoney() {
	string AccNumber = ReadAccNumber();
	int ClientIndex = GetClientAddress(AccNumber);
	double amount;

	if (ClientIndex != -1) {
		vector <stClient> vClients = LoadRecordsFromFile(filename, delim);
		PrintClientDetails(vClients[ClientIndex]);

		while (true) {// check if the user enter a valid number
			amount = ReadDouble("Enter deposit amount: ");
			if (amount >= 0)
				break;
			else
				cout << "Invalid Amount!" << endl;
		}

		int option = ReadNumberInRange("Are you SURE you want to performe this transaction [0]:No [1]:Yes : ", 0, 1);
		if (option == 1) {
			vClients[ClientIndex].Balance += amount;
			UpdateDataFile(filename, delim, vClients);// update the data file after doing the transaction
			cout << "Transaction Done." << endl;
		}
		else
			cout << "Transaction cancelled.\n";

	}
	else
		cout << "Client didn't found!\n";

	BackToTransactionScreen(); // back to transaction menu after performing the operation
}

void DepositScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\tDeposit Screen:\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Client Info:\n";
	DepositMoney();
}

bool CheckAmount(double TotalAmount, double& WithdrawAmount) {

	while (true) {// check if the user enter a valid number
		WithdrawAmount = ReadDouble("Enter withdraw amount: ");
		if (WithdrawAmount >= 0)
			break;
		else
			cout << "Invalid Amount!" << endl;
	}

	return TotalAmount >= WithdrawAmount;
}

void WithdrawMoney() {
	string AccNumber = ReadAccNumber();
	int ClientIndex = GetClientAddress(AccNumber);
	double amount;

	if (ClientIndex != -1) {
		vector <stClient> vClients = LoadRecordsFromFile(filename, delim);
		PrintClientDetails(vClients[ClientIndex]);
		if (CheckAmount(vClients[ClientIndex].Balance, amount)) {// read the amount of withdraw from the user and check if it was valable
			int option = ReadNumberInRange("Are you SURE you want to performe this transaction [0]:No [1]:Yes : ", 0, 1);
			if (option == 1) {
				vClients[ClientIndex].Balance -= amount;
				UpdateDataFile(filename, delim, vClients);// update the data file after doing the transaction
				cout << "Transaction Done." << endl;
			}
			else
				cout << "Transaction cancelled.\n";
			
		}
		else
			cout << "\n\nInvalid operation: withdraw amount bigger than original balance" << endl;
	}
	else
		cout << "Client didn't found!\n";

	BackToTransactionScreen();
}

void WithdrawScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\tWithdraw Screen:\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Client Info:\n";
	WithdrawMoney();
}

void PrintClientBalanceInfo(stClient client) {
	cout << "| " << left << setw(20) << client.AccNumber;
	cout << "| " << left << setw(40) << client.UserName;
	cout << "| " << left << setw(30) << client.Balance;
	cout << endl;
}

double SumBalances(vector <stClient> vClients) {
	double Sum = 0;
	for (int i = 0; i < vClients.size(); i++) {
		Sum += vClients[i].Balance;
	}
	return Sum;
}

void PrintClientsBalances(string filename, string delim) {
	vector <stClient> vClients = LoadRecordsFromFile(filename, delim);

	cout << "\n\t\t\t\t\t\tBalances List (" << vClients.size() << ") Clients:\n";
	cout << "\n______________________________________________________________________";
	cout << "__________________________________________\n\n";
	cout << "| " << left << setw(20) << "Account Number";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << fixed << setprecision(2) << setw(30) << "Balance";
	cout << "\n______________________________________________________________________";
	cout << "__________________________________________\n\n";

	for (int i = 0; i < vClients.size(); i++) {
		PrintClientBalanceInfo(vClients[i]);
	}

	cout << "______________________________________________________________________";
	cout << "__________________________________________\n";
	cout << "\n\t\t\t\t\t\tTotal Balances = " << SumBalances(vClients) << endl;
}


void PrintTotalBalanacesScreen() {
	ResetScreen();
	PrintClientsBalances(filename, delim);
	BackToTransactionScreen();
}

void ExecuteTransactionsMenuOption(enTransation option) {
	switch (option) {
	case enTransation::deposit:
		DepositScreen();
		break;
	case enTransation::withdraw:
		WithdrawScreen();
		break;
	case enTransation::totalBalance:
		PrintTotalBalanacesScreen();
		break;
	case enTransation::mainMenu:
		ResetScreen();
		MainMenuScreen();
		break;
	default:
		cout << "Invalid option!" << endl;
		break;
	}
}

void PrintTransactionMenu() {
	cout << "================================================\n";
	cout << "\t\tTransactions Menu Screen:\n";
	cout << "================================================\n";
	cout << "\t[1] Deposit.\n";
	cout << "\t[2] Withdraw.\n";
	cout << "\t[3] Total balance.\n";
	cout << "\t[4] Main Menu.\n";
	cout << "================================================\n";
}

void PrintTransactionsMenuScreen() {
	int choice;
	ResetScreen();
	PrintTransactionMenu();
	choice = ReadNumberInRange("Enter your option: ", 1, 4);
	ExecuteTransactionsMenuOption((enTransation)choice);
}

void PrintEndScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\tEnd Screen :)\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Press any key to exist...";
	system("pause>0");
}

void ExecuteMenuOption(enMenuOptions option) {
	switch (option) {
	case enMenuOptions::ShowList:
		PrintClientsListMenuScreen();
		break;
	case enMenuOptions::Add:
		PrintAddScreen();
		break;
	case enMenuOptions::Delete:
		PrintDeleteScreen();
		break;
	case enMenuOptions::Update:
		PrintUpdateScreen();
		break;
	case enMenuOptions::Find:
		PrintFindScreen();
		break;
	case enMenuOptions::Transaction:
		PrintTransactionsMenuScreen();
		break;
	case enMenuOptions::ExistMenu:
		PrintEndScreen();
		break;
	default:
		cout << "Invalid option!" << endl;
		break;
	}
}


int main() {
	MainMenuScreen();
	return 0;
}