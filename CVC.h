#pragma once

#include <cstdlib>				// for random numbers
#include <ctime>				// for srand
#include <windows.h>			// for the sleep function
#include <conio.h>				// for _getch()
#include <chrono>		        //time
#include "MenuFunctions.h"
#include "PVP.h"

// Inherits all qualities from PVP except 
// - the way the board is drawn for AI Player integration
// - the way the game is setup to play with AI instead of 2ndary player
class CVC :
    public PVP
{
private:

public:
    int getRandNum1to9();
    void drawBoardCVC(string C1Name, string C2Name);
    int playCVC(int gameResult);

};