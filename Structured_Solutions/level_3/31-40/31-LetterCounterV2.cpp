#include <iostream>
#include <string>

using namespace std;

enum enCase { ignoreCase = 1, KeepCase =  2};

string ReadText() {
	string text;
	cout << "Enter Your text: ";
	getline(cin, text);
	return text;
}

char ReadLetter() {
	char letter;
	cout << "enter the character you are searching for: ";
	cin >> letter;
	return letter;
}

int LetterCounter(string text, char character, enCase _case) {
	int counter = 0;
	for (int i = 0; i < text.length(); i++) {
		if (_case == enCase::ignoreCase) {
			if (tolower(text[i]) == tolower(character))
				counter++;
		}
		else {
			if (text[i] == character)
				counter++;
		}
	}
	return counter;
}

char InvertCharacter(char character) {
	return (islower(character)) ? toupper(character) : tolower(character);
}

int main() {
	string text = ReadText();
	char character = ReadLetter();
	cout << "Your text is: " << text << endl;
	cout << "Letter " << character << " Count: " << LetterCounter(text, character, enCase::KeepCase) << endl;
	cout << "Letter " << character << " or " << InvertCharacter(character);
	cout << " count: " << LetterCounter(text, character, enCase::ignoreCase) << endl;
	return 0;
}