#include <iostream>
#include <string>

using namespace std;

char ToCapitalLetter(char character) {
	return (character >= 'a' && character <= 'z') ? character - 32 : character;
}

void CapitalizeFirstCharacter(string &text) {
	bool IsFirstLetter = true;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ' && IsFirstLetter) {
			text[i] = ToCapitalLetter(text[i]);
		}
		IsFirstLetter = (text[i] == ' ') ? true : false;
	}
}

string ReadString() {
	string text;
	cout << "Enter your text: ";
	getline(cin, text);
	return text;
}

int main() {
	string text = ReadString();

	cout << "\nYour original text:\n";
	cout << text << endl;
	CapitalizeFirstCharacter(text);
	cout << "\nAfter capitalizing:\n";
	cout << text << endl;
	return 0;
}