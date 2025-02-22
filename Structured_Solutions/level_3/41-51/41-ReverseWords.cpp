#include <string>
#include <iostream>
#include <vector>

using namespace std;

string ReadText() {
	string text;
	cout << "Enter your text: ";
	getline(cin, text);
	return text;
}

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

string ReverseWordsInString(string text) {
	string ConvertedText = "";
	vector <string> vText = SplitString(text, " ");

	// declare an iterator
	vector <string>::iterator iter = vText.end();
	while (iter != vText.begin()) {
		--iter;
		ConvertedText += *iter + " ";
	}
	ConvertedText = ConvertedText.substr(0, ConvertedText.length() - 1);
	return ConvertedText;
}

int main() {
	string text = ReadText();
	cout << "Original text: " << text << endl;
	text = ReverseWordsInString(text);
	cout << "\nText aftre reversing: " << text << endl;
}