#include <iostream>

using namespace std;

int ReadPositiveNumber(const string& message) {
    int number;
    do {
        cout << message;
        cin >> number;
    } while (number < 0);

    return number;
}

int NumberFrequency(int number, int searched) {
    int Remainder = 0, counter = 0;
    while (number != 0) {
        Remainder = number % 10;
        if (Remainder == searched)
            counter++;
        number /= 10;
    }
    return counter;
}

void PrintResult(int number, int searched) {
    cout << "Digit " << searched << " Frequency is: " << NumberFrequency(number, searched) << " Time(s)." << endl;
}

int main() {
    int number = ReadPositiveNumber("Enter a positive number: ");
    int searched = ReadPositiveNumber("Enter the number your searching for: ");
    PrintResult(number, searched);
    return 0;
}
