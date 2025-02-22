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

int main() {
	vector <string> vText = { "Hicham", "Khalid", "Karim" };
	cout << "text after join function:" << endl;
	cout << Join(vText, "#") << endl;
}