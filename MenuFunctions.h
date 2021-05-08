#pragma once

#include <iostream>
#include <string>
#include <conio.h>				// for _getch()

using namespace std;

class MenuFunctions
{
public: 
	int menuChoices();
	int displayMenuScreen();
	void showScoreBoard();
	void displayExitScreen();
};

