#include <iostream>
#include <string>

using namespace std;

string ReadText() {
	string text;
	cout << "Enter a text to invert: ";
	getline(cin, text);
	return text;
}

char InvertLetterCase(char character) {
	return isupper(character) ? tolower(character) : toupper(character);
}

string InvertAllLetters(string text) {
	for (int i = 0; i < text.length(); i++) {
		text[i] = InvertLetterCase(text[i]);
	}
	return text;
}

int main() {
	string text = ReadText();
	cout << "Your original text is: " << text << endl;
	cout << "\nAfter inverting: " << InvertAllLetters(text) << endl;

	return 0;
}