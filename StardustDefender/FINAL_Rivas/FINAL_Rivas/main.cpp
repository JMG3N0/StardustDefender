#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Data.h"

using namespace std;

int Tittle_Screen();
void Play_Game(Characters &Player);

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	//Player//
	Characters Player;
	Player.Life = 5;
	Player.Avatar = 30;
	Player.Level = 1;
	Player.Coord_X = 55;
	Player.Coord_Y = 26;
	//-----------------//

	ShowConsoleCursor(false);
	
	if (Tittle_Screen() == 0)
	{
			Play_Game(Player);
	}
	
}