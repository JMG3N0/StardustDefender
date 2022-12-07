#pragma once

using namespace std;

struct Characters
{
	//Player Only//
	int Level = 0;
	int Bullet_Amount[18];
	int Score = 0;
	//---------------------//

	//Shared//
	int Life = 0;
	char Avatar = ' ';
	int Coord_X = 0;
	int Coord_Y = 0;
	char Bullet_Type[3] = { (char)127,(char)248,(char)06 };
	int Bullet_Row[18];
	int Bullet_Col[18];
	bool In_use[18];
	//-------------------//

	//Enemy Only//
	bool Active = false;
	int Side = 0;
	int Sleep = 3;
	int Pattern = 0;
	int Bullet_Direction[10];
	//----------------------//
};

