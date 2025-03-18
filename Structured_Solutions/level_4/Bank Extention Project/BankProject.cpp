#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

enum enMenuOptions { ShowList = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transaction = 6, ManageUsers = 7, Logout = 8 };
enum enPermissions { PerShowClientList = 1, PerAddNewClient = 2, PerDeleteClient = 4, PerUpdateClient = 8, PerFindClient = 16, PerTransactions = 32, PerManageUsers = 64 };

struct stClient {
	string AccNumber;
	string PinCode;
	string UserName;
	string Phone;
	double Balance = 0;
};

struct stUser {
	string Username;
	string password;
	int permissions = 0b0000;
};

// Function prototypes (declarations)
void MainMenuScreen(stUser UserData);
void BackToMenu(stUser UserData);
void PrintClientsListMenuScreen(stUser UserData);
void ExecuteMenuOption(enMenuOptions option, stUser UserData);
void PrintAddScreen(stUser UserData);
void PrintDeleteScreen(stUser UserData);
void PrintUpdateScreen(stUser UserData);
void PrintFindScreen(stUser UserData);
void PrintEndScreen();
void BackToTransactionScreen(stUser UserData);
void PrintTransactionsMenuScreen(stUser UserData);
void PrintLoginScreen();
void Login();
void PrintManageUserScreen(stUser UserData);
void PrintAddUserScreen();
void PrintDeleteUserScreen();
void PrintUpdateUserScreen();
void PrintFindUserScreen();
void PrintAccessDenied();

string filename = "ClientData.txt"; // you can change the storage file from here
string delim = "#//#"; // for me I prefer the delemetre to be like that if you want to change it's okay

bool HasPermission(stUser user, enPermissions permission) {
	return (user.permissions & permission) == permission;
}

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

int FindClientIndex(string AccNumber) {
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
		if (FindClientIndex(client.AccNumber) == -1) { // check if the account number is already exist
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
	int ClientAddress = FindClientIndex(AccNumber); // check if this client is exist
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
	int ClientAddress = FindClientIndex(AccNumber); // check if this client is exist
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
	int ClientAddress = FindClientIndex(AccNumber);
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
	cout << "\t[7] Manage Users.\n";
	cout << "\t[8] Logout.\n";
	cout << "================================================\n";
}

void MainMenuScreen(stUser UserData) {
	short option;
	PrintMainMenu();
	option = ReadNumberInRange("Enter your option: ", 1, 8);
	ExecuteMenuOption(enMenuOptions(option), UserData);
}

void BackToMenu(stUser UserData) {
	cout << "\n\nPress any key to go back to menu...";
	system("pause>0");
	ResetScreen();
	MainMenuScreen(UserData);
}

void PrintClientsListMenuScreen(stUser user) {
	ResetScreen(); //clear the screen

	if (HasPermission(user, enPermissions::PerShowClientList)) // check if the user has access
		PrintClientsList(filename, delim);
	else
		PrintAccessDenied();

	BackToMenu(user);
}

void PrintAddScreen(stUser user) {
	ResetScreen();

	if (HasPermission(user, enPermissions::PerAddNewClient)) { // check if the user has permissions
		cout << "-----------------------------------------------------------\n";
		cout << "\t\tAdd New Client Screen:\n";
		cout << "-----------------------------------------------------------\n\n";
		cout << "Adding New Client:" << endl;
		AddClient(filename, delim);
		cout << "\n-----------------------------------------------------------\n";
	}
	else
		PrintAccessDenied();
	
	BackToMenu(user);
}

void PrintDeleteScreen(stUser user) {
	ResetScreen();

	if (HasPermission(user, enPermissions::PerDeleteClient)) { // check the permissions
		cout << "-----------------------------------------------------------\n";
		cout << "\t\tDelete Client Screen:\n";
		cout << "-----------------------------------------------------------\n";
		cout << "Delete Client:\n";
		DeleteClient(filename, delim);
		cout << "\n-----------------------------------------------------------\n";
	}
	else
		PrintAccessDenied();
	
	BackToMenu(user);
}

void PrintUpdateScreen(stUser user) {
	ResetScreen();
	if (HasPermission(user, enPermissions::PerUpdateClient)) {
		cout << "-----------------------------------------------------------\n";
		cout << "\t\tUpdate Client Info Screen:\n";
		cout << "-----------------------------------------------------------\n";
		cout << "Update Client Info:\n";
		UpdateClient(filename, delim);
		cout << "\n-----------------------------------------------------------\n";
	}
	else
		PrintAccessDenied();
	
	BackToMenu(user);
}

void PrintFindScreen(stUser user) {
	ResetScreen();
	if (HasPermission(user, enPermissions::PerFindClient)) {
		cout << "-----------------------------------------------------------\n";
		cout << "\t\tFind Client Screen:\n";
		cout << "-----------------------------------------------------------\n";
		cout << "Client Info:\n";
		FindClient(filename, delim);
	}
	else
		PrintAccessDenied();

	BackToMenu(user);
}

enum enTransation { deposit = 1, withdraw = 2, totalBalance = 3, mainMenu = 4 };


void BackToTransactionScreen(stUser user) {
	cout << "\nEnter any key to back to transaction menu...";
	system("pause>0");
	ResetScreen();
	PrintTransactionsMenuScreen(user);
}

void DepositMoney() {
	string AccNumber = ReadAccNumber();
	int ClientIndex = FindClientIndex(AccNumber);
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
	int ClientIndex = FindClientIndex(AccNumber);
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
}

void ExecuteTransactionsMenuOption(enTransation option, stUser UserData) {
	switch (option) {
	case enTransation::deposit:
		DepositScreen();
		BackToTransactionScreen(UserData);
		break;
	case enTransation::withdraw:
		WithdrawScreen();
		BackToTransactionScreen(UserData);
		break;
	case enTransation::totalBalance:
		PrintTotalBalanacesScreen();
		BackToTransactionScreen(UserData);
		break;
	case enTransation::mainMenu:
		ResetScreen();
		MainMenuScreen(UserData);
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

void PrintTransactionsMenuScreen(stUser user) {
	int choice;
	ResetScreen();
	PrintTransactionMenu();
	choice = ReadNumberInRange("Enter your option: ", 1, 4);
	ExecuteTransactionsMenuOption((enTransation)choice, user);
	BackToMenu(user);
}

void PrintEndScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\tEnd Screen :)\n";
	cout << "-----------------------------------------------------------\n";
	cout << "Press any key to exist...";
	system("pause>0");
}

// ********************************* Login ************************************

const string UserFile = "Userdata.txt";

void UserLogout() {
	ResetScreen();
	Login();
}

void PrintAccessDenied() {
	cout << "-----------------------------------------------------------\n";
	cout << "\tAccess Denied,\n";
	cout << "\tYou don't have permissions to reach there.\n";
	cout << "\tPlease contact your admin for more informations.\n";
	cout << "-----------------------------------------------------------\n";
}

void ExecuteMenuOption(enMenuOptions option, stUser UserData) {
	switch (option) {
	case enMenuOptions::ShowList:
		PrintClientsListMenuScreen(UserData);
		break;
	case enMenuOptions::Add:
		PrintAddScreen(UserData);
		break;
	case enMenuOptions::Delete:
		PrintDeleteScreen(UserData);
		break;
	case enMenuOptions::Update:
		PrintUpdateScreen(UserData);
		break;
	case enMenuOptions::Find:
		PrintFindScreen(UserData);
		break;
	case enMenuOptions::Transaction:
		PrintTransactionsMenuScreen(UserData);
		break;
	case enMenuOptions::ManageUsers:
		PrintManageUserScreen(UserData);
		break;
	case enMenuOptions::Logout:
		UserLogout();
		break;
	default:
		cout << "Invalid option!" << endl;
		break;
	}
}

stUser ReadUserInfo() {
	stUser user;
	cout << "Enter the username: ";
	getline(cin >> ws, user.Username);
	cout << "Enter the password: ";
	getline(cin, user.password);

	return user;
}

string ConvertUserDataToLine(stUser userDate, string delim) {
	string line = "";
	line += userDate.Username + delim;
	line += userDate.password + delim;
	line += to_string(userDate.permissions);

	return line;
}

stUser ConvertLineToUserData(string line, string delim) {
	stUser userData;
	vector <string> vLine = SplitString(line, delim);
	userData.Username = vLine[0];
	userData.password = vLine[1];
	userData.permissions = stoi(vLine[2]); // convert permissions from string format to int
	return userData;
}

vector <stUser> LoadUserData(string Filename, string delim) {
	vector <stUser> vUserData;
	fstream MyFile;
	MyFile.open(Filename, ios::in);
	if (MyFile.is_open()) { // if the file exist we can raed it's content
		string line;
		while (getline(MyFile, line)) {
			vUserData.push_back(ConvertLineToUserData(line, delim)); // convert line to struct data.
		}
		MyFile.close();
	}
	else { // if the file doesn't exist we'll create an empty one.
		MyFile.open(filename, ios::out);
		if (MyFile.is_open()) {
			MyFile.close();
		}
		else
			cout << "Error: opening file " << filename << endl;
	}

	return vUserData;
}

bool UpdateUserData(vector <stUser> &vUserData, string filename, string delim) {
	fstream MyFile;
	string line;
	MyFile.open(filename, ios::out);
	if (MyFile.is_open()) {
		for (stUser& userdata : vUserData) {
			MyFile << ConvertUserDataToLine(userdata, delim) << endl;
		}
		MyFile.close();
		return true; // if the file was updated i'll return true, else we return false.
	}
	else {
		cout << "Error: openning file " << filename << endl;
		return false;
	}
}

string stringToLower(string text) {
	for (int i = 0; i < text.size(); i++) {
		text[i] = tolower(text[i]);
	}
	return text;
}

int SearchUser(vector <stUser> &vUser, string username, string password) {
	int counter = 0;
	for (stUser& user : vUser) {
		if ((stringToLower(user.Username) == stringToLower(username)) && (password == user.password))
			return counter;
		counter++;
	}
	return -1;
}

void PrintManageUsersMenu() {
	cout << "================================================\n";
	cout << "\t\tManage Users Screen:\n";
	cout << "================================================\n";
	cout << "\t[1] List Users.\n";
	cout << "\t[2] Add New User.\n";
	cout << "\t[3] Delete User.\n";
	cout << "\t[4] Update User.\n";
	cout << "\t[5] Find User.\n";
	cout << "\t[6] Back To Main Menu.\n";
	cout << "================================================\n";
}

enum enUserOptions { ListUsers = 1, AddUser = 2, DeleteUser = 3, UpdateUser = 4, FindUser = 5, BackMainMenu = 6};

void PrintUserInfo(stUser sUser) {
	cout << "| " << left << setw(40) << sUser.Username;
	cout << "| " << left << setw(30) << sUser.password;
	cout << "| " << left << setw(20) << to_string(sUser.permissions);
	cout << endl;
}

void ListAllUsers() {
	vector <stUser> vUsers = LoadUserData(UserFile, delim);
	cout << "\n\t\t\t\t\t\tUsers List (" << vUsers.size() << ") User(s):\n";
	cout << "\n______________________________________________________________________";
	cout << "__________________________________________\n\n";
	cout << "| " << left << setw(40) << "User Name";
	cout << "| " << left << setw(30) << "Password";
	cout << "| " << left << setw(20) << "Permissions";
	cout << "\n______________________________________________________________________";
	cout << "__________________________________________\n\n";
	for (stUser& sUser : vUsers) {
		PrintUserInfo(sUser);
	}
	cout << "______________________________________________________________________";
	cout << "__________________________________________\n";
}

void BackToManageUsersScreen(stUser user) {
	cout << "\n\nPress any key to go back to manage users screen...";
	system("pause>0");
	PrintManageUserScreen(user);
}


void UsersListScreen() {
	ResetScreen();
	ListAllUsers();
}

void ExecuteUserMenuOption(enUserOptions option, stUser user) {
	switch (option) {
	case enUserOptions::ListUsers:
		UsersListScreen();
		// back to amanage user screen after the end of adding new users
		BackToManageUsersScreen(user);
		break;
	case enUserOptions::AddUser:
		PrintAddUserScreen();
		BackToManageUsersScreen(user);
		break;
	case enUserOptions::DeleteUser:
		PrintDeleteUserScreen();
		BackToManageUsersScreen(user);
		break;
	case enUserOptions::UpdateUser:
		PrintUpdateUserScreen();
		BackToManageUsersScreen(user);
		break;
	case enUserOptions::FindUser:
		PrintFindUserScreen();
		BackToManageUsersScreen(user);
		break;
	case enUserOptions::BackMainMenu:
		ResetScreen();
		MainMenuScreen(user);
		break;
	default:
		cout << "Invalid option!" << endl;
		break;
	}
}

void PrintManageUserScreen(stUser user) {
	ResetScreen();
	if (HasPermission(user, enPermissions::PerManageUsers)) {
		PrintManageUsersMenu();
		short option = ReadNumberInRange("Enter your option: ", 1, 6);
		ExecuteUserMenuOption((enUserOptions)option, user);
	}
	else
		PrintAccessDenied();

	BackToMenu(user);
}

int UserIndexFinder(vector <stUser> &vUsers, string username) {
	int counter = 0;
	for (stUser& sUser : vUsers) {
		if (stringToLower(username) == stringToLower(sUser.Username))
			return counter; // if we find the user we are looking for we return it's index.
		counter++;
	}

	return -1; // if we didn't find any user with this name, return -1.
}

int SetNewPermissions(int oldPermissions, enPermissions permissions) {
	return oldPermissions | permissions;
}

int ReadPermissions() {
	int permissions = 0b000000;
	cout << "\n\n\tEnter User permissions:\n\n";
	int option = ReadNumberInRange("Do you want give him full access [0]:No [1]:Yes : ", 0, 1);
	if (option == 1)
		return -1;
	else {
		cout << "\nDo you want give him access to: " << endl;
		option = ReadNumberInRange("Show client list [0]:No [1]:Yes : ", 0, 1);
		if (option) permissions = SetNewPermissions(permissions, enPermissions::PerShowClientList);
		option = ReadNumberInRange("Add New Clients  [0]:No [1]:Yes : ", 0, 1);
		if (option) permissions = SetNewPermissions(permissions, enPermissions::PerAddNewClient);
		option = ReadNumberInRange("Delete Clients   [0]:No [1]:Yes : ", 0, 1);
		if (option) permissions = SetNewPermissions(permissions, enPermissions::PerDeleteClient);
		option = ReadNumberInRange("Update Clients   [0]:No [1]:Yes : ", 0, 1);
		if (option) permissions = SetNewPermissions(permissions, enPermissions::PerUpdateClient);
		option = ReadNumberInRange("Find Clients     [0]:No [1]:Yes : ", 0, 1);
		if (option) permissions = SetNewPermissions(permissions, enPermissions::PerFindClient);
		option = ReadNumberInRange("Transactions     [0]:No [1]:Yes : ", 0, 1);
		if (option) permissions = SetNewPermissions(permissions, enPermissions::PerTransactions);
		option = ReadNumberInRange("Manage Users     [0]:No [1]:Yes : ", 0, 1);
		if (option) permissions = SetNewPermissions(permissions, enPermissions::PerManageUsers);

		// check if the user now has all the permissions and then return -1
		if (permissions == 255)
			return -1;
	}

	return permissions;
}

stUser ReadNewUser() {
	stUser user;
	vector <stUser> vUsers = LoadUserData(UserFile, delim);
	cout << "\nEnter a username: ";
	getline(cin >> ws, user.Username);
	while (UserIndexFinder(vUsers, user.Username) != -1) { // if the index is deffrente than -1 it means that this username exist
		cout << "\nThis username is already taken." << endl;
		cout << "Enter a new username: ";
		getline(cin >> ws, user.Username);
	}

	cout << "Enter the password: ";
	getline(cin, user.password);
	user.permissions = ReadPermissions();

	return user;
}

bool AddUserToDataFile(string filename, stUser user) {
	fstream MyFile;
	MyFile.open(filename, ios::app);
	if (MyFile.is_open()) {
		string line;
		line = ConvertUserDataToLine(user, delim);
		MyFile << line << endl;
		MyFile.close();
		return true;
	}
	else {
		cout << "Error: openning file " << filename << endl;
		return false;
	}
}

void PrintAddUserScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\t\tAdd User Screen:\n";
	cout << "-----------------------------------------------------------\n\n";
	
	bool AddNew = false;
	do {
		cout << "\tAdding new user:\n\n";
		stUser user = ReadNewUser();
		cout << endl;
		int choice = ReadNumberInRange("Are you SURE you want to add this user [0]:No [1]:Yes : ", 0, 1);
		if (choice) {
			if (AddUserToDataFile(UserFile, user))
				cout << "User Added successfully.\n";
			else
				cout << "Error Adding the new user.\n";
		}
		else
			cout << "Operation cancelled.\n";

		cout << endl << endl;
		AddNew = ReadNumberInRange("Do you want to add more users [0]:No [1]:Yes : ", 0, 1);
	} while (AddNew);
}

void PrintUserDetails(stUser user) {
	cout << "\nThe following are the user details:\n";
	cout << "-----------------------------------------------------------\n";
	cout << "User Name   : " << user.Username << endl;
	cout << "Password    : " << user.password << endl;
	cout << "Permissions : " << to_string(user.permissions) << endl;
	cout << "-----------------------------------------------------------\n\n";
}

void RemoveUser() {
	string username;
	cout << "Enter the username of the user to delete: ";
	getline(cin >> ws, username);
	if (stringToLower(username) != "admin") { // check if the user that we want to delete isn't the admin
		vector <stUser> vUsers = LoadUserData(UserFile, delim);
		int index = UserIndexFinder(vUsers, username);
		if (index != -1) { // check that the user is exist
			PrintUserDetails(vUsers[index]); // print the user details
			bool choice = ReadNumberInRange("Are you SURE you want to delete this user [0]:No [1]:Yes : ", 0, 1);
			if (choice) {
				vUsers.erase(vUsers.begin() + index);
				if (UpdateUserData(vUsers, UserFile, delim)) { // check if the data file is updated or not.
					cout << "User [" << username << "] deleted successfully.\n";
				}
				else
					cout << "Error deleting the user!\nPlease Try Again.\n";
			}
			else {
				cout << "Operation cancelled successfully.\n";
			}
		}
		else {
			cout << "No user with the name [" << username << "] found.\n";
		}
	}
	else {
		cout << "Admin user can't be deleted.\n";
	}
}

void PrintDeleteUserScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\t\tDelete User Screen:\n";
	cout << "-----------------------------------------------------------\n\n";
	RemoveUser();
}

void UpdateUserInfo() {
	string username;
	cout << "\nEnter the user name: ";
	getline(cin >> ws, username);
	if (stringToLower(username) != "admin") { // check if the user that we want to update isn't the admin
		vector <stUser> vUsers = LoadUserData(UserFile, delim);
		int index = UserIndexFinder(vUsers, username);
		if (index != -1) { // check that the user is exist
			PrintUserDetails(vUsers[index]); // print the user details
			bool choice = ReadNumberInRange("Are you SURE you want to update this user [0]:No [1]:Yes : ", 0, 1);
			if (choice) {
				// read the new info of the user.
				cout << "Enter the password: ";
				getline(cin >> ws, vUsers[index].password);
				vUsers[index].permissions = ReadPermissions();

				// update the data file
				if (UpdateUserData(vUsers, UserFile, delim)) { // check if the data file is updated or not.
					cout << "User [" << username << "] updated successfully.\n";
				}
				else
					cout << "Error updating the user!\nPlease Try Again.\n";
			}
			else {
				cout << "Operation cancelled successfully.\n";
			}
		}
		else {
			cout << "No user with the name [" << username << "] found.\n";
		}
	}
	else {
		cout << "Admin user can't be modified.\n";
	}
}

void PrintUpdateUserScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\t\tUpdate User Screen:\n";
	cout << "-----------------------------------------------------------\n\n";
	UpdateUserInfo();
}

void FindUserInfo() {
	string username;
	cout << "Enter the user you are looking for: ";
	getline(cin >> ws, username);

	vector <stUser> vUsers = LoadUserData(UserFile, delim);
	int index = UserIndexFinder(vUsers, username);

	if (index != -1) {
		PrintUserDetails(vUsers[index]);
	}
	else
		cout << "The user with name [" << username << "] didn't found.\n";
}

void PrintFindUserScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\t\tFind User Screen:\n";
	cout << "-----------------------------------------------------------\n\n";
	FindUserInfo();
}


void PrintLoginScreen() {
	ResetScreen();
	cout << "-----------------------------------------------------------\n";
	cout << "\t\t\tLogin Screen:\n";
	cout << "-----------------------------------------------------------\n\n";
}

void Login() {
	stUser sUserData;
	PrintLoginScreen();
	sUserData = ReadUserInfo();

	vector <stUser> vUsers = LoadUserData(UserFile, delim);
	int index = SearchUser(vUsers, sUserData.Username, sUserData.password);

	do {
		if (index != -1) {
			ResetScreen();
			MainMenuScreen(vUsers[index]);
		}
		else {
			PrintLoginScreen();
			cout << "\nInvalid username or password!\n";
			sUserData = ReadUserInfo();
		}
		index = SearchUser(vUsers, sUserData.Username, sUserData.password);
	} while (index != -1); // do while the user enter invalid input.
}


int main() {
	Login();

	return 0;
}