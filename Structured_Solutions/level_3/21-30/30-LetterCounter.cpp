#include <iostream>
#include <string>

using namespace std;

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

int LetterCounter(string text, char character) {
	int counter = 0;
	for (int i = 0; i < text.length(); i++) {
		if (tolower(text[i]) == tolower(character))
			counter++;
	}
	return counter;
}

int main() {
	string text = ReadText();
	char character = ReadLetter();
	cout << "Your text is: " << text << endl;
	cout << "There is " << LetterCounter(text, character) << " " << "Letter " << character << " in that text." << endl;
	return 0;
}