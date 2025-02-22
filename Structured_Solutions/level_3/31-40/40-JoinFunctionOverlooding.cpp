#include <string>
#include <iostream>
#include <vector>

using namespace std;

string Join(vector <string> vText, string separator) {
	string text = "";
	for (string& word : vText) {
		text += word;
		text += separator;
	}
	return text.substr(0, text.length() - separator.length());
}

string Join(string array[], int length, string delim) {
	string text = "";
	for (int i = 0; i < length; i++) {
		text += array[i];
		text += delim;
	}
	return text.substr(0, text.length() - delim.length());
}

int main() {
	vector <string> vText = { "Hicham", "Khalid", "Karim" };
	string array[] = { "Hicham", "Khalid", "Mustapha" };
	string text = Join(array, 3, "#");

	cout << "text after join function on vector: " << endl;
	cout << Join(vText, "#") << endl;
	cout << "\ntext after join function on array: " << endl;
	cout << text << endl;
}