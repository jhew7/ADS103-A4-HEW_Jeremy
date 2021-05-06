#include "PVC.h"

int PVC::getRandNum1to9()
{
	// 1. Generate random numbers between 1 and 9
	// 2. Shift that number to something in the range of 1 - 9 (because default random is  in the range of 0 - std::RAND_MAX)
	int rand1to9;
	srand((unsigned)time(0));
	rand1to9 = (rand() % 9) + 1;

	return rand1to9;
}

void PVC::drawBoardPVC(string P1Name, string computerName)
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

int PVC::playPVC(int gameResult)
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
			//displayMenuScreen();
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
			cout << endl << endl << "Hit enter to return to the Main Menu.";
		}
		else
		{
			cout << endl << "  " << computerName << " you are the winner!";
			cout << endl << endl << "Hit enter to return to the Main Menu.";
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
