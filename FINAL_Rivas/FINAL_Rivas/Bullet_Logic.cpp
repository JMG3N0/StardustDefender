#include <iostream>
#include <Windows.h>
#include "Data.h"

using namespace std;

void gotoxy(short x, short y);

void Color(int Color, char Text);

void Bullet_Logic(Characters &Player)
{
	char Special_Character = 205;
	int CY = 0;
	int CX = 0;
	bool Active = false;

	//------------------------------------------------------------------------------------------------------------------//

	//----------------------------------------------Bullets Count------------------------------------------------------//

	for (int Bullet_Number = 0; Bullet_Number < 18; Bullet_Number++)
	{
		//Variables//
		CX = Player.Bullet_Col[Bullet_Number];
		CY = Player.Bullet_Row[Bullet_Number];
		Active = Player.In_use[Bullet_Number];
		//-------------------------------//
		//While active bullet and no location//
		if (Active == true)
		{
			if (CX == 0 && CY == 0)
			{
				Player.Bullet_Col[Bullet_Number] = Player.Coord_X;
				Player.Bullet_Row[Bullet_Number] = Player.Coord_Y - 1;
			}
		}
		else
		{	//if Non active with location//
			if (CY > 0)
			{
				if (CY == 19)
				{
					gotoxy(CX, (CY + 1));
					cout << Special_Character;
				}
				else
				{
					gotoxy(CX, (CY + 1));
					cout << " ";
				}
				Player.Bullet_Col[Bullet_Number] = 0;
				Player.Bullet_Row[Bullet_Number] = 0;
			}
		}
	}
	//------------------------------------------------//

	//-----------------------------------------------------------------------------//

	//-------------------------------------------------Bullet Movement----------------------------------------------//


	for (int size = 0; size < 18; size++)
	{
		//Variables//
		CX = Player.Bullet_Col[size];
		CY = Player.Bullet_Row[size];
		Active = Player.In_use[size];
		//-----------------------//
		if (Active == true)
		{		
						if (size >= 0 && size < 18)
						{
							gotoxy(CX, (CY + 1));
							if ((CY + 1) == 19 || (CY + 1) == 27)
							{
								cout << Special_Character;
							}
							else if ((CY + 1) != Player.Coord_Y)
							{
								cout << " ";
							}
						}
					
	
				if ( size >= 0 && size < 5 && CY > 0)
				{
					gotoxy(CX, CY);
					Color(4, Player.Bullet_Type[0]);
				}
				if (size >= 5 && size < 15 && CY > 0)
				{
					gotoxy(CX, CY);
					Color(4, Player.Bullet_Type[1]);
				}
				if (size >= 15 && size < 18 && CY > 0)
				{
					gotoxy(CX, CY);
					Color(4, Player.Bullet_Type[2]);
				}
			

			//Increase Movement//
			if (size >= 0 && size < 18)
			{
				Player.Bullet_Row[size] = (Player.Bullet_Row[size] - 1);
			}
			//---------------------//
		}

		//Reset when limit reached//
		if (CX > 0 && CY <= 0)
		{
			if (CY == 0 && size < 5 && size >= 15)
			{
				cout << Special_Character;
			}

				Player.Bullet_Col[size] = 0;
				Player.Bullet_Row[size] = 0;
				Player.In_use[size] = false;
		}

	}

}