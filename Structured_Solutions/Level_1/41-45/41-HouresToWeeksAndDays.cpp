#include <iostream>

using namespace std;

int ReadPositiveNumber(const string& message) {
    int input;
    do {
        cout << message;
        cin >> input;
    } while (input < 0);

    return input;
}

void CalculateWeeksAndDays(int totalHours, float& weeks, float& days) {
    weeks = (float)totalHours / (7 * 24);
    days = (float)totalHours / 24;
}

int main() {
    int totalHours = ReadPositiveNumber("Enter the number of hours: ");
    float weeks, days;
    CalculateWeeksAndDays(totalHours, weeks, days);
    cout << "Total hours: " << totalHours << endl;
    cout << "Total days: " << days << endl;
    cout << "Total weeks: " << weeks << endl;
    return 0;
}