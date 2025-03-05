#include <iostream>
#include <cmath>

using namespace std;

string digits[] = { "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven",
						"Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string dozens[] = { "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

long long ReadNumber(string message) {
	long long number;
	cout << message;
	cin >> number;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid Input!" << endl;
		cout << message;
		cin >> number;
	}
	return number;
}

string ConvertNumberToText(long long number) {
	if (number == 0)
		return "";

	if (number > 0 && number < 20)
		return digits[number - 1];

	if (number >= 20 && number < 100) {
		int teens = number / 10;
		int remainder = number % 10;
		return dozens[teens - 2] + " " + ConvertNumberToText(remainder);
	}

	if (number >= 100 && number < 1000) {
		int remainder = number % 100;
		int hundreds = number / 100;
		return ConvertNumberToText(hundreds) + " Hundred " + ConvertNumberToText(remainder);
	}

	if (number >= 1000 && number < 1000000) {
		int remainder = number % 1000;
		int thousands = number / 1000;
		return ConvertNumberToText(thousands) + " Thousand " + ConvertNumberToText(remainder);
	}

	if (number >= 1000000 && number < 1000000000) {
		int remainder = number % 1000000;
		int millions = number / 1000000;
		return ConvertNumberToText(millions) + " Million " + ConvertNumberToText(remainder);
	}

	if (number >= 1000000000 && number < 1000000000000) {
		int remainder = number % 1000000000;
		int billions = number / 1000000000;
		return ConvertNumberToText(billions) + " Billion " + ConvertNumberToText(remainder);
	}

	if (number >= 1000000000000) {
		int remainder = number % 1000000000000;
		long billions = number / 1000000000000;
		return ConvertNumberToText(billions) + " Trillion " + ConvertNumberToText(remainder);
	}
}

int main() {

	long long number = ReadNumber("Enter a number: ");
	if (number > 0)
		cout << "Your number is: " << ConvertNumberToText(abs(number)) << endl;
	else if (number < 0)
		cout << "Your number is: minus " << ConvertNumberToText(abs(number)) << endl;
	else
		cout << "Your number is: Zero" << endl;

	return 0;
}