#include <iostream>
#include <string>

using namespace std;

char ReadCharacter() {
	char character;
	cout << "Enter a character: ";
	cin >> character;
	return character;
}

char InvertLetterCase(char character) {
	return isupper(character) ? tolower(character) : toupper(character);
}

int main() {
	char character = ReadCharacter();
	cout << "Your character is: " << character << endl;
	cout << "\nAfter inverting: " << InvertLetterCase(character) << endl;

	return 0;
}