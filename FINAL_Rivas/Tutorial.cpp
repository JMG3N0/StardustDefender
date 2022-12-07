#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

void Color(int Color, char Text);

bool Tutorial()
{
	char Special_Symbols = ' ';
	char Text_Page_1[] = "In Stardust Defender, you will cross through space, defeating enemy spaceships.  You can use the W/A/S/D keys to move around, and use the J key to shoot.Your Normal shot has 5 bullets, which recharge once it hit it's target or a border. You also have a limited space to move around, visible while playing.YouYour Bullet Enemy Enemy BulletNext Page [D]";
	char Text_Page_2[] = "You also can use the Light and Heavy Shots.Use K for Light Shot and L for Heavy Shot.The Light Shot can shoot up to 10 bullets, but can't break enemy bullets.The Heavy Shot can only shoot 3 bullets, but can break any bullet.While the Normal Shot will break the enemy bullet and himself.Also, remember that enemies change color depending on their health.Light ShotHeavy Shot[A] Previous PageClose Tutorial [D]";
	int Letter_Number = 0;
	int Blank_Col = 1;
	int Page = 0;
	char input = '\0';
	bool completed = false;

	while (completed == false)
	{

		while (Page == 0)
		{
			Letter_Number = 0;
			input = '\0';

			for (int row = 0; row < 28; ++row)
			{
				for (int col = 0; col < 83; ++col)
				{
					//Tab at start//
					if (col == 0)
					{
						cout << "\t\t";
					}
					//----------//

					//---------------top row-----------------//
					if (row == 0 && col <= 82)
					{
						//-------------up left corner-------------//
						if (row == 0 && col == 0)
						{
							Special_Symbols = 201;
							cout << Special_Symbols;
						}
						//middle top row//
						if (row == 0 && col > 0 && col < 82)
						{
							Special_Symbols = 205;
							cout << Special_Symbols;
						}
						//up-right corner//
						if (row == 0 && col == 82)
						{
							Special_Symbols = 187;
							cout << Special_Symbols;
						}
					}
					//--------------------------------------------//

					//-----------middle  row-----------------//
					if (row >= 1 && row <= 26 && col >= 0 && col <= 82)
					{
						//borders//
						if (col == 0 || col == 82)
						{
							Special_Symbols = 186;

							if (col == 0)
							{
								cout << Special_Symbols;
							}
							else if (col == 82)
							{
								cout << Special_Symbols;
								Blank_Col = 1;
							}
						}
						else //Text and display enemy\player and bullet\enemy bullet//
						{
							//-----------------Text----------------//
							if (row >= 1 && row <= 4 && col >= 1 && col <= 81)
							{

								//first row//
								if (row == 1 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									cout << Text_Page_1[Letter_Number];
									Letter_Number++;
									Blank_Col++;
								}
								//second row//
								if (row == 2 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									if (Blank_Col < 73)
									{
										cout << Text_Page_1[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}
								//third row//
								if (row == 3 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									if (Blank_Col < 72)
									{
										cout << Text_Page_1[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}
								//fourth row//
								if (row == 4 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									if (Blank_Col <= 82)
									{
										cout << Text_Page_1[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}
								//-------------------------------//
							}
							else //---------------
							{

								//------------Symbols-------//
								if (row == 14 || row == 15 || row == 16 || row == 20 || row == 21 || row == 22)
								{
									if (row == 14)
									{
										if (col < 31 || col >= 32 && col < 48 || col >= 49)
										{
											cout << " ";
										}

										if (col == 31)
										{
											Special_Symbols = 30;
											Color(9, Special_Symbols);
										}

										if (col == 48)
										{
											Special_Symbols = 127;
											Color(4, Special_Symbols);

										}
									}
									//--------------------------//
									//--------arrow-------------//
									if (row == 15)
									{
										if (col == 31 || col == 48)
										{
											Special_Symbols = 24;
											cout << Special_Symbols;
										}
										else
										{
											cout << " ";
										}
									}
									//-----------description-----------//
									if (row == 16)
									{
										if (col > 29 && col <= 32 || col >= 43 && col <= 54)
										{
											cout << Text_Page_1[Letter_Number];
											Letter_Number++;
										}
										else
										{
											cout << " ";
										}
									}

									if (row == 20)
									{
										if (col < 31 || col >= 32 && col < 48 || col >= 49)
										{
											cout << " ";
										}

										if (col == 31)
										{
											Special_Symbols = 31;
											Color(13, Special_Symbols);
										}

										if (col == 48)
										{
											Special_Symbols = 127;
											Color(10, Special_Symbols);

										}
									}
									if (row == 21)
									{
										if (col == 31 || col == 48)
										{
											Special_Symbols = 24;
											cout << Special_Symbols;
										}
										else
										{
											cout << " ";
										}
									}
									if (row == 22)
									{
										if (col >= 29 && col <= 33 || col >= 43 && col <= 55)
										{
											cout << Text_Page_1[Letter_Number];
											Letter_Number++;
										}
										else
										{
											cout << " ";
										}
									}
								}
								else //Go to the next page//
								{

									if (row == 26 && col >= 69 && col < 82)
									{
										Color(14, Text_Page_1[Letter_Number]);
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}

							}
						}
					}
					//------------------------------//
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
			//waiting for input//
			input = (char)_getch();
			//-------------//

			if (input == 'd' || input == 'D')
			{
				Page = 1;
				system("cls");
			}
			else
			{
				input = '\0';
				system("cls");
			}
		}

		while (Page == 1)
		{
			Letter_Number = 0;
			input = '\0';

			for (int row = 0; row < 28; ++row)
			{
				for (int col = 0; col < 83; ++col)
				{
					//Tab at start//
					if (col == 0)
					{
						cout << "\t\t";
					}
					//----------//

					//---------------top row-----------------//
					if (row == 0 && col <= 82)
					{
						//-------------up left corner-------------//
						if (row == 0 && col == 0)
						{
							Special_Symbols = 201;
							cout << Special_Symbols;
						}
						//middle top row//
						if (row == 0 && col > 0 && col < 82)
						{
							Special_Symbols = 205;
							cout << Special_Symbols;
						}
						//up-right corner//
						if (row == 0 && col == 82)
						{
							Special_Symbols = 187;
							cout << Special_Symbols;
						}
					}
					//--------------------------------------------//

					//-----------middle  row-----------------//
					if (row >= 1 && row <= 26 && col >= 0 && col <= 82)
					{
						//borders//
						if (col == 0 || col == 82)
						{
							Special_Symbols = 186;

							if (col == 0)
							{
								cout << Special_Symbols;
							}
							else if (col == 82)
							{
								cout << Special_Symbols;
								Blank_Col = 1;
							}
						}
						else //Text and display bullets//
						{
							//-----------------Text----------------//
							if (row >= 1 && row <= 6 && col >= 1 && col <= 81 && Letter_Number <= 352)
							{

								//first row//
								if (row == 1 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									if (Blank_Col < 44)
									{
										cout << Text_Page_2[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
				
								}
								//second row//
								if (row == 2 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									if (Blank_Col <= 42)
									{
										cout << Text_Page_2[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}
								//third row//
								if (row == 3 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									if (Blank_Col <= 73)
									{
										cout << Text_Page_2[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}
								//fourth row//
								if (row == 4 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									if (Blank_Col < 67)
									{
										cout << Text_Page_2[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}
								//fifth row//
								if (row == 5 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									if (Blank_Col < 63)
									{
										cout << Text_Page_2[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}
								//sixth row//
								if (row == 6 && Blank_Col >= 1 && Blank_Col <= 81)
								{
									/*if (Blank_Col < 67)
									{*/
										cout << Text_Page_2[Letter_Number];
										Letter_Number++;
										Blank_Col++;
									/*}*/
									/*else
									{
										cout << " ";
									}*/
								}
								//-------------------------------//
							}
							else //---------------
							{

								//------------Symbols-------//
								if (row == 14 || row == 15 || row == 16)
								{
									if (row == 14)
									{
										if (col < 31 || col >= 32 && col < 48 || col >= 49)
										{
											cout << " ";
										}

										if (col == 31)
										{
											Special_Symbols = 248;
											Color(4, Special_Symbols);
										}

										if (col == 48)
										{
											Special_Symbols = 06;
											Color(4, Special_Symbols);

										}
									}
									//--------------------------//
									//--------arrow-------------//
									if (row == 15)
									{
										if (col == 31 || col == 48)
										{
											Special_Symbols = 24;
											cout << Special_Symbols;
										}
										else
										{
											cout << " ";
										}
									}
									//-----------description-----------//
									if (row == 16)
									{
										if (col >= 26 && col <= 35 || col >= 43 && col <= 52)
										{
											cout << Text_Page_2[Letter_Number];
											Letter_Number++;
										}
										else
										{
											cout << " ";
										}
									}

								}
								else //Go back\Close Tut//
								{

									if (row == 26 && col <= 17 || row == 26 && col <= 81 && col >= 64)
									{
										Color(14, Text_Page_2[Letter_Number]);
										Letter_Number++;
										Blank_Col++;
									}
									else
									{
										cout << " ";
									}
								}

							}
						}
					}
					//------------------------------//
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
			//waiting for input//
			input = (char)_getch();
			//-------------//

			switch (input)
			{
			case 'D':
			case 'd':
				completed = true;
				return true;
				system("cls");
				cout << "a";
				break;
			case 'A':
			case 'a':
				Page = 0;
				system("cls");
				break;
			default:
				system("cls");
				break;
			}
		}
	}
}
	