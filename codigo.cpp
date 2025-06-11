#include <iostream>
#include <conio.h>
#include <windows.h>
#include "Figuras.h"
#include "libreria.h"
using namespace std;
void gotoxy(int x,int y)
{ 
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);   
    COORD dwPos;   
    dwPos.X = x;    
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);
}
int main()
{ system("color A0");
bool contra;
int a;    
 cout<<"Ingrese clave ";
 contra=valcontra();                                                 
 if(contra==true)
    { getch();
        system("cls"); 
        menuprincipal();    





    }else cout<<"ACCESO BLOQUEADO, INTENTE EN 12 MINUTOS.";
















}


