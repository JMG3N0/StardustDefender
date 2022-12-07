#include <windows.h>

//Func que nos permite mover a donde está el cursor en la consola, para dibujar en pantalla
void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}