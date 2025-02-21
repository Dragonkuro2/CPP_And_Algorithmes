#include <iostream>
#include <string>

using namespace std;

char ToLowerCase(char character) {
	return (character >= 'A' && character <= 'Z') ? character + 32 : character;
}

void ToLowerCaseFirstCharacter(string &text) {
	bool IsFirstLetter = true;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ' && IsFirstLetter) {
			text[i] = ToLowerCase(text[i]);
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
	ToLowerCaseFirstCharacter(text);
	cout << "\nAfter Converting to lowercase:\n";
	cout << text << endl;
	return 0;
}