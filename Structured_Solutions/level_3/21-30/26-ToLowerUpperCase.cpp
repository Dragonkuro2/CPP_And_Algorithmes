#include <iostream>
#include <string>

using namespace std;

char ToLowerCase(char character) {
	return (character >= 'A' && character <= 'Z') ? character + 32 : character;
}

char ToUpperCase(char character) {
	return (character >= 'a' && character <= 'z') ? character - 32 : character;
}

string CapitalizeText(string text) {
	for (int i = 0; i < text.length(); i++) {
		text[i] = ToLowerCase(text[i]);
	}
	return text;
}

string ToLowercaseText(string text) {
	for (int i = 0; i < text.length(); i++) {
		text[i] = ToUpperCase(text[i]);
	}
	return text;
}

string ReadString() {
	string text;
	cout << "Enter your text: ";
	getline(cin, text);
	return text;
}

int main() {
	string text = ReadString();
	string UppercaseText, LowercaseText;

	UppercaseText = ToLowercaseText(text);
	LowercaseText = CapitalizeText(text);

	cout << "\nYour original text:\n";
	cout << text << endl;
	cout << "\nAfter Converting to lowercase:\n";
	cout << LowercaseText << endl;
	cout << "\nAfter Converting to uppercase:\n";
	cout << UppercaseText << endl;

	return 0;
}