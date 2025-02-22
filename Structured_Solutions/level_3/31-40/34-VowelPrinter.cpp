#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

char ReadLetter() {
	char letter;
	cout << "enter a character: ";
	cin >> letter;
	return letter;
}

string ReadText() {
	string text;
	cout << "Enter your text: ";
	getline(cin, text);
	return text;
}

bool IsVowel(char character) {
	char array[] = { 'a', 'e', 'i', 'o', 'u' };
	for (int i = 0; i < 5; i++) {
		if (tolower(character) == array[i])
			return true;
	}
	return false;
}

void VowelPrinter(string text) {
	for (int i = 0; i < text.length(); i++) {
		if (IsVowel(text[i]))
			cout << std::left << setw(4) << text[i];
	}
}

int main() {
	char character = ReadLetter();
	string text = ReadText();
	cout << "Your text is: ";
	cout << "Vowel in string are: ";
	VowelPrinter(text);

	return 0;
}