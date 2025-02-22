#include <iostream>
#include <string>

using namespace std;

string ReadText() {
	string text;
	cout << "Enter your text: ";
	getline(cin, text);
	return text;
}

int WordsCounter(string text) {
	string delim = " ", sWord;
	int pos = 0, counter = 0;

	while ((pos = text.find(delim)) != std::string::npos) {
		sWord = text.substr(0, pos);
		if (sWord != "")
			counter++;

		text.erase(0, pos + delim.length());
	}

	if (text != "")
		counter++;

	return counter;
}

int main() {
	string text = ReadText();

	cout << "Your text is: " << text << endl;
	cout << "Words count: " << WordsCounter(text);
	return 0;
}