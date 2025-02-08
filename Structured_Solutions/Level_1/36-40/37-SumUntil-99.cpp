#include <iostream>

using namespace std;

float GetInput(const string& message) {
    float input;
    cout << message;
    cin >> input;
    return input;
}

float SumNumbers() {
    float sum = 0;
    float number;

    while (true) {
        number = GetInput("Enter a number (-99 to stop): ");
        if (number == -99) {
            break;
        }
        sum += number;
    }

    return sum;
}

int main() {
    float sum = SumNumbers();
    cout << "The sum of the numbers is: " << sum << endl;
    return 0;
}