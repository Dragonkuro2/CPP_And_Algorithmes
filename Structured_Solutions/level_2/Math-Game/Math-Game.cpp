#include <iostream>
#include <cstdlib>

using namespace std;

enum enLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOperation { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

struct stEquation { // struct that has the elements of the equation
	int number1;
	int number2;
	char operation;
};

struct stRoundInfo { // struct that has info of the round
	stEquation equation;
	int RoundResult;
};

struct stGameStatus { // struct of the status of the game
	int Rounds = 0;
	int RightAnswers = 0;
	int WrongAnswers = 0;
	string QuestionLevel = "";
	string Operation = "";
};

void ClearScreen() {
	system("color 0F");
	system("cls");
}

int ReadNumberInRange(string message, int From, int To) { // this function read a number in a specific range
	int number;											// it takes the message and the edges of the range
	do {
		cout << message;
		cin >> number;
		if (number < From || number > To)
			cout << "Enter a valid option!" << endl;
	} while (number < From || number > To);
	return number;
}

int ReadPositiveNumber(string message) { // this function Reads a positive number, it takes the message and print it
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number < 0);
	return number;
}

int ReadNumber(string message) { // this function takes the message and read from the user a number
	int number;
	cout << message;
	cin >> number;
	return number;
}

int RandomNumberInRange(int From, int To) { // Generate a random number in a specific edge
	return rand() % (To - From + 1) + From;
}

char charOperation(enOperation operation) { // convert from from operations from enums to strings
	switch (operation) {
	case enOperation::Add:
		return '+';
	case enOperation::Sub:
		return '-';
	case enOperation::Mul:
		return '*';
	case enOperation::Div:
		return '/';
	default:
		break;
	}
}

stEquation EasyEquation(enOperation operation) { // generate easy questions
	stEquation equation;

	equation.number1 = RandomNumberInRange(1, 10);
	equation.number2 = RandomNumberInRange(1, 10);
	equation.operation = charOperation(operation);

	return equation;
}

stEquation MedEquation(enOperation operation) { // generate meduim questions
	stEquation equation;

	equation.number1 = RandomNumberInRange(11, 30);
	equation.number2 = RandomNumberInRange(11, 30);
	equation.operation = charOperation(operation);

	return equation;
}

stEquation HardEquation(enOperation operation) { // generate Hard questions
	stEquation equation;

	equation.number1 = RandomNumberInRange(31, 100);
	equation.number2 = RandomNumberInRange(31, 100);
	equation.operation = charOperation(operation);

	return equation;
}

enLevel GetLevel() { // gets the level of hardness from the user
	short level = ReadNumberInRange("Enter question level [1]:Easy [2]:Med [3]:Hard [4]:Mix : ", 1, 4);
	return (enLevel)level;
}

enOperation GetOperation() { // gets operation from the user
	short operation = ReadNumberInRange("Enter operation type [1]:Add [2]:Sub [3]:Mul [4]:Div [5]:Mix : ", 1, 5);
	return (enOperation)operation;
}

stEquation GetEquation(enLevel level, enOperation operation) { // generate the equation based on the level and operation
	if (level == enLevel::Mix) // if the level is mix it'll take a random level
		level = (enLevel)RandomNumberInRange(1, 3);

	if (operation == enOperation::MixOp) // if the level is mix it'll take a random operation
		operation = (enOperation)RandomNumberInRange(1, 4);

	switch (level) {
	case enLevel::Easy:
		return EasyEquation(operation);
	case enLevel::Med:
		return MedEquation(operation);
	case enLevel::Hard:
		return HardEquation(operation);
	default:
		cout << "Invalid level" << endl;
		break;
	}
}

int GetResult(stEquation equation) { // calculate the real result of the equation to compare it the input of the user
	switch (equation.operation) {
	case '+':
		return equation.number1 + equation.number2;
	case '-':
		return equation.number1 - equation.number2;
	case '*':
		return equation.number1 * equation.number2;
	case '/':
		return equation.number1 / equation.number2;
	}
}

stRoundInfo GetRoundInfo(enLevel level, enOperation operation) { // generate the final equation based
	stRoundInfo roundInfo;										// on the input of the user.

	roundInfo.equation = GetEquation(level, operation);
	roundInfo.RoundResult = GetResult(roundInfo.equation);

	return roundInfo;
}

void ShowRoundInfo(stEquation equation) { // print exercice info
	cout << equation.number1 << endl;
	cout << equation.number2 << "  " << equation.operation << endl;
	cout << "____________" << endl;
}

void ChangeScreen(bool Result) { // it takes bool value if it was true that mean that the answer is right
	if (Result)					// then change the color of the screen
		system("color 2F"); // make the backgound green
	else {
		cout << "\a";
		system("color 4F"); // make the backgound red
	}
}

void ShowRoundResult(stRoundInfo roundInfo, int UserResult) { // Print the round result
	ChangeScreen(roundInfo.RoundResult == UserResult);
	if (UserResult == roundInfo.RoundResult) {
		cout << "Right answer :)" << endl;
	}
	else {
		cout << "Wrong answer :(" << endl;
		cout << "The right answer is: " << roundInfo.RoundResult << endl;
	}
}

void UpdateStatus(int roundResult, int UserResult, int &RightAnswers, int &WrongAnswers) { // update the status of the game
	if (roundResult == UserResult)
		RightAnswers++;
	else
		WrongAnswers++;
}

stGameStatus StartGame() {
	stRoundInfo roundInfo;
	int UserResult;

	string Levels[] = { "Easy", "Med", "Hard", "Mix" };
	string Operations[] = { "Add", "Sub", "Mul", "Div", "Mix"};

	int Roundnumber = ReadPositiveNumber("How many exercice do you want: ");
	enLevel level = GetLevel();
	enOperation operation = GetOperation();

	stGameStatus status;
	status.Rounds = Roundnumber;
	status.QuestionLevel = Levels[level - 1]; // -1 because the array starts from 1 and enums start from 1
	status.Operation = Operations[operation - 1]; // the same here

	for (int i = 0; i < Roundnumber; i++) {
		cout << "\n\n_______________ Round [" << i + 1 << "/" << Roundnumber << "] _______________" << endl;
		roundInfo = GetRoundInfo(level, operation); // generate random equation based on the level and operation
		ShowRoundInfo(roundInfo.equation);
		UserResult = ReadNumber("Enter the answer: ");
		ShowRoundResult(roundInfo, UserResult);
		UpdateStatus(roundInfo.RoundResult, UserResult, status.RightAnswers, status.WrongAnswers);
	}
	return status;
}

void PrintResult(int NumberWin, int NumberFail) {
	ChangeScreen(NumberWin >= NumberFail);

	cout << "___________________________________________\n";

	if (NumberWin >= NumberFail)
		cout << "\n\tFinal Result is You Passed :)\n";
	else
		cout << "\n\tFinal Result is You Fail :(\n";

	cout << "___________________________________________\n";
}

void PrintStatus(stGameStatus status) {
	PrintResult(status.RightAnswers, status.WrongAnswers);

	cout << "\nNumber of Questions: " << status.Rounds << endl;
	cout << "Question level\t: " << status.QuestionLevel << endl;
	cout << "Operation type\t: " << status.Operation << endl;
	cout << "Right answers\t: " << status.RightAnswers << endl;
	cout << "Wrong answers\t: " << status.WrongAnswers << endl;
	cout << "__________________________________________\n";
}

void Play() {
	int option;
	stGameStatus status;

	do {
		ClearScreen();
		status = StartGame();
		PrintStatus(status);
		option = ReadNumberInRange("Do you want to continue [0]:No [1]:Yes : ", 0, 1);
	} while (option);
}

int main() {
	srand((unsigned)time(NULL));

	Play();

	return 0;
}
