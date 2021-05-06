#pragma once

#include <cstdlib>				// for random numbers
#include <ctime>				// for srand
#include <windows.h>			// for the sleep function
#include <conio.h>				// for _getch()
#include "PVP.h"

// Inherits all qualities from PVP except 
// - the way the board is drawn for AI Player integration
// - the way the game is setup to play with AI instead of 2ndary player
class PVC :
    public PVP
{
private:
    int getRandNum1to9();

public:
    void drawBoardPVC(string P1Name, string computerName);
    int playPVC(int gameResult);

};

