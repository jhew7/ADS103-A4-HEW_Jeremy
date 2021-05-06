#pragma once

#include <iostream>
#include <string>
#include <conio.h>				// for _getch()

using namespace std;

class PVP
{
public:
	char position[11] = { 'o','1','2','3','4','5','6','7','8','9','q' };


	void drawBoardPVP (string P1Name, string P2Name);
	void clearBoard ();
	int checkWin (int gameResult);
	int playPVP (int gameResult);
};

