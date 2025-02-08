#include <iostream>

using namespace std;

const int TABLE_SIZE = 10;

void PrintTableHeader() {
    cout << "\n\t\t\tMultiplication Table from 1 to " << TABLE_SIZE << "\n\n";
    for (int i = 1; i <= TABLE_SIZE; i++)
        cout << "\t" << i;
    cout << "\n____________________________________________________________________________________" << endl;
}

void PrintRowLabel(int row) {
    if (row < 10)
        cout << row << "   |   ";
    else
        cout << row << "  |   ";
}

void PrintTable() {
    PrintTableHeader();
    for (int i = 1; i <= TABLE_SIZE; i++) {
        PrintRowLabel(i);
        for (int j = 1; j <= TABLE_SIZE; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

int main() {
    PrintTable();
    return 0;
}