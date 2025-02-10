#include <iostream>

using namespace std;

int ReadNumber(const string& message) {
    int number;
    do {
        cout << message;
        cin >> number;
    } while (number < 0);

    return number;
}

int ReveresNumber(int number) {
    int Remainder = 0, NewNumber = 0;
    while (number != 0) {
        Remainder = number % 10;
        number /= 10;
        NewNumber = NewNumber * 10 + Remainder;
    }
    return NewNumber;
}

void PrintResult(int number) {
    cout << "The reverse of " << number << " is: " << ReveresNumber(number) << endl;
}

int main() {
    int number = ReadNumber("Enter a positive number: ");
    PrintResult(number);
    return 0;
}
