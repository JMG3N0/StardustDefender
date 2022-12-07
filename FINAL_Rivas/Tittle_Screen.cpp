#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

bool Tutorial();

int Tittle_Screen()
{
	//Varaibles//
	char Special_Symbols = ' ';
	int direction = 0;
	bool In_Tittle = true;
	char input = '\0';
	//-----------//

	//While Tittle Screen isn't finished//
	while (In_Tittle == true)
	{

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
					if (row == 0 && col <= 82)
					{
						//up-left corner//
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
					//------------------------------//

					//---------in-between row--------//
					if (row >= 1 && row <= 26 && col >= 0 && col <= 82)
					{
						//borders//
						if (col == 0 || col == 82)
						{
							Special_Symbols = 186;
							cout << Special_Symbols;
						}
						else
						{
							//Display Text and options, display different options depending on which is selected//
							if (col >= 1 && col <= 81 && row >= 1 && row <= 28)
							{
								//Game Tittle//
								if (row == 3)
								{
									if (col < 30 || col > 30 && col < 66)
									{
										Special_Symbols = 32;
										cout << Special_Symbols;
									}
									if (col == 30)
									{
										cout << "Stardust Defender";
									}
								}
								//Explanation on Select a option//
								if (row == 6)
								{
									if (col < 30 || col > 30 && col <= 63)
									{
										Special_Symbols = 32;
										cout << Special_Symbols;
									}
									if (col == 30)
									{
										cout << "(Use W/S and ENTER)";
									}
								}
								//Play Option//
								if (row == 9)
								{
									if (direction == 0)
									{
										if (col < 32 || col > 32 && col <= 77)
										{
											Special_Symbols = 32;
											cout << Special_Symbols;
										}
										if (col == 32)
										{
											Special_Symbols = 26;
											cout << Special_Symbols << "Play";
										}
									}
									else
									{
										if (col < 32 || col > 32 && col <= 78)
										{
											Special_Symbols = 32;
											cout << Special_Symbols;
										}
										if (col == 32)
										{
											cout << "Play";
										}
									}
								}
								//Tutorial Option//
								if (row == 10)
								{
									if (direction == 1)
									{
										if (col < 32 || col > 32 && col <= 73)
										{
											Special_Symbols = 32;
											cout << Special_Symbols;
										}
										if (col == 32)
										{
											Special_Symbols = 26;
											cout << Special_Symbols << "Tutorial";
										}
									}
									else
									{
										if (col < 32 || col > 32 && col <= 74)
										{
											Special_Symbols = 32;
											cout << Special_Symbols;
										}
										if (col == 32)
										{
											cout << "Tutorial";
										}
									}
								}

								//Exit Game Option//
								if (row == 11)
								{
									if (direction == 2)
									{
										if (col < 32 || col > 32 && col <= 72)
										{
											Special_Symbols = 32;
											cout << Special_Symbols;
										}
										if (col == 32)
										{
											Special_Symbols = 26;
											cout << Special_Symbols << "Exit Game";
										}
									}
									else
									{
										if (col < 32 || col > 32 && col <= 73)
										{
											Special_Symbols = 32;
											cout << Special_Symbols;
										}
										if (col == 32)
										{
											cout << "Exit Game";
										}
									}
								}
								//Fill Blank Spaces//

								if (row != 3 && row != 6 && row != 9 && row != 10 && row != 11)
								{
									//Flashing Stars//
									if (row == rand() % 26 || col == rand() % 40)
									{
										Special_Symbols = 04;
										cout << Special_Symbols;
									}
									//--------------//
									//Filled Blank Space//
									else
									{
										Special_Symbols = 32;

										cout << Special_Symbols;

									}
								}
								//---------------------//
							}
						}
					}

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

			//Switch between options//
			switch (input)
			{
				//Upwards//
			case 'w':
			case 'W':
				if (direction > 0)
				{
					direction--;
					input = '\0';

				}
				break;
				//Downwards//
			case 's':
			case 'S':
				if (direction < 2)
				{
					direction++;
					input = '\0';
				}
				break;
				//Enter Option//
			case 13:
				if (direction == 0) //Play Option//
				{
					system("cls");
					In_Tittle = false;
					return 0;
				}
				if (direction == 1) //Tutorial Option//
				{
					system("cls");
					if (Tutorial() == true)
					{
						In_Tittle = true;
						direction = 0;
					}
				}
				if (direction == 2) //Exit Game//
				{
					system("cls");
					In_Tittle = false;
					return 1;
					
				}
				break;
				//-------------//
			}
			//Clear Screen//
			system("cls");
			//-------//
	}
		//-----------------//
	
}