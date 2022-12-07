#include <iostream>
#include <Windows.h>
#include "Data.h"
#include <string>
#include <time.h>

using namespace std;

void gotoxy(short x, short y);

void Color(int Color, char Text);

void Trace2(int x, int y, string text)
{
	gotoxy(x, y);
	cout << text;
}

Characters Enemy_Logic(Characters &Enemy, int Player_Col, Characters &Player)
{
	//Variables//
	srand(time(NULL));
	int Rand_Direct = rand() % 2;
	int CX = Enemy.Coord_X;
	int CY = Enemy.Coord_Y;
	int Bullet_CX[10];
	int Bullet_CY[10];
	int Bullets_in_use[10];
	int Direction[10];
	int Bullet_Type[10];
	char Special_Character = 205;
	//--------------//
	


	//Initialize Variable//
	for (int i = 0; i < 10; i++)
	{
		Bullet_CX[i] = Enemy.Bullet_Col[i];
		Bullet_CY[i] = Enemy.Bullet_Row[i];
		Direction[i] = Enemy.Bullet_Direction[i];
		Bullet_Type[i] = Enemy.Pattern;
	}
	//------------------//



	//If enemy is dead, deactivate him//
	if (Enemy.Life <= 0 && Enemy.Active == true)
	{
		Enemy.Active = false;
		for (int i = 0; i < 10; i++)
		{
			Enemy.In_use[i] = false;
			if (Bullet_CX[i] > 0 && Bullet_CY[i] > 0)
			{
				if (Bullet_CY[i] == 19 || Bullet_CY[i] == 27)
				{
					if (Bullet_CY[i] == 19)
					{
						gotoxy((Bullet_CX[i] - 1), 19);
						cout << " ";
						gotoxy(Bullet_CX[i], 19);
						cout << Special_Character;
						gotoxy((Bullet_CX[i] + 1), 19);
						cout << " ";
					}
					if (Bullet_CY[i] == 27)
					{
						gotoxy((Bullet_CX[i] - 1), 27);
						cout << " ";
						gotoxy(Bullet_CX[i], 27);
						cout << Special_Character;
						gotoxy((Bullet_CX[i] + 1), 27);
						cout << " ";
					}
					
				}
				else
				{
					gotoxy(Bullet_CX[i], Bullet_CY[i]);
					cout << " ";
				}

				Enemy.Bullet_Col[i] = 0;
				Enemy.Bullet_Row[i] = 0;
				Enemy.Bullet_Direction[i] = 2;
				Player.Score += 5;
			}
		}
	}
	//------------------------------//

	//If bullet was deleted//
	for (int i = 0; i < 10; i++)
	{
		if (Enemy.In_use[i] == false)
		{
				if (Bullet_CX[i] > 0 && Bullet_CY[i] > 0)
				{
					if (Bullet_CY[i] == 19)
					{
						gotoxy(Bullet_CX[i], Bullet_CY[i]);
						cout << Special_Character;
					}
					else
					{
						gotoxy(Bullet_CX[i], Bullet_CY[i]);
						cout << " ";
					}

					Enemy.Bullet_Col[i] = 0;
					Enemy.Bullet_Row[i] = 0;
					Enemy.Bullet_Direction[i] = 2;
				}
		}
	}
	//----------------------------//

	//If enemy is active but sleeping//
	if (Enemy.Sleep > 0 )
	{
		Enemy.Sleep--;
	}
	//if enemy is active and not sleeping//
	else if (Enemy.Active == true)
	{

			//Shoot Bullet//
			if (Enemy.Pattern == 1)	//Pattern 1 = Shoot//
			{
				for (int i = 0; i < 10; i++)
				{
					//If already filled, fill variables//
					if (Enemy.Bullet_Row[i] > 0 && Enemy.Bullet_Col[i] > 0)
					{
						Bullet_CX[i] = Enemy.Bullet_Col[i];
						Bullet_CY[i] = Enemy.Bullet_Row[i];
					}
					else	//if not filled, fill it//
					{
						Enemy.Bullet_Col[i] = CX;
						Enemy.Bullet_Row[i] = CY + 1;
						Enemy.In_use[i] = true;
					}

					if (Enemy.Bullet_Direction[i] == 2)		//Direction 2 = No direction, so fill it//
					{

						//If it moves to the left or right//
						if (CX >= Player_Col + 5 || CX <= Player_Col - 5)
						{
							//If it moves to the left//
							if (CX >= Player_Col + 5)
							{
								Enemy.Bullet_Direction[i] = -1;
							}
							//if it moves to the right//
							else
							{
								Enemy.Bullet_Direction[i] = 1;
							}
						}
						//if it don't move//
						else
						{
							Enemy.Bullet_Direction[i] = 0;
						}
					}
				}
				//Change to don't shoot pattern//
				Enemy.Pattern = (Enemy.Pattern * -1);
			}
			//Don't Shoot//
			else
			{
				Enemy.Pattern = (Enemy.Pattern * -1);
			}

			//Moving Enemy//
			Enemy.Coord_X = (Enemy.Coord_X + Enemy.Side);
			//Move only within limits//
			if (Enemy.Coord_X == 17 || Enemy.Coord_X == 55 || Enemy.Coord_X == 57 || Enemy.Coord_X == 97)
			{
				//Chance to go up or down//
				if (Rand_Direct == 0)
				{
					if (Enemy.Coord_Y > 2)
					{
						Enemy.Coord_Y--;
					}
					else
					{
						Enemy.Coord_Y++;
					}
				}
				else
				{
					if (Enemy.Coord_Y < 18)
					{
						Enemy.Coord_Y++;
					}
					else
					{
						Enemy.Coord_Y--;
					}
				}
				//Going back after reaching limit//
				Enemy.Side = (Enemy.Side * -1);
			}
	}

		//Moving Bullet//
		for (int i = 0; i < 10; i++)
		{
			//if bullet still avaliable, and didn't hit the limit//
			if (Bullet_CY[i] > 0 && Bullet_CY[i] < 27)
			{
				Enemy.Bullet_Col[i] = (Enemy.Bullet_Col[i] + Enemy.Bullet_Direction[i]);
				Enemy.Bullet_Row[i] = (Enemy.Bullet_Row[i] + 1);
			}
			//if the bullet hit the limit//
			if (Bullet_CY[i] == 27)
			{
				Enemy.Bullet_Col[i] = 0;
				Enemy.Bullet_Row[i] = 0;
				Enemy.Bullet_Direction[i] = 2;
			}
		}
		//-----------------------//

		//Display and clear past display//
		for (int i = 0; i < 10; i++)
		{
			//confirmation if it is valid//
			if (Enemy.Bullet_Row[i] > 0)
			{

				if (Enemy.Bullet_Row[i] != 19 && Enemy.Bullet_Row[i] != 27)
				{
					gotoxy(Enemy.Bullet_Col[i], Enemy.Bullet_Row[i]);
					Color(10, Enemy.Bullet_Type[0]);
				}
				if (Bullet_CY[i] != 19 && Bullet_CY[i] != 27)
				{
					gotoxy(Bullet_CX[i], Bullet_CY[i]);
					cout << " ";
				}
			}
		}
		//------------------------//
		
		//display enemy//
		if (Enemy.Active == true)
		{
			if (Enemy.Life == 3)
			{
				gotoxy(Enemy.Coord_X, Enemy.Coord_Y);
				Color(13, Enemy.Avatar);
			}
			if (Enemy.Life == 2)
			{
				gotoxy(Enemy.Coord_X, Enemy.Coord_Y);
				Color(14, Enemy.Avatar);
			}
			if (Enemy.Life == 1)
			{
				gotoxy(Enemy.Coord_X, Enemy.Coord_Y);
				Color(12, Enemy.Avatar);
			}
			
			gotoxy(CX, CY);
			cout << " ";
		}
	//----------------//

	return Enemy;
}