#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
using namespace std;

void cursor (int columna, int fila);
void camino ();

int main (){
	
	camino();
	/*
	camino = camino.substr(1) + piso[0];
	*/
	
	system("pause>NULL");
	return 0;
	getch();
}


void cursor (int columna, int fila){
	HANDLE consola = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cordenaditas;
	cordenaditas.X = columna;
	cordenaditas.Y = fila;
	SetConsoleCursorPosition(consola,cordenaditas);
}

void camino (){
	//variables
	char tecla;
	int mov =100;
	
	char plano0 = 254;
	char plano1 =176;
	char plano2 = 177;
	char plano3 = 178;
	int ancho = 100;
	
	string camino1 = "";
	string camino2 = "";
	string camino3 = "";
	
	//sub desarrollo
	for(int i=0;i<ancho;i++){
		camino1.push_back(plano1);
	
	}
	for(int j=0;j<ancho/2;j++){
		camino2.push_back(plano2);
        camino2.push_back(plano0);
	}
	for(int p=0;p<ancho;p++){
		camino3.push_back(plano3);
	
	}
	
	
	
	
	//desarrollo
	
	while(1){
		system("cls");

		while(1){
		
		cursor(mov,4);
		cout<<" °<°";
		
		break;
		}
		mov--;
		
		
		while(1){
		
		cursor(mov,2);
		cout<<"*_*";
		
		break;
		}
		
		
		//Imprimir los caminos
		cursor(0,21); 
		cout<<camino1<<endl;
		camino1 = camino1.substr(1) + camino1[0];
		
		cursor(0,22); 
		cout<<camino2<<endl;
		camino2 = camino2.substr(1) + camino2[0];	
		
		cursor(0,23);
		cout<<camino3<<endl;
		camino3 = camino3.substr(1) + camino3[0];	
	
		Sleep(200); 
		
		
		if(kbhit()){
			
			tecla = getch();
			if(tecla==27){
				cursor(12,3);
				cout<<"SALIENDO..";
				break;
				//exit(0);
			}
		}
		
		
	}
	
}
