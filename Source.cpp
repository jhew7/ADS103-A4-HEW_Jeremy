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

char position[11] = { 'o','1','2','3','4','5','6','7','8','9','q' };

int displayMenuScreen();
int checkWin(int gameResult);
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
void drawBoardPVP(string P1Name, string P2Name)
{
	system("cls");
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "\t\t  " << P1Name << " [X]" << endl << "\t\t  - vs. -" << endl << "\t\t " << P2Name << " [O]" << endl << endl;
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

void drawBoardPVC(string P1Name, string computerName)
{
	system("cls");
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "\t\t  " << P1Name << " [X]" << endl << "\t\t  - vs. -" << endl << "\t\t " << computerName << " [O]" << endl << endl;
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

int getRandNum1to9()
{
	// 1. Generate random numbers between 2 and 7
	// 2. Shift that number to something in the range of 2 - 7 (because default random is  in the range of 0 - std::RAND_MAX)
	int rand1to9;
	srand((unsigned)time(0));
	rand1to9 = (rand() % 9) + 1;

	return rand1to9;
}

void clearBoard()
{
	for (int i = 0; i < 10; i++)
		position[i] = '0' + i;
}

// Play Player vs Player
int playPVP(int gameResult)
{
	int player = 1, i, choice;
	char playerMove;

	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "\t   Player Name Selection" << endl << endl << endl << endl;

	string P1Name = "Player 1";  //Default name
	string P2Name = "Player 2";
	int P1Move = 1;
	int P2Move = 2;

	cout << "  Player 1 - Select your name: ";
	cin >> P1Name;
	cout << "  Player 2 - Select your name: ";
	cin >> P2Name;

	cout << "Hello " << P1Name << " & " << P2Name << " , let's play some Tic Tac Toe!";

	do
	{
		drawBoardPVP(P1Name, P2Name);
		//player = (player % 2) ? 1 : 2;
		if (player % 2)
		{
			player = 1; // Odd
			player = P1Move;
			cout << endl << "  Your move " << P1Name << ":  ";
			cin >> choice;
		}
		else
		{
			player = 2;
			player = P2Move;
			cout << endl << "  Your move " << P2Name << ":  ";
			cin >> choice;
		}
		
		/*cout << "\nPlayer " << player << ", enter a number:  ";
		cin >> choice;*/

		//playerMove = (player == 1) ? 'X' : 'O';

		if (player == 1 && player == P1Move)
		{
			playerMove = 'X';
		}
		else if (player == 2 && player == P2Move)
		{
			playerMove = 'O';
		}

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

		i = checkWin(gameResult);
		player++;

	} while (i == -1);

	drawBoardPVP(P1Name, P2Name);

	if (i == 1)
	{
		if (playerMove == 'X')
		{
			cout << endl << "  " << P1Name << " you are the winner!";
		}
		else
		{
			cout << endl << "  " << P2Name << " you are the winner!";
		}
	}
	else
	{
		cout << " DRAW!";
	}

	cin.ignore();
	cin.get();
	return gameResult;
}

// Game Results
int checkWin(int gameResult)
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

int playPVC(int gameResult)
{
	system("cls");
	clearBoard();
	int player = 1, i, choice;
	char playerMove;

	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "\t   Player Name Selection" << endl << endl << endl << endl;

	string P1Name = "Player 1";  //Default name
	string computerName = "Consol";
	int P1Move = 1;
	int computerMove = 2;

	cout << "  Player 1 - Select your name: ";
	cin >> P1Name;
	
	cout << "Hello " << P1Name << " & " << computerName << " , let's play some Tic Tac Toe!";

	do
	{
		drawBoardPVC(P1Name, computerName);
		//player = (player % 2) ? 1 : 2;
		if (player % 2)
		{
			player = 1; // Odd
			cout << endl << "  Your move " << P1Name << ":  ";
			cin >> choice;
		}
		else
		{
			player = 2;
			choice = getRandNum1to9();
			cout << endl << "  Your move " << computerName << ":  " << choice;
			Sleep(1200);
		}

		/*cout << "\nPlayer " << player << ", enter a number:  ";
		cin >> choice;*/
		
		if (player == 1 && player == P1Move)
		{
			playerMove = 'X';
		}
		else if (player == 2 && player == computerMove)
		{
			playerMove = 'O';
		}

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

		else if (choice == 10 && position[10] == 'q')
		{
			displayMenuScreen();
		}

		else
		{
			cout << endl << "Invalid move!";
			
			Sleep(800);
			player--;
			//cin.ignore();
			//cin.get();
		}

		i = checkWin(gameResult);
		player++;

	} while (i == -1);
	
	drawBoardPVC(P1Name, computerName);

	if (i == 1)
	{
		if (playerMove == 'X')
		{
			cout << endl << "  " << P1Name << " you are the winner!";
		}
		else
		{
			cout << endl << "  " << computerName << " you are the winner!";
		}
	}
	else
	{
		cout << " DRAW!";
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
		if (choice == MenuChoice::PLAYPVC)
		{
			system("cls");
			player = playPVC(gameResult);
			system("cls");
		}
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