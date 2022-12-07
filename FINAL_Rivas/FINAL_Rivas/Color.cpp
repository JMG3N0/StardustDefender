#include <iostream>
#include <Windows.h>

using namespace std;

void Color(int Color, char Text)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // you can loop k higher to see more color choices
        // pick the colorattribute k you want
        SetConsoleTextAttribute(hConsole, Color);
        cout << Text;
        SetConsoleTextAttribute(hConsole, 15);
   
}