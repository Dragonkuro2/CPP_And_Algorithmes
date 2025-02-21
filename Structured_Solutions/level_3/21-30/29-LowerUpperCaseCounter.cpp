#include <iostream>
#include <string>

using namespace std;

string ReadText() {
	string text;
	cout << "Enter a text to invert: ";
	getline(cin, text);
	return text;
}

int CountCapitalLetters(string text) {
	int counter = 0;
	for (int i = 0; i < text.length(); i++) {
		if (isupper(text[i]))
			counter++;
	}
	return counter;
}

int CountSmallLetters(string text) {
	int counter = 0;
	for (int i = 0; i < text.length(); i++) {
		if (islower(text[i]))
			counter++;
	}
	return counter;
}

int main() {
	string text = ReadText();
	cout << "Your original text is: " << text << endl;
	cout << "\nString length: " << text.length() << endl;
	cout << "Capital Letter count: " << CountCapitalLetters(text) << endl;
	cout << "Small Letters count: " << CountSmallLetters(text) << endl;
	return 0;
}