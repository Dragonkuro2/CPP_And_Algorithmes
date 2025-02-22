#include <string>
#include <iostream>
#include <vector>

using namespace std;

enum enMatchCase { MatchCase = 1, IgnoreMatchCase = 2 };

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

string ToLowerCase(string text) {
	for (int i = 0; i < text.length(); i++) {
		text[i] = tolower(text[i]);
	}
	return text;
}

string ReplaceWord(string text, string Searched, string toReplace, enMatchCase mtCase) {
	vector <string> vText = SplitString(text, " ");
	string NewText = "";

	for (string& word : vText) {
		if ((mtCase == enMatchCase::IgnoreMatchCase) && (ToLowerCase(word) == ToLowerCase(Searched))) {
			word = toReplace;
		}
		else if ((mtCase == enMatchCase::MatchCase) && (word == Searched))
			word = toReplace;

		NewText += word + " ";
	}
	NewText = NewText.substr(0, NewText.length() - 1);
	return NewText;
}

int main() {
	string text = "Welcome to Jordan , jordan is a nice country";
	string StringToReplace = "Jordan";
	string sReplaceTo = "USA";

	cout << "Original text: " << text << endl;
	cout << "\nText aftre using my own replace function with match case: " << ReplaceWord(text, StringToReplace, sReplaceTo, enMatchCase::MatchCase) << endl;

	cout << "\nText aftre using my own replace function with no match case: " << ReplaceWord(text, StringToReplace, sReplaceTo, enMatchCase::IgnoreMatchCase) << endl;
}