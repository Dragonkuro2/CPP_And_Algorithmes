#include <iostream>
#include <string>

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

int VowelCounter(string text) {
	int counter = 0;
	for (int i = 0; i < text.length(); i++) {
		if (IsVowel(text[i]))
			counter++;
	}
	return counter;
}

int main() {
	char character = ReadLetter();
	string text = ReadText();
	cout << "Your text is: ";
	cout << "there is " << VowelCounter(text) << " Vowel on it.\n";
	return 0;
}