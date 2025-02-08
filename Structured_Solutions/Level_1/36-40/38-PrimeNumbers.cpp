#include <iostream>

using namespace std;

int ReadNumber(const string& message) {
    float input;
    cout << message;
    cin >> input;
    return input;
}

bool IsPrimeNumber(int number) {
    if (number <= 1) 
        return false;

    for (int i = 2; i <= round(number / 2); i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

void PrintResult(int number) {
    if (IsPrimeNumber(number))
        cout << "The number " << number << " is a prime number." << endl;
    else
        cout << "The number " << number << " isn't a prime number." << endl;
}

int main() {
    
    PrintResult(ReadNumber("Enter a number: "));

    return 0;
}