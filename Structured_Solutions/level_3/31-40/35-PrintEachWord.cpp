#include <iostream>
#include <string>

using namespace std;

string ReadText() {
	string text;
	cout << "Enter your text: ";
	getline(cin, text);
	return text;
}

void PrintEachWord(string text) {
	string delim = " ", sWord;
	int pos = 0;
	cout << "Your string words are:" << endl;
	while ((pos = text.find(delim)) != std::string::npos) {
		sWord = text.substr(0, pos);
		if (sWord != "")
			cout << sWord << endl;

		text.erase(0, pos + delim.length());
	}

	if (text != "")
		cout << text << endl;
}

int main() {
	string text = ReadText();

	cout << "Your string words are:\n\n";

	PrintEachWord(text);

	return 0;
}