#include <iostream>

using namespace std;

enum enMonths {
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
};

int ReadMonth(const string& message) {
    int input;
    do {
        cout << message;
        cin >> input;
    } while (input < 1 || input > 12); // Ensure the input is between 1 and 12

    return input;
}

void PrintMonth(int month) {
    switch ((enMonths)month) {
    case enMonths::January:
        cout << "January" << endl;
        break;
    case enMonths::February:
        cout << "February" << endl;
        break;
    case enMonths::March:
        cout << "March" << endl;
        break;
    case enMonths::April:
        cout << "April" << endl;
        break;
    case enMonths::May:
        cout << "May" << endl;
        break;
    case enMonths::June:
        cout << "June" << endl;
        break;
    case enMonths::July:
        cout << "July" << endl;
        break;
    case enMonths::August:
        cout << "August" << endl;
        break;
    case enMonths::September:
        cout << "September" << endl;
        break;
    case enMonths::October:
        cout << "October" << endl;
        break;
    case enMonths::November:
        cout << "November" << endl;
        break;
    case enMonths::December:
        cout << "December" << endl;
        break;
    default:
        cout << "Wrong Month!" << endl;
    }
}

int main() {
    PrintMonth(ReadMonth("Enter a month number [Jan = 1, Feb = 2, ..., Dec = 12]: "));
    return 0;
}