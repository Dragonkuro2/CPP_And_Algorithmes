#include <iostream>
#include <string>
#include <vector>

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

vector <string> StringToVector(string text, string delim) {
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

stUserInfo FillUserInfo(vector <string> vText) {
	stUserInfo info;
	info.AccNumber = vText[0];
	info.PinCode = vText[1];
	info.UserName = vText[2];
	info.Phone = vText[3];
	info.balance = stod(vText[4]);
	return info;
}

void PrintClientRecord(stUserInfo Client) {
	cout << "\n\nThe following is the extracted client record:\n";
	cout << "\nAccout Number: " << Client.AccNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.UserName;
	cout << "\nPhone : " << Client.Phone;
	cout << "\nAccount Balance: " << Client.balance;
}

int main() {
	stUserInfo info;
	string UserInfo;
	info = GetNewUserData();
	UserInfo = ConvertRecordToLine(info);
	cout << UserInfo << endl;

	// Example of converting back from string to struct
	vector<string> vText = StringToVector(UserInfo, "#//#");
	stUserInfo newInfo = FillUserInfo(vText);
	cout << "Converted back to struct:" << endl;
	PrintClientRecord(newInfo);

	return 0;
}