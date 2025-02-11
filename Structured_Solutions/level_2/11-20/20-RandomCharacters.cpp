#include <iostream>
#include <cstdlib>

using namespace std;

enum enCharacters { SmallLetter, CapitalLetter, SpecialCharacter, Digit};

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

int main() {
	srand((unsigned)time(NULL));

	cout << RandomCharacter(enCharacters::SmallLetter) << endl;
	cout << RandomCharacter(enCharacters::CapitalLetter) << endl;
	cout << RandomCharacter(enCharacters::SpecialCharacter) << endl;
	cout << RandomCharacter(enCharacters::Digit) << endl;

	return 0;
}