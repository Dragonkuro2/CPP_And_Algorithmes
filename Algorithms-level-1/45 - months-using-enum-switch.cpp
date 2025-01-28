#include <iostream>

using namespace std;

enum enMonth {Junuary = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	Octobre = 10,
	November = 11,
	Decembre = 12
};

void PrintList() {
	cout << "****************************************\n";
	cout << "(1) Junuary\n";
	cout << "(2) February\n";
	cout << "(3) March\n";
	cout << "(4) April\n";
	cout << "(5) May\n";
	cout << "(6) June\n";
	cout << "(7) July\n";
	cout << "(8) August\n";
	cout << "(9) September\n";
	cout << "(10) Octobre\n";
	cout << "(11) November\n";
	cout << "(12) Decembre\n";
	cout << "****************************************\n";
}

void PrintMonth(enMonth month) {
	switch (month) {
	case enMonth::Junuary:
		cout << "January" << endl;
		break;
	case enMonth::February:
		cout << "February" << endl;
		break;
	case enMonth::March:
		cout << "March" << endl;
		break;
	case enMonth::April:
		cout << "April" << endl;
		break;
	case enMonth::May:
		cout << "May" << endl;
		break;
	case enMonth::June:
		cout << "June" << endl;
		break;
	case enMonth::July:
		cout << "July" << endl;
		break;
	case enMonth::August:
		cout << "August" << endl;
		break;
	case enMonth::September:
		cout << "September" << endl;
		break;
	case enMonth::Octobre:
		cout << "October" << endl;
		break;
	case enMonth::November:
		cout << "November" << endl;
		break;
	case enMonth::Decembre:
		cout << "December" << endl;
		break;
	default:
		cout << "Invalid month" << endl;
		break;
	}
}

int main() { // program that writes the name of the month of the screen
	short option;
	enMonth month;

	PrintList();
	cout << "Enter number a number of a month: ";
	cin >> option;

	month = (enMonth)option;

	PrintMonth(month);


	return 0;
}