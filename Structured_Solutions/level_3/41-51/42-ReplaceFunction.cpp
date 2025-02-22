#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector <string> SplitString(string text, string delim) {
	vector <string> vText;
	string sWord = "";
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

string ReplaceWord(string text, string Searched, string toReplace) {
	vector <string> vText = SplitString(text, " ");
	string NewText = "";

	for (string& word : vText) {
		if (word == Searched)
			word = toReplace;

		NewText += word + " ";
	}
	NewText = NewText.substr(0, NewText.length() - 1);
	return NewText;
}

string ReplaceWordUsingBuiltInFunction(string text, string StringToReplace, string sReplaceTo) {
	short pos = text.find(StringToReplace);
	while (pos != std::string::npos) {
		text = text.replace(pos, StringToReplace.length(), sReplaceTo);
		pos = text.find(StringToReplace);
	}
	return text;
}

int main() {
	string text = "Welcome to Jordan , Jordan is a nice country";
	string StringToReplace = "Jordan";
	string sReplaceTo = "USA";

	cout << "Original text: " << text << endl;
	text = ReplaceWord(text, StringToReplace, sReplaceTo);
	cout << "\nText aftre using my own replace function: " << text << endl;

	text = "Welcome to Jordan , Jordan is a nice country";
	text = ReplaceWordUsingBuiltInFunction(text, StringToReplace, sReplaceTo);
	cout << "\nText after using replace built in function: " << text << endl;
}