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

void PrintInReverse(int number) {
    if (number == 0) {
        cout << 0 << endl;
        return;
    }
    while (number != 0) {
        cout << number % 10 << endl;
        number /= 10;
    }
}

int main() {
    int number = ReadNumber("Enter a positive number: ");
    PrintInReverse(number);
    return 0;
}
