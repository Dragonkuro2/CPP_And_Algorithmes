#include <iostream>
#include <string>

using namespace std;

enum enOperator { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float GetInput(const string &message) {
    float input;
    cout << message;
    cin >> input;
    return input;
}

enOperator GetOperator() {
    char op;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    switch (op) {
    case '+':
        return enOperator::Add;
    case '-':
        return enOperator::Subtract;
    case '*':
        return enOperator::Multiply;
    case '/':
        return enOperator::Divide;
    default:
        cout << "Invalid operator. Defaulting to +." << endl;
        return enOperator::Add;
    }
}

float Calculate(float num1, float num2, enOperator op) {
    switch (op) {
    case enOperator::Add:
        return num1 + num2;
    case enOperator::Subtract:
        return num1 - num2;
    case enOperator::Multiply:
        return num1 * num2;
    case enOperator::Divide:
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << "Error: Division by zero." << endl;
            return 0;
        }
    default:
        return 0;
    }
}

int main() {
    float num1 = GetInput("Enter the first number: ");
    float num2 = GetInput("Enter the second number: ");
    enOperator op = GetOperator();

    float result = Calculate(num1, num2, op);
    cout << "The result is: " << result << endl;

    return 0;
}