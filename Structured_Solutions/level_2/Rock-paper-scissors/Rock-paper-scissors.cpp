#include <iostream>
#include <cstdlib>

using namespace std;

int const MAX_SIZE = 100;

enum enMove { stone = 1, paper = 2, csissors = 3 };
enum enWiner { win = 1, lose = 2, draw = 3 };

int ReadPositiveNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number < 0);
	return number;
}

int RandomNumberInRange(int From, int To) { // generate a random number in a specific range
	return rand() % (To - From + 1) + From;
}

int ReadNumberInRange(string message, int From, int To) {
	int choice;
	do {
		choice = ReadPositiveNumber(message);
		if (choice < From || choice > To)
			cout << "\nPlease enter a valid choice!" << endl;
	} while (choice < From || choice > To);
	return choice;
}

void GreenScreen() {
	system("color 2F"); // make the background green with white text
}

void RedScreen() {
	system("color 4F"); // make the background red with white text
}

void YellowScreen() {
	system("color 6F"); // make the background yellow with white text
}

void ResetScreen() {
	system("cls"); // clear the screen
	system(" color 07");
}

bool ContinueGame() {
	int choice = ReadNumberInRange("Do you want to continue [0]:No [1]:Yes: ", 0, 1);
	return choice;
}

enMove GetPlayerMove() { // this function gets the move of the user and checks if it is valid or not
	return (enMove)ReadNumberInRange("Enter your choice [1]:Stone [2]:Paper [3]:csissors : ", 1, 3);
}

enMove GetComputerMove() { // function that generate a random move for the computer
	return (enMove)RandomNumberInRange(1, 3);
}

enWiner GetPlayerResult(enMove PlayerMove, enMove ComputerMove) { // this is the function that has the logic
	if (PlayerMove == ComputerMove)								  // of deciding the winner
		return enWiner::draw;
	else {
		if (PlayerMove == enMove::stone && ComputerMove == enMove::paper)
			return enWiner::lose;
		else if (PlayerMove == enMove::stone && ComputerMove == enMove::csissors)
			return enWiner::win;
		else if (PlayerMove == enMove::paper && ComputerMove == enMove::stone)
			return enWiner::win;
		else if (PlayerMove == enMove::paper && ComputerMove == enMove::csissors)
			return enWiner::lose;
		else if (PlayerMove == enMove::csissors && ComputerMove == enMove::stone)
			return enWiner::lose;
		else
			return enWiner::win;
	}
}

string GetMove(enMove move) { // convert from enum format to string format, to get the moves
	switch (move) {
	case enMove::csissors:
		return "Csissors";
	case enMove::paper:
		return "Paper";
	case enMove::stone:
		return "Stone";
	default:
		return "Doesn't exist";
	}
}

string GetWinner(enWiner result) { // convert from enum format to string formt, to get the result
	switch (result) {
	case enWiner::win:
		return "Player";
	case enWiner::lose:
		return "Computer";
	case enWiner::draw:
		return "No Winner";
	default:
		return "Doesn't exist";
	}
}

void ChangeBackgound(enWiner result) { // function that changes the background based on the result
	if (result == enWiner::win)
		GreenScreen();
	else if (result == enWiner::lose) {
		cout << "\a";
		RedScreen();
	}
	else
		YellowScreen();
}

void ShowRoundResult(enMove PlayerMove, enMove ComputerMove, enWiner result) {
	// applying effects
	ChangeBackgound(result);

	// show the result of the round
	cout << "Player Move: " << GetMove(PlayerMove) << endl;
	cout << "Computer Move: " << GetMove(ComputerMove) << endl;
	cout << "Round Winner: " << GetWinner(result) << endl;
	cout << "\n_______________________________________________________\n";
}

int ElementCounter(enWiner array[MAX_SIZE], int length, enWiner searched) {
	int counter = 0;
	for (int i = 0; i < length; i++) {
		if (array[i] == searched)
			counter++;
	}
	return counter;
}

string FinalWinner(enWiner array[MAX_SIZE], int length) {
	int PlayerWinTimes = ElementCounter(array, length, enWiner::win);
	int ComputerWinTimes = ElementCounter(array, length, enWiner::lose);
	if (PlayerWinTimes == ComputerWinTimes)
		return "No Winner";
	else if (PlayerWinTimes > ComputerWinTimes)
		return "Player";
	else
		return "Computer";
}

void GameOver(enWiner array[MAX_SIZE], int length) {
	int TimesWin = ElementCounter(array, length, enWiner::win);
	int TimesLose = ElementCounter(array, length, enWiner::lose);
	int TimesDraw = ElementCounter(array, length, enWiner::draw);

	if (TimesLose > TimesWin)
		ChangeBackgound(enWiner::lose);
	else if (TimesLose < TimesWin)
		ChangeBackgound(enWiner::win);
	else
		ChangeBackgound(enWiner::draw);

	cout << "\n\n\t\t\t__________________________________________________________________________\n\n";
	cout << "\t\t\t\t\t\t++++ G A M E   O V E R ++++\n\n";
	cout << "\t\t\t__________________________________________________________________________\n\n";
	cout << "\t\t\t_____________________________ [Game Results] _____________________________\n\n";
	cout << "\t\t\tGame Rounds\t\t: " << length << endl;
	cout << "\t\t\tPlayer won times\t: " << TimesWin << endl;
	cout << "\t\t\tComputer won times\t: " << TimesLose << endl;
	cout << "\t\t\tDraw times\t\t: " << TimesDraw << endl;
	cout << "\t\t\tFinal winner\t\t: " << FinalWinner(array, length) << endl;
	cout << "\n\t\t\t__________________________________________________________________________\n\n";
}

void StartGame() {
	enMove PlayerMove, ComputerMove;
	enWiner result;
	enWiner results[MAX_SIZE];
	int counter;

	int tries = ReadPositiveNumber("How many rounds do you want to play: ");

	for (counter = 1; counter <= tries; counter++) {
		cout << "\nRound [" << counter << "] begins: \n";

		PlayerMove = GetPlayerMove();
		ComputerMove = GetComputerMove();
		result = GetPlayerResult(PlayerMove, ComputerMove);

		results[counter - 1] = result;

		cout << "\n______________________ Round [" << counter << "] ______________________\n" << endl;
		ShowRoundResult(PlayerMove, ComputerMove, result);
		if (counter < tries) {
			if (!ContinueGame())
				break;
		}
	}

	GameOver(results, counter);

	if (ReadNumberInRange("\t\t\tDo you wanna play again [0]:No [1]:Yes : ", 0, 1)) {
		ResetScreen();
		StartGame();
	}
}

int main() {

	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}