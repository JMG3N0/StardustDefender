#include <iostream>
#include "Data.h"

using namespace std;

void gotoxy(short x, short y);

void Game_Inputs(Characters &Player, int Input)
{
	int count = -1;

	switch (Input)
	{
	case 'w':
	case 'W':
		if (Player.Coord_Y > 19 && Player.Coord_Y - 2 != 18)
		{
			Player.Coord_Y = Player.Coord_Y - 2;
		}
		break;
	case 's':
	case 'S':
		if (Player.Coord_Y < 27 && Player.Coord_Y + 2 != 28)
		{
			Player.Coord_Y = Player.Coord_Y + 2;
		}
		break;
	case 'a':
	case 'A':
		if (Player.Coord_X > 18)
		{
			Player.Coord_X--;
		}
		break;
	case 'd':
	case 'D':
		if (Player.Coord_X < 97)
		{
			Player.Coord_X++;
		}
		break;
	
	case 'j':
	case 'J':
		for (int i = 0; i < 5; i++)
		{
			if (Player.In_use[i] == false && count == -1)
			{
				count = i;
			}
		}
			if (count != -1)
			{
				Player.In_use[count] = true;
			}
			
			break;
	case 'k':
	case 'K':
		for (int i = 5; i < 15; i++)
		{
			if (Player.In_use[i] == false && count == -1)
			{
				count = i;
			}
		}
		if (count != -1)
		{
			Player.In_use[count] = true;
		}
		break;
	case 'l':
	case 'L':
		for (int i = 15; i < 18; i++)
		{
			if (Player.In_use[i] == false && count == -1)
			{
				count = i;
			}
		}
		if (count != -1)
		{
			Player.In_use[count] = true;
		}
		break;
	default:
		break;
	}
	
}