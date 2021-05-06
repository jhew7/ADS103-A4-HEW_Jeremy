#include "MenuFunctions.h"
#include "PVP.h"
#include "PVC.h"

enum MenuChoice
{
	PLAYPVP = 1,
	PLAYPVC,
	SCOREBOARD,
	QUIT,
	CHOICES_END
};

int MenuFunctions::menuChoices()
{
	int player = 1, i, choice;
	int gameResult = 0;
	MenuFunctions display;

	/// Core loop: shows menu, goes to screens or exits based on the player's choice
	do
	{
		system("cls");

		choice = display.displayMenuScreen();

		if (choice == MenuChoice::PLAYPVP)
		{
			system("cls");
			PVP playPVP;
			playPVP.playPVP(gameResult);
		}
		if (choice == MenuChoice::PLAYPVC)
		{
			system("cls");
			PVC playPVC;
			playPVC.playPVC(gameResult);
			system("cls");
		}
		else if (choice == MenuChoice::SCOREBOARD)
		{
			system("cls");
			display.showScoreBoard();
		}

		// Loop back to beginning of 'do' if choice is not 4 (QUIT)
	} while (choice != MenuChoice::QUIT);

	system("cls");

	display.displayExitScreen();

	return 0;
}

// Displays Starting Menu Screen
int MenuFunctions::displayMenuScreen()
{
	bool validChoice = false;		// False until they enter 1, 2, 3 or 4.
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

// Displays Scoreboard
void MenuFunctions::showScoreBoard()
{
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "\t\tTop  Scores" << endl;
	cout << "\t\t-----------" << endl << endl;

	cout << endl << "Press any key to return to the Main Menu:";
	_getch();

	system("cls");
	return;
}

// Displays Exit Screen
void MenuFunctions::displayExitScreen()
{
	cout << "\t\t===========" << endl;
	cout << "\t\tTic Tac Toe" << endl;
	cout << "\t\t===========" << endl << endl;

	cout << "Thanks for playing Tic Tac Toe" << endl;

	return;
}
