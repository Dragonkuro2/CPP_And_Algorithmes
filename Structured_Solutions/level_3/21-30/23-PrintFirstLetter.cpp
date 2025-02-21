#include <iostream>

using namespace std;

void PrintFirstCharacter(string text) {
	bool IsFirstLetter = true;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] != ' ' && IsFirstLetter)
			cout << text[i] << endl;
		IsFirstLetter = (text[i] == ' ') ? true : false;
	}
}

int main() {
	string text = "My name is Hicham Bourezi, and I'm a software engineer";
	PrintFirstCharacter(text);

	return 0;
}