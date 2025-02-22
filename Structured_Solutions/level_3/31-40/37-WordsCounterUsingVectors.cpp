#include <iostream>
#include <string>
#include <vector>

using namespace std;

string ReadText() {
	string text;
	cout << "Enter your text: ";
	getline(cin, text);
	return text;
}

vector <string> StringToVector(string text, string delim) {
	vector <string> vText;
	string sWord;
	int pos = 0;
	while ((pos = text.find(delim)) != std::string::npos) {
		sWord = text.substr(0, pos);
		if (sWord != "")
			vText.push_back(sWord);

		text.erase(0, pos + delim.length());
	}
	if (text != "")
		vText.push_back(text);

	return vText;
}

void PrintVector(vector <string>& vText) {
	for (string& sWord : vText) {
		cout << sWord << endl;
	}
}

int main() {
	string text = ReadText();
	vector <string> vText = StringToVector(text, " ");

	cout << "Your text is: " << text << endl;
	cout << "Tokens: " << vText.size() << endl;
	cout << "Your Words: " << endl;
	PrintVector(vText);
	return 0;
}