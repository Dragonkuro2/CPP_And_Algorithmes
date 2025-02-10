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

int GetSum(int number) {
    if (number == 0) {
        return 0;
    }
    int sum = 0;
    while (number != 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

void PrintSum(int number) {
    cout << "The sum of number is: " << GetSum(number) << endl;
}

int main() {
    int number = ReadNumber("Enter a positive number: ");
    PrintSum(number);
    return 0;
}
