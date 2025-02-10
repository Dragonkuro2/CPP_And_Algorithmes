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

void PrintAllDigitsFrequency(int number) {
    int NumFrequency = 0;
    for (int i = 0; i < 10; i++) {
        NumFrequency = NumberFrequency(number, i);
        if (NumFrequency > 0)
            PrintResult(number, i);
    }
}

int main() {
    int number = ReadPositiveNumber("Enter a positive number: ");
    PrintAllDigitsFrequency(number);
    return 0;
}