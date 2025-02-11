#include <iostream>

using namespace std;

string ReadPassword() {
	string passwd;
	cout << "Please enter a text: ";
	cin >> passwd;
	return passwd;
}

string EncryptText(string &text, int EncriptionKey) {
	for (int i = 0; i < text.length(); i++) {
		text[i] = char((int)text[i] + EncriptionKey);
	}
	return text;
}

string DecriptText(string &text, int EncriptionKey) {
	for (int i = 0; i < text.length(); i++) {
		text[i] = char((int)text[i] - EncriptionKey);
	}
	return text;
}

int main() {
	string text = ReadPassword();
	int EncriptionKey = 2;
	cout << "text before encription: " << text << endl;
	cout << "text after encription: " << EncryptText(text, EncriptionKey) << endl;
	cout << "text after decription: " << DecriptText(text, EncriptionKey) << endl;
	return 0;
}