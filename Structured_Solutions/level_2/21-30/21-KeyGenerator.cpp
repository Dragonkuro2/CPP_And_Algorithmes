#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharacters { SmallLetter, CapitalLetter, SpecialCharacter, Digit};

int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number < 0);
	return number;
}

int RnadomNumberInRange(int From, int To) {
	return rand() % (To - From + 1) + From;
}

char RandomCharacter(enCharacters character) {

	switch (character) {
	case enCharacters::SmallLetter:
		return (char)RnadomNumberInRange('a', 'z');
	case enCharacters::CapitalLetter:
		return (char)RnadomNumberInRange('A', 'Z');
	case enCharacters::SpecialCharacter:
		return (char)RnadomNumberInRange(33, 47);
	case enCharacters::Digit:
		return (char)RnadomNumberInRange(48, 57);
	default:
		return '\0';
	}
}

string GenerateWord(enCharacters character, short lenght) {
	string word = "";
	for (int i = 0; i < lenght; i++) {
		word += RandomCharacter(character);
	}

	return word;
}

string GenerateKey() {
	string key = "";
	key += GenerateWord(enCharacters::CapitalLetter, 4) + "-";
	key += GenerateWord(enCharacters::CapitalLetter, 4) + "-";
	key += GenerateWord(enCharacters::CapitalLetter, 4) + "-";
	key += GenerateWord(enCharacters::CapitalLetter, 4);

	return key;
}

void GenerateKeys(int amount) {
	for (int i = 1; i <= amount; i++) {
		cout << "Key [" << i << "] : " << GenerateKey() << endl;
	}
}

int main() {
	srand((unsigned)time(NULL));

	GenerateKeys(ReadPositiveNumber("How many keys do you want: "));

	return 0;
}