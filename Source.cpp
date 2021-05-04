/******************************************************************************
*
*  ACADEMIC INTEGRITY DECLARATION
*
*   I, Jeremy Hew declare that except where I have referenced,
*  the work I am are submitting in this attachment is my own work. I
*  acknowledge and agree that the assessor of this assignment may,
*  for the purpose of authenticating this assignment, reproduce it
*  for the purpose of detecting plagiarism. I have read and am aware
*  of the Think Education Policy and Procedure viewable online at
*  http://www.think.edu.au/studying-at-think/policies-and-procedures/
*
******************************************************************************/

//// GIT HUB LINK: https://github.com/jhew7/ADS103-A4-HEW_Jeremy.git

#include <iostream>
#include <string>
#include <cstdlib>				// for random numbers
#include <ctime>				// for srand
#include <windows.h>			// for the sleep function
#include <conio.h>				// for _getch()

using namespace std;

char position[10] = { 'o','1','2','3','4','5','6','7','8','9' };
//int gameProgress();
void drawBoard();
int displayMenuScreen();
//int playPVP();
//int playPVC();
void showScoreBoard();
void displayExitScreen();

/// Menu Choices
/// Allows the input of string menu choices rather than ints
enum MenuChoice
{
	PLAYPVP = 1,
	PLAYPVC,
	SCOREBOARD,
	QUIT,
	CHOICES_END
};

// Displays a MENU SCREEN which gets a choice (also shows player's cash)
// Inbuilt is a Valid Choice loop which will show the player
// what their choice was if it was invalid and shows them
// how to correct it.
int displayMenuScreen()
{
	bool validChoice = false;		// False until they enter 1, 2 or 3.
	int choice = 0;
	string error = "";

	while (!validChoice)
	{
		// Keep showing menu until player enters a valid choice
		cout << "\t\t===========" << endl;
		cout << "\t\tTic Tac Toe" << endl;
		cout << "\t\t===========" << endl << endl;

		cout << "\tSelect from the menu below: \n\n";

		cout << "\t" << "1. Play - Player vs. Player\n";
		cout << "\t" << "2. Play - Player vs. Computer\n";
		cout << "\t" << "3. Scoreboard\n";
		cout << "\t" << "4. Quit\n";

		error.empty();

		// If the error string is not empty, it must contain a message about an error
		if (!error.empty())
		{
			cout << "\t\t\t " << error << endl;
		}
		cout << endl << "\tSubmit your choice > ";
		cin >> choice;

		// There's no 0 in the menu, and choice end gives us a limit to stay below
		if (choice > 0 && choice < MenuChoice::CHOICES_END)
		{
			validChoice = true;
		}
		else
		{
			error = "\n\t  ========== INCORRECT SELLECTION =========== \n\t\t\t\t\t\t    "
				+ to_string(choice)
				+ " is not in the menu..\t\n\t\t\t\t\t  ===========================================\t\t";

			system("cls");
		}
	}

	return choice;
}

// Draw the gameboard
void drawBoard()
{
	system("cls");
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "       Player 1 [X]  -  Player 2 [O]" << endl << endl;
	cout << endl;

	cout << "             " << "     |     |     " << endl;
	cout << "             " << "  " << position[1] << "  |  " << position[2] << "  |  " << position[3] << endl;

	cout << "             " << "_____|_____|_____" << endl;
	cout << "             " << "     |     |     " << endl;

	cout << "             " << "  " << position[4] << "  |  " << position[5] << "  |  " << position[6] << endl;

	cout << "             " << "_____|_____|_____" << endl;
	cout << "             " << "     |     |     " << endl;

	cout << "             " << "  " << position[7] << "  |  " << position[8] << "  |  " << position[9] << endl;

	cout << "             " << "     |     |     " << endl << endl;
}

//// Generate our 3 random cards/wheel outputs.
//// We want each wheel to end up with a random number
//// Outcome = a number form 2 to 7 inclusive
//int getRandNum2to7(int rangeMax)
//{
//	// 1. Generate random numbers between 2 and 7
//	// 2. Shift that number to something in the range of 2 - 7 (because default random is  in the range of 0 - std::RAND_MAX)
//	int rand2to7;
//
//	rand2to7 = (rand() % 6) + 2;
//
//	return rand2to7;
//}

// Set bet multiplier based on win / loss by matching random numbers
// Mrs Sing only gives back multipliers
int gameProgress(int gameResult)
{
	if (position[1] == position[2] && position[2] == position[3])
	{
		gameResult = 1;
		return gameResult; // Win - Result
	}
	else if (position[4] == position[5] && position[5] == position[6])
	{
		gameResult = 1;
		return gameResult; // Win - Result
	}
	else if (position[7] == position[8] && position[8] == position[9])
	{
		gameResult = 1;
		return gameResult; // Win - Result
	}
	else if (position[1] == position[4] && position[4] == position[7])
	{
		gameResult = 1;
		return gameResult; // Win - Result
	}
	else if (position[2] == position[5] && position[5] == position[8])
	{
		gameResult = 1;
		return gameResult; // Win - Result
	}
	else if (position[3] == position[6] && position[6] == position[9])
	{
		gameResult = 1;
		return gameResult; // Win - Result
	}
	else if (position[1] == position[5] && position[5] == position[9])
	{
		gameResult = 1;
		return gameResult; // Win - Result
	}
	else if (position[3] == position[5] && position[5] == position[7])
	{
		gameResult = 1;
		return gameResult; // Win - Result
	}
	else if (position[1] != '1' && position[2] != '2' && position[3] != '3'
		&& position[4] != '4' && position[5] != '5' && position[6] != '6'
		&& position[7] != '7' && position[8] != '8' && position[9] != '9')
	{
		gameResult = 0;
		return gameResult; // Draw - Game Over with no result
	}
	else
	{
		gameResult = -1;
		return gameResult; // continue playing
	}
}

// Play Player vs Player
int playPVP(int gameResult)
{
	int player = 1, i, choice;
	char playerMove;

	do
	{
		drawBoard();
		player = (player % 2) ? 1 : 2;

		cout << "\nPlayer " << player << ", enter a number:  ";
		cin >> choice;

		playerMove = (player == 1) ? 'X' : 'O';

		if (choice == 1 && position[1] == '1')
		{
			position[1] = playerMove;
		}
		else if (choice == 2 && position[2] == '2')
		{
			position[2] = playerMove;
		}

		else if (choice == 3 && position[3] == '3')
		{
			position[3] = playerMove;
		}

		else if (choice == 4 && position[4] == '4')
		{
			position[4] = playerMove;
		}

		else if (choice == 5 && position[5] == '5')
		{
			position[5] = playerMove;
		}

		else if (choice == 6 && position[6] == '6')
		{
			position[6] = playerMove;
		}

		else if (choice == 7 && position[7] == '7')
		{
			position[7] = playerMove;
		}

		else if (choice == 8 && position[8] == '8')
		{
			position[8] = playerMove;
		}

		else if (choice == 9 && position[9] == '9')
		{
			position[9] = playerMove;
		}
		else
		{
			cout << endl << "Invalid move!";
			cout << endl << "Hit Enter and try again.";
			player--;
			cin.ignore();
			cin.get();
		}

		i = gameProgress(gameResult);
		player++;

	} while (i == -1);

	drawBoard();

	if (i == 1)
	{
		cout << "==>\aPlayer " << --player << " win ";
	}
	else
	{
		cout << "==>\aGame draw";
	}

	cin.ignore();
	cin.get();
	return gameResult;
}

// Displays Credits
void showScoreBoard()
{
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "Top Scores";

	cout << "Press any key to return to the Main Menu:";
	_getch();

	system("cls");
	return;
}

// Displays Exit Screen
void displayExitScreen()
{
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "Thanks for playing Tic Tac Toe" << endl;

	return;
}


// MAIN PROGRAM 
int main()
{
	int player = 1, i, choice;
	char playerMove;
	int gameResult = 0;

	/// Core loop: shows menu, goes to screens or exits based on the player's choice
	do
	{
		system("cls");
		choice = displayMenuScreen();

		if (choice == MenuChoice::PLAYPVP)
		{
			system("cls");
			player = playPVP(gameResult);
		}
		/*if (choice == MenuChoice::PLAYPVC)
		{
			system("cls");
			player = playPVC(gameResult);
		}*/
		else if (choice == MenuChoice::SCOREBOARD)
		{
			system("cls");
			showScoreBoard();
		}

		// Loop back to beginning of 'do' if choice is not 2 (QUIT)
	} while (choice != MenuChoice::QUIT);

	system("cls");
	displayExitScreen();

	return 0;
}