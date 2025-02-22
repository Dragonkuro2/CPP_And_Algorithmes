#include <iostream>
#include <string>

using namespace std;

char ReadLetter() {
	char letter;
	cout << "enter a character: ";
	cin >> letter;
	return letter;
}

bool IsVowel(char character) {
	char array[] = { 'a', 'e', 'i', 'o', 'u' };
	for (int i = 0; i < 5; i++) {
		if (tolower(character) == array[i])
			return true;
	}
	return false;
}

int main() {
	char character = ReadLetter();
	if (IsVowel(character))
		cout << "Yes letter " << character << " is a vowel.\n";
	else
		cout << "No letter " << character << " is not a vowel.\n";
	return 0;
}