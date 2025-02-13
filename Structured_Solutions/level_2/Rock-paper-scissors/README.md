# Rock-Paper-Scissors Game

This is a console-based Rock-Paper-Scissors game implemented in C++. The game allows a player to play multiple rounds against the computer, with the console background color changing based on the result of each round.

## Features

- Play Rock-Paper-Scissors against the computer.
- The console background color changes based on the result of each round:
  - Green for a win.
  - Red for a loss.
  - Yellow for a draw.
- The game displays the result of each round and the final game results.
- Option to play multiple rounds and continue playing after the game ends.

## Installation

1. Clone the repository or download the source code.
2. Open the project in Visual Studio.
3. Build the project to compile the code.

## Usage

1. Run the compiled executable.
2. Enter the number of rounds you want to play.
3. For each round, enter your move:
   - `1` for Stone
   - `2` for Paper
   - `3` for Scissors
4. The computer will randomly select its move.
5. The result of each round will be displayed, and the console background color will change based on the result.
6. After all rounds are completed, the final game results will be displayed.
7. You will be prompted to play again or exit the game.

## Code Overview

- `ReadPositiveNumber`: Reads a positive number from the user.
- `RandomNumberInRange`: Generates a random number within a specified range.
- `ReadNumberInRange`: Reads a number within a specified range from the user.
- `GreenScreen`, `RedScreen`, `YellowScreen`: Change the console background color.
- `ResetScreen`: Clears the screen and resets the console color to default.
- `ContinueGame`: Prompts the user to continue playing.
- `GetPlayerMove`: Gets the player's move.
- `GetComputerMove`: Generates a random move for the computer.
- `GetPlayerResult`: Determines the result of the round.
- `GetMove`: Converts the move enum to a string.
- `GetWinner`: Converts the winner enum to a string.
- `ChangeBackground`: Changes the console background color based on the result.
- `ShowRoundResult`: Displays the result of the round.
- `ElementCounter`: Counts the occurrences of a specific result in an array.
- `FinalWinner`: Determines the final winner based on the results.
- `GameOver`: Displays the final game results.
- `StartGame`: Starts the game and handles the game loop.

## Note

This code may not work as expected on Linux because it uses the `system()` function, which does not exist on Linux.

## Author

This project was created by [Hicham Bourezi].

## Acknowledgments

- This project was created as a simple console game to demonstrate basic C++ programming concepts and console manipulation.

Feel free to modify and enhance the game as you see fit. Enjoy playing!
