#include "CVC.h"


int CVC::getRandNum1to9()
{
	// 1. Generate random numbers between 1 and 9
	 // 2. Shift that number to something in the range of 1 - 9 (because default random is  in the range of 0 - std::RAND_MAX)
	int rand1to9;
	srand((unsigned)time(0));
	rand1to9 = (rand() % 9) + 1;

	return rand1to9;
}

void CVC::drawBoardCVC(string C1Name, string C2Name)
{
	system("cls");
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "\t\t " << "[X] " << C1Name << endl << "\t\t  - vs. -" << endl << "\t\t " << "[O] " << C2Name << endl << endl;
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

int CVC::playCVC(int gameResult)
{
	system("cls");
	clearBoard();
	int player = 1, i, choice;
	char playerMove;

	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	string C1Name = "Microsoft";  //Default name
	string C2Name = "Apple";
	int C1Move = 1;
	int C2Move = 2;

	chrono::steady_clock::time_point begin = chrono::steady_clock::now(); ////// START TIME FOR GAME

	do
	{
		drawBoardCVC(C1Name, C2Name);
		//player = (player % 2) ? 1 : 2;
		if (player % 2)
		{
			player = 1; // Odd
			choice = getRandNum1to9();
			cout << endl << "  Your move " << C1Name << ":  ";
			Sleep(500);
		}
		else
		{
			player = 2;
			choice = getRandNum1to9();
			cout << endl << "  Your move " << C2Name << ":  " << choice;
			Sleep(500);
		}

		if (player == 1 && player == C1Move)
		{
			playerMove = 'X';
		}
		else if (player == 2 && player == C2Move)
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
			//displayMenuScreen();
		}

		else
		{
			cout << endl << "Invalid move!";
			Sleep(300);
			player--;
			// couldn't figure out how to stop it crashing if a letter is input and not a number
		}

		i = checkWin(gameResult);
		player++;

	} while (i == -1);

	drawBoardCVC(C1Name, C2Name);

	string winnerName;

	if (i == 1)
	{
		if (playerMove == 'X')
		{
			cout << endl << "  " << C1Name << " you are the winner!";
			winnerName = C1Name;
		}
		else
		{
			cout << endl << "  " << C2Name << " you are the winner!";
			winnerName = C2Name;
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

	CVC restart;
	char rematch = ' ';
	MenuFunctions backToMenu;

	cout << endl << "  Play Again? (y/n): ";
	cin >> rematch;
	if (rematch == 'y')
	{
		system("cls");
		restart.playCVC(gameResult);
		restart.clearBoard();
		restart.drawBoardCVC(C1Name, C2Name);
	}
	else
	{
		system("cls");
		backToMenu.displayMenuScreen();
	}

	return gameResult;
}
