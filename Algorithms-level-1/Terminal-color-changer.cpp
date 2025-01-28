#include <iostream>

using namespace std;

enum enColor {Red = 1, Blue = 2, Green = 3, Yellow = 4};

void PrintList() {
	cout << "****************************************\n";
	cout << "(1) Red\n";
	cout << "(2) Blue\n";
	cout << "(3) Green\n";
	cout << "(4) Yellow\n";
	cout << "\n****************************************\n";
}

int main() {
	short option;
	enColor color;

	PrintList();
	cout << "Enter number of a color: ";
	cin >> option;

	color = (enColor)option;

	switch (color) {
	case enColor::Red:
		system("color 4F");
		break;
	case enColor::Blue:
		system("color 1F");
		break;
	case enColor::Green:
		system("color 2F");
		break;
	case enColor::Yellow:
		system("color 6F");
		break;
	default:
		system("color 4F");
		break;
	}

	return 0;
}