#include <string>
#include <iostream>

using namespace std;

string ReadText() {
	string text;
	cout << "Enter your text: ";
	getline(cin, text);
	return text;
}

string TrimLeft(string S1) {
	for (int i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
			return S1.substr(i, S1.length() - i);
	}
	return "";
}

string TrimRight(string S1) {
	for (int i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}
	return "";
}

string Trim(string S1) {
	return (TrimLeft(TrimRight(S1)));
}

int main()
{
	string S1 = ReadText();
	cout << "\nString = " << S1;
	cout << "\n\nTrim Left = " << TrimLeft(S1);
	cout << "\nTrim Right = " << TrimRight(S1);
	cout << "\nTrim = " << Trim(S1);
	system("pause>0");
}