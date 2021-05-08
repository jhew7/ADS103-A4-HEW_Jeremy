#include <chrono>		//time
#include "PVP.h"
#include "MenuFunctions.h"

using namespace std;

void PVP::drawBoardPVP(string P1Name, string P2Name)
{
	system("cls");
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "\t\t " << "[X] " << P1Name << endl << "\t\t  - vs. -" << endl << "\t\t " << "[O] " << P2Name << endl << endl;
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

void PVP::clearBoard()
{
	for (int i = 0; i < 10; i++)
		position[i] = '0' + i;
}

int PVP::checkWin(int gameResult)
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

int PVP::playPVP(int gameResult)
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

	chrono::steady_clock::time_point begin = chrono::steady_clock::now(); ////// START TIME FOR GAME

	do
	{
		drawBoardPVP(P1Name, P2Name);

		if (player % 2)
		{
			player = 1;
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
			// couldn't figure out how to stop it crashing if a letter is input and not a number
		}

		i = checkWin(gameResult);
		player++;

	} while (i == -1);

	drawBoardPVP(P1Name, P2Name);

	string winnerName;

	if (i == 1)
	{
		if (playerMove == 'X') // If last player move was " X " then P1Name is winner
		{
			cout << endl << "  " << P1Name << " you are the winner!";
			winnerName = P1Name;
		}
		else // If last player move was NOT " X " then P2Name is winner
		{
			cout << endl << "  " << P2Name << " you are the winner!";
			winnerName = P2Name;
		}
	}
	else
	{
		cout << " DRAW!";
	}

	chrono::steady_clock::time_point end = chrono::steady_clock::now(); // ENDS GAME TIME
	int winnerTime;
	winnerTime = chrono::duration_cast<chrono::seconds>(end - begin).count();
	cout << endl << endl << "  " << winnerName << " took " << chrono::duration_cast<chrono::seconds>(end - begin).count() << " seconds to win!" << endl;

	PVP restart;
	char rematch = ' ';
	MenuFunctions backToMenu;
	
	cout << endl << "  Play Again? (y/n): ";
	cin >> rematch;
	if (rematch == 'y')
	{
		system("cls");
		restart.playPVP(gameResult);
		restart.clearBoard();
		restart.drawBoardPVP(P1Name, P2Name);
	}
	else (backToMenu.displayMenuScreen());

	
	return gameResult;
}
