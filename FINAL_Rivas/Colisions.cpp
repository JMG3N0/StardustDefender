#include <iostream>
#include <Windows.h>
#include "Data.h"
#include <string>

using namespace std;

void gotoxy(short x, short y);
void Trace(int x, int y, string text)
{
	gotoxy(x, y);
	cout << text;
}

void Colisions(Characters &Player, Characters &Enemy)
{
	bool Already_hit = false;
	bool Enemy_Already_hit = false;

	//for each player bullet//
	for (int i = 0; i < 18; i++)
	{
		//------Variables-----//
		int Player_Col = Player.Coord_X;
		int Player_Row = Player.Coord_Y;
		int CY = Player.Bullet_Row[i];
		int CX = Player.Bullet_Col[i];
		char Special_Character = 205;
		int Player_Life = Player.Life;
		bool Player_Active_Bullet = Player.In_use[i];
		//---------------------//

		//For each enemy bullet//
		for (int z = 0; z < 10; z++)
		{
			//----------Variables--------//
			int Enemy_CY = Enemy.Bullet_Row[z];
			int Enemy_CX = Enemy.Bullet_Col[z];
			int Row_Enemy = Enemy.Coord_Y;
			int Col_Enemy = Enemy.Coord_X;
			int Enemy_Direct = Enemy.Bullet_Direction[z];
			//--------------------------//

			//If Player bullet is active//
				if (Player_Active_Bullet == true)
				{
					//Heavy Bullet//
					if (i >= 15)
					{
						//If bullets colide//
						for (int j = 0; j < 2; j++)
						{
							if (((CY - j) == Enemy_CY && CX == Enemy_CX) || ((CY - j) == Enemy_CY && (CX - Enemy_Direct) == Enemy_CX))
							{
							
										if (Enemy_CY == 19)
										{
											gotoxy(Enemy_CX, Enemy_CY);
											cout << Special_Character;
										}
										Enemy.In_use[z] = false;
									
							}
						}
						//-------------------------------------------------//
						
						//If Player hits enemy//
						if (CY == Row_Enemy && CX == Col_Enemy && Enemy_Already_hit == false || CY == Row_Enemy && CX == (Col_Enemy + Enemy.Side) && Enemy_Already_hit == false)
						{
							Enemy.Life = (Enemy.Life - 3);
							Enemy_Already_hit = true;
						}
						//--------------------------------//
					}
					//-------------------------------------//

					//Normal Bullet//
					if (i >= 0 && i < 5)
					{
						//if Bulet Colide//
						for (int j = 0; j < 2; j++)
						{
							if (((CY - j) == Enemy_CY && CX == Enemy_CX) || ((CY - j) == Enemy_CY && (CX - Enemy_Direct) == Enemy_CX))
							{
									if (Enemy_CY == 19)
									{
										gotoxy(Enemy_CX, Enemy_CY);
										cout << Special_Character;
									}
									else
									{
										gotoxy(Enemy_CX, Enemy_CY);
										cout << " ";
									}
									Enemy.In_use[z] = false;
									Player.In_use[i] = false;
							}
						}
						//----------------------//
						
						//If Player hit enemy//
						if (CY == Row_Enemy && CX == Col_Enemy && Enemy_Already_hit == false || CY == Row_Enemy && CX == (Col_Enemy + Enemy.Side) && Enemy_Already_hit == false )
						{
							Enemy.Life = (Enemy.Life - 2);
							Enemy_Already_hit = true;
						}
						//------------------//
					}
					//------------------------------//

					//Light Bullet//
					if (i >= 5 && i < 15)
					{
						//if Bulet Colide//
						for (int j = 0; j < 2; j++)
						{
							if (((CY - j) == Enemy_CY && CX == Enemy_CX) || ((CY - j) == Enemy_CY && (CX - Enemy_Direct) == Enemy_CX))
							{
								if (CY - j == 19)
								{
									gotoxy(CX, (CY - j));
									cout << Special_Character;
								}
								else
								{
									gotoxy(CX, (CY - j));
									cout << " ";
								}
								Player.In_use[i] = false;
							}
						}
						//-----------------------------//
						
						//If Player hit enemy//
						if (CY == Row_Enemy && CX == Col_Enemy && Enemy_Already_hit == false || CY == Row_Enemy && CX == (Col_Enemy + Enemy.Side) && Enemy_Already_hit == false )
						{
							Enemy.Life = (Enemy.Life - 1);
							Enemy_Already_hit = true;
						}
						//-----------------------//
					}
					//-----------------------------------//
				}
				//-------------------------------------//

				//Enemy Hit Player//
				if (Enemy_CY == Player_Row && Enemy_CX == Player_Col && Already_hit == false)
				{
					Player.Life = (Player_Life - 1);
					Already_hit = true;
				}
				//-----------------//
		}
	}
}