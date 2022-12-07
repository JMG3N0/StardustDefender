#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Data.h"

using namespace std;

bool Level_1(Characters &Player);

void Play_Game(Characters &Player)
{
	char Choice = 'N';
	int cont = 0;
	do
	{


		if (Player.Level == 1)
		{
			if (Level_1(Player) == true)
			{
				system("cls");
				cout << "\n\n\n\n\t\t\t\tYou Won!";
				cout << "\n\n\n\n\t\t\tYour Score was: " << Player.Score << "\n\t\t";
				system("pause");
				cout << "\t\tDo you wish to retry ?(Y/N)\n";
				cin >> Choice;
				do
				{
					switch (Choice)
					{
					case 'Y':
					case 'y':
						cont = 1;
						system("cls");
						break;
					case 'N':
					case 'n':
						cont = 0;
						system("cls");
						break;
					default:
						break;
					}
				} while (Choice != 'Y' && Choice != 'y' && Choice != 'N' && Choice != 'n');
			}
			else
			{
				system("cls");
				cout << "\n\n\n\n\t\t\t\tYou lose!";
				cout << "\n\n\n\n\t\t\tYour Score was: " << Player.Score << "\n\n\t\t";
				system("pause");
				cout << "\t\tDo you wish to retry ?(Y/N)\n";
				cin >> Choice;
				do
				{
					switch (Choice)
					{
					case 'Y':
					case 'y':
						cont = 1;
						system("cls");
						break;
					case 'N':
					case 'n':
						cont = 0;
						system("cls");
						break;
					default:
						break;
					}

				} while (Choice != 'Y' && Choice != 'y' && Choice != 'N' && Choice != 'n');

			}
		}
	} while (cont == 1);
	
}