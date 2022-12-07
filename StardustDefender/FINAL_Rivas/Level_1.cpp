#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Data.h"
#include <string>

using namespace std;

void Play_Game(Characters &Player);

void gotoxy(short x, short y);
void Game_Inputs(Characters &Player, int Input);
void Bullet_Logic(Characters &Player);
void Colisions(Characters &Player, Characters &Enemy);
void Color(int Color, char Text);
Characters Enemy_Logic(Characters &Enemy, int Player_Col, Characters &Player);

void Trace3(int x, int y, string text)
{
	gotoxy(x, y);
	cout << text;
}

bool Level_1(Characters &Player)
{
	//-----Variables-------//
	char Input = '\0';
	char Special_Symbols = ' ';
	int Player_Life = 0;
	int confirmation = 0;
	Player.Life = 5;
	//-----------------------------//

	//------Clear arrays----//
	for (int i = 0; i < 18; i++)
	{
		Player.Bullet_Col[i] = 0;
		Player.Bullet_Row[i] = 0;
		Player.In_use[i] = false;
	}
	//--------------------//


	//-----------Enemy-----------------//
	Characters Enemy[4];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Enemy[i].Bullet_Row[j] = 0;
			Enemy[i].Bullet_Col[j] = 0;
			Enemy[i].Bullet_Direction[j] = 2;
		}
		{
			Enemy[i].Life = 3;
			Enemy[i].Avatar = 31;
			Enemy[i].Active = true;
			if (i % 2 == 0)
			{
				Enemy[i].Coord_X = 17;
				Enemy[i].Coord_Y = 13;
				Enemy[i].Side = 1;
				Enemy[i].Pattern = 1;
			}
			else
			{
				Enemy[i].Coord_X = 97;
				Enemy[i].Coord_Y = 13;
				Enemy[i].Side = -1;
				Enemy[i].Pattern = -1;
			}
			if (i > 1)
			{
				Enemy[i].Sleep = 3;
			}
			else
			{
				Enemy[i].Sleep = 0;
			}
		}
		
	}
	//----------------------//

	for (int row = 0; row < 28; ++row)
	{
		for (int col = 0; col < 83; ++col)
		{
			//Tab at start//
			if (col == 0)
			{
				cout << "\t\t";
			}
			//------------//

			//-------------top row-----------//
			if (row == 0 && col <= 82 || row == 19 && col <= 82)
			{
				//up-left corner//
				if (row == 0 && col == 0 || row == 19 && col == 0)
				{
					if (row == 0)
					{
						Special_Symbols = 201;
						cout << Special_Symbols;
					}
					if (row == 19)
					{
						Special_Symbols = 204;
						cout << Special_Symbols;
					}
				}
				//middle top row//
				if (row == 0 && col > 0 && col < 82 || row == 19 && col > 0 && col < 82)
				{
					Special_Symbols = 205;
					cout << Special_Symbols;
				}
				//up-right corner//
				if (row == 0 && col == 82 || row == 19 && col == 82)
				{
					if (row == 0)
					{
						Special_Symbols = 187;
						cout << Special_Symbols;
					}
					if (row == 19)
					{
						Special_Symbols = 185;
						cout << Special_Symbols;
					}
				}

			}
			//------------------------------//

			//---------in-between row--------//
			if (row >= 1 && row <= 18 && col >= 0 && col <= 82 || row >= 20 && row < 27 && col >= 0 && col <= 82)
			{
				//borders//
				if (col == 0 || col == 82)
				{
					Special_Symbols = 186;
					cout << Special_Symbols;
				}
				else
				{
					cout << " ";
				}
			}

			//---------------------//

			//-------------down row--------//
			if (row == 27 && col <= 82)
			{
				//down-left corner//
				if (row == 27 && col == 0)
				{
					Special_Symbols = 200;
					cout << Special_Symbols;
				}
				//middle down row//
				if (row == 27 && col > 0 && col < 82)
				{
					Special_Symbols = 205;
					cout << Special_Symbols;
				}
				//down-right corner//
				if (row == 27 && col == 82)
				{
					Special_Symbols = 188;
					cout << Special_Symbols << "\n";
				}

			}
			//---------------------------------------//

			//end line//
			if (col == 82)
			{
				cout << "\n";
			}
			//---------//
		}
	}


	Player_Life = Player.Life;

	//Enemy, Player and Bullets Moving//
	while (Player_Life > 0)
	{	
		int CX = Player.Coord_X;
		int CY = Player.Coord_Y;
		Player_Life = Player.Life;
		

		//Happening while waiting for input//
		Input = '\0';

		if (_kbhit())
		{
			Input = (char)_getch();
		}
		//-------------------------------//


		//-----Colisions-------------//
		for (int i = 0; i < 5; i++)
		{	
			Colisions(Player, Enemy[i]);
		}
		//-------------------------//

		// Enemy Logic//
		for (int i = 0; i < 4; i++)
		{

			Enemy[i] = Enemy_Logic(Enemy[i], CX, Player);
		}
		//--------------------//

		Game_Inputs(Player, Input);

		Bullet_Logic(Player);

		//Confirm to advance to the next level//
		int confirmation = 0;
		for (int i = 0; i < 4; i++)
		{
			if (Enemy[i].Active == false)
			{
				confirmation++;
			}
		}

		if (confirmation >= 4 && Player_Life > 0)
		{
			return true;
		}
		else
		{
			confirmation = 0;
		}
		//------------------------------------//

		//----Display Player----//
		if (CX != Player.Coord_X && Input != '\0' || CY != Player.Coord_Y && Input != '\0')
		{
			gotoxy(CX, CY);
			cout << " ";
		}
			gotoxy(Player.Coord_X, Player.Coord_Y);
			Color(9, Player.Avatar);
			
		//-------------------------------//
		
		//---------Display Life----------//
			gotoxy(16, 28);
			cout << "Life: ";
			for (int i = 1; i < 6; i++)
			{
				if (Player.Life >= i)
				{
					gotoxy(21 + i, 28);
					Color(9, Player.Avatar);
				}
				else
				{
					gotoxy(21 + i, 28);
					cout << " ";
				}
			}
			cout << "\t\tLevel 1\n\t\tScore: " << Player.Score << "\n";
			//------------------------------//
		Sleep(100);
	}

	////Change levels//
	//if (Player.Level > 1 || Player_Life <= 0)
	//{
	//	Play_Game(Player);
	//}
	//--------------//
}
