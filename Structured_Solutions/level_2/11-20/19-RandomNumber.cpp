#include <iostream>
#include <cstdlib>

using namespace std;

int RandomNumber(int From, int To) {
	return rand() % (To - From + 1) + From;
}

int main() {
	srand((unsigned)time(NULL));

	cout << RandomNumber(1, 5) << endl;
	cout << RandomNumber(1, 5) << endl;
	cout << RandomNumber(1, 5) << endl;

	return 0;
}