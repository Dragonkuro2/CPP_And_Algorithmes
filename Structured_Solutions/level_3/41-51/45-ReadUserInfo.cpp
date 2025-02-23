#include <iostream>
#include <string>

using namespace std;

struct stUserInfo {
	string AccNumber;
	string PinCode;
	string UserName;
	string Phone;
	double balance;
};

stUserInfo GetNewUserData() {
	stUserInfo info;
	cout << "Enter User informations: \n\n";
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

int main() {
	stUserInfo info;
	string UserInfo;
	info = GetNewUserData();
	UserInfo = ConvertRecordToLine(info);
	cout << UserInfo << endl;
	return 0;
}