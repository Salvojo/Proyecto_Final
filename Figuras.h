#ifndef FIGURITAS_H
#define FIGURITAS_H

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <ctime>
using namespace std;

void gotoxy(int x,int y) {
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);
}
const int ancho_personaje = 5;
const int alto_personaje = 5;
const int ancho_arbol = 3;
const int alto_arbol = 3;
const int ancho_ave = 3;
const int alto_ave = 3;
// Variables globales
char personaje[alto_personaje][ancho_personaje] = {
    {char(219), char(219), char(219), char(219), char(219)},
    {char(219),' ', char(219),' ', char(219)},
    {char(219),' ', char(219),' ', char(219)},
    {char(219), char(219) , char(219),char(219),char(219)},
    {char(219), char(219) , char(219),char(219),char(219)},
};

char arbol[alto_arbol][ancho_arbol] = {
    {' ', 'V', ' '},
    {'V', 'A', 'V'},
    {' ', 'A', ' '}
};
char ave[alto_ave][ancho_ave] = {
    {' ','-', ' '},
    {'-', char(254),'-' },
    {' ', '-', ' '}
};
char piedra [3][3] = {
    {char(219),char(219),char(219)},
    {char(219),char(219),char(219)},
    {char(219),char(219),char(219)}
};
void cuadro(const int x,const int y,const int x1,const int y1) {
    char si = 201,ii = 200,sd = 187,id = 188,v = 186,h = 205; 
 	  int i,j;
 	
	  gotoxy(x,y); cout << si;
 	  gotoxy(x1,y); cout << sd;
 	
	  for(i = x + 1;i < x1;i++) {
	     gotoxy(i,y); cout << h;  
	  }  
 	
	  for(j = y + 1;j < y1;j++) { 
	     gotoxy(x,j); cout << v;
	  }
 	
	  gotoxy(x,y1); cout << ii;
 	  gotoxy(x1,y1); cout << id;
 	
	  for(j = y + 1;j < y1;j++) {
	     gotoxy(x1,j); cout << v;
	  }
  	
	  for(i = x + 1;i <x1;i++) {
	     gotoxy(i,y1); cout <<h;
	  }  
}

void limpiarPantalla() {
    system("cls");
}

void cambio_color(int x){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
} 

void pin (int x, int c){
    
    cambio_color (c);
    for (int i = 0; i < x; i++) {
        cout<<char(219);
    }

}
void colorTextoFondo(int colorTexto, int colorFondo = 0, bool usarFondoActual = true) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD fondoFinal;

    if (usarFondoActual) {
        GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
        fondoFinal = consoleInfo.wAttributes & 0xF0; // fondo actual
    } else {
        fondoFinal = (colorFondo & 0x0F) << 4; // nuevo fondo
    }

    WORD atributo = fondoFinal | (colorTexto & 0x0F);
    SetConsoleTextAttribute(hConsole, atributo);
}

void cara2(){
	//OJOS IZQUIERDO
	char a= 223, c=219;
	//para manejar el for
	int m=40;
	//ancho de la cara
	int n=20;
	int y= 20;// vertical de la cara
	do{
	for(int i=0;i<n;i++){
		gotoxy(m+i,y); cout<<c;
		gotoxy(m+i,y+1); cout<<c;
		gotoxy(m+i,y+2); cout<<c;
		gotoxy(m+i,y+3); cout<<c;
		gotoxy(m+i,y+4); cout<<c;
		gotoxy(m+i,y+5); cout<<c;
		gotoxy(m+i,y+6); cout<<c;
		gotoxy(m+i,y+7); cout<<c;
		gotoxy(m+i,y+8); cout<<c;
	}
	//ojos
	for(int i=0; i<3;i++){
		gotoxy(m+i+10,y+1); cout<<" ";
		gotoxy(m+i+15,y+1); cout<<" ";
		
		gotoxy(m+i+10,y+2); cout<<" ";
		gotoxy(m+i+15,y+2); cout<<" ";
		
		gotoxy(m+i+10,y+3); cout<<" ";
		gotoxy(m+i+15,y+3); cout<<" ";
	}
	//iris
		gotoxy(m+12,y+3); cout<<a;
		gotoxy(m+17,y+3); cout<<a;
	m++;
	Sleep(20);
	}while(m<110);
}

void cara3(){
	//OJOS AL MEDIO
	char a= 223, c=219;
	//para manejar el for
	const int m=75;
	int n=20;

	for(int i=0;i<n;i++){
		gotoxy(m+i,20); cout<<c;
		gotoxy(m+i,21); cout<<c;
		gotoxy(m+i,22); cout<<c;
		gotoxy(m+i,23); cout<<c;
		gotoxy(m+i,24); cout<<c;
		gotoxy(m+i,25); cout<<c;
		gotoxy(m+i,26); cout<<c;
		gotoxy(m+i,27); cout<<c;
		gotoxy(m+i,28); cout<<c;
	}
	//ojos
	for(int i=0; i<3;i++){
		gotoxy(m+i+6,21); cout<<" ";
		gotoxy(m+i+11,21); cout<<" ";
		
		gotoxy(m+i+6,22); cout<<" ";
		gotoxy(m+i+11,22); cout<<" ";
		
		gotoxy(m+i+6,23); cout<<" ";
		gotoxy(m+i+11,23); cout<<" ";
	}
	//iris
		gotoxy(m+8,21); cout<<a;
		gotoxy(m+13,21); cout<<a;
	
}
void cara4(){
	//OJOS AL MEDIO
	char a= 223, c=219;
	//para manejar el for
	const int m=40;
	int n=20;

	for(int i=0;i<n;i++){
		gotoxy(m+i,20); cout<<c;
		gotoxy(m+i,21); cout<<c;
		gotoxy(m+i,22); cout<<c;
		gotoxy(m+i,23); cout<<c;
		gotoxy(m+i,24); cout<<c;
		gotoxy(m+i,25); cout<<c;
		gotoxy(m+i,26); cout<<c;
		gotoxy(m+i,27); cout<<c;
		gotoxy(m+i,28); cout<<c;
	}
	//ojos
	for(int i=0; i<3;i++){
		//gotoxy(m+i+6,21); cout<<" ";
		gotoxy(m+i+11,21); cout<<" ";
		
		//gotoxy(m+i+6,22); cout<<" ";
		gotoxy(m+i+11,22); cout<<" ";
		
		gotoxy(m+i+6,23); cout<<" ";
		gotoxy(m+i+11,23); cout<<" ";
	}
	//iris
		//gotoxy(m+8,21); cout<<a;
		gotoxy(m+13,21); cout<<a;
	
}
void cara5(){
	//OJOS AL MEDIO
	char a= 223, c=219;
	//para manejar el for
	const int m=110;
	int n=20;

	for(int i=0;i<n;i++){
		gotoxy(m+i,20); cout<<c;
		gotoxy(m+i,21); cout<<c;
		gotoxy(m+i,22); cout<<c;
		gotoxy(m+i,23); cout<<c;
		gotoxy(m+i,24); cout<<c;
		gotoxy(m+i,25); cout<<c;
		gotoxy(m+i,26); cout<<c;
		gotoxy(m+i,27); cout<<c;
		gotoxy(m+i,28); cout<<c;
	}
	//ojos
	for(int i=0; i<3;i++){
		gotoxy(m+i+6,21); cout<<" ";
		//gotoxy(m+i+11,21); cout<<" ";
		
		gotoxy(m+i+6,22); cout<<" ";
		//gotoxy(m+i+11,22); cout<<" ";
		
		gotoxy(m+i+6,23); cout<<" ";
		gotoxy(m+i+11,23); cout<<" ";
	}
	//iris
		gotoxy(m+8,21); cout<<a;
		//gotoxy(m+13,21); cout<<a;
	
}

char generarPiedras(){

	int aleatorio = rand()%15;
	char opciones[]={'.',' ',' ',' ',' ',' ',' ',' ','_',' ',' ',' ','-',' ',' '};
	
	return opciones[aleatorio];
}
char generarPiedras2(){
	
	int aleatorio = rand()%15;
	char opciones[]={'.',' ',' ',' ',' ','_',' ',' ',' ',' ',' ',' ',' ',' ',' '};
	
	return opciones[aleatorio];
}
char generarPiedras3(){
	
	int aleatorio = rand()%15;
	char opciones[]={' ',' ',' ',' ',' ',' ',' ',' ','.',' ',' ',' ',' ',' ',' '};
	
	return opciones[aleatorio];
}


void bienvenida() {
    limpiarPantalla();        

	cara2();
	colorTextoFondo(5,15,false);
	gotoxy(70,23); cout << "BIENVENIDO(A) AL JUEGO!!!";getch();
	colorTextoFondo(7,0,false);
}
void presentacion(){
    //VARIABLES CONTROL
    srand(time(NULL));
    int posX=65,posY=18;
    int c=255;//  "c" es de color
    int b=0;//mueve solo el BIT para que encage
    int r=0;//mueve solo el RUNNER
    while(true){
    //BIT
    //cout << "\n\t";//1era linea
    gotoxy(b+posX,posY);pin(6,c);
    gotoxy(b+posX+8,posY);pin(2,c);
    gotoxy(b+posX+12,posY);pin(6,c);

    //cout << "\n\t";//2da linea
    gotoxy(b+posX,posY+1);pin(2,c);
    gotoxy(b+posX+4,posY+1);pin(2,c);
    gotoxy(b+posX+8,posY+1);pin(2,c);
    gotoxy(b+posX+14,posY+1);pin(2,c);

    //cout << "\n\t";//3 linea
    gotoxy(b+posX,posY+2);pin(6,c);
    gotoxy(b+posX+8,posY+2);pin(2,c);
    gotoxy(b+posX+14,posY+2);pin(2,c);
    
    //cout << "\n\t";//4 linea
    gotoxy(b+posX,posY+3);pin(4,c);
    gotoxy(b+posX+8,posY+3);pin(2,c);
    gotoxy(b+posX+14,posY+3);pin(2,c);

    //cout << "\n\t";//5 linea
    gotoxy(b+posX,posY+4);pin(6,c);
    gotoxy(b+posX+8,posY+4);pin(2,c);
    gotoxy(b+posX+14,posY+4);pin(2,c);
    
    //cout << "\n\t";//6da linea
    gotoxy(b+posX,posY+5);pin(2,c);
    gotoxy(b+posX+4,posY+5);pin(2,c);
    gotoxy(b+posX+8,posY+5);pin(2,c);
    gotoxy(b+posX+14,posY+5);pin(2,c);

    //cout << "\n\t";//7 linea
    gotoxy(b+posX,posY+6);pin(6,c);
    gotoxy(b+posX+8,posY+6);pin(2,c);
    gotoxy(b+posX+14,posY+6);pin(2,c);


    //RUNNER
    //cout << "\n\t";//1 linea
    gotoxy(r+posX-16,posY+8);pin(6,c);
    gotoxy(r+posX-8,posY+8);pin(2,c);
    gotoxy(r+posX-4,posY+8);pin(2,c);
    gotoxy(r+posX,posY+8);pin(2,c);
    gotoxy(r+posX+6,posY+8);pin(2,c);
    gotoxy(r+posX+10,posY+8);pin(2,c);
    gotoxy(r+posX+16,posY+8);pin(2,c);
    gotoxy(r+posX+20,posY+8);pin(4,c);
    gotoxy(r+posX+26,posY+8);pin(6,c);
    //cout << "\n\t";//2 linea
    gotoxy(r+posX-16,posY+9);pin(2,c);
    gotoxy(r+posX-12,posY+9);pin(2,c);
    gotoxy(r+posX-8,posY+9);pin(2,c);
    gotoxy(r+posX-4,posY+9);pin(2,c);
    gotoxy(r+posX,posY+9);pin(4,c);
    gotoxy(r+posX+6,posY+9);pin(2,c);
    gotoxy(r+posX+10,posY+9);pin(4,c);
    gotoxy(r+posX+16,posY+9);pin(2,c);
    gotoxy(r+posX+20,posY+9);pin(2,c);
    gotoxy(r+posX+26,posY+9);pin(2,c);
    gotoxy(r+posX+30,posY+9);pin(2,c);
    //cout << "\n\t";//3 linea
    gotoxy(r+posX-16,posY+10);pin(6,c);
    gotoxy(r+posX-8,posY+10);pin(2,c);
    gotoxy(r+posX-4,posY+10);pin(2,c);
    gotoxy(r+posX,posY+10);pin(8,c);
    gotoxy(r+posX+10,posY+10);pin(8,c);
    gotoxy(r+posX+20,posY+10);pin(4,c);
    gotoxy(r+posX+26,posY+10);pin(6,c);
    //cout << "\n\t";//4 linea
    gotoxy(r+posX-16,posY+11);pin(4,c);
    gotoxy(r+posX-8,posY+11);pin(2,c);
    gotoxy(r+posX-4,posY+11);pin(2,c);
    gotoxy(r+posX,posY+11);pin(2,c);
    gotoxy(r+posX+4,posY+11);pin(4,c);
    gotoxy(r+posX+10,posY+11);pin(2,c);
    gotoxy(r+posX+14,posY+11);pin(4,c);
    gotoxy(r+posX+20,posY+11);pin(4,c);
    gotoxy(r+posX+26,posY+11);pin(4,c);
    //cout << "\n\t";//5 linea
    gotoxy(r+posX-16,posY+12);pin(2,c);
    gotoxy(r+posX-12,posY+12);pin(2,c);
    gotoxy(r+posX-8,posY+12);pin(2,c);
    gotoxy(r+posX-4,posY+12);pin(2,c);
    gotoxy(r+posX,posY+12);pin(2,c);
    gotoxy(r+posX+4,posY+12);pin(4,c);
    gotoxy(r+posX+10,posY+12);pin(2,c);
    gotoxy(r+posX+14,posY+12);pin(4,c);
    gotoxy(r+posX+20,posY+12);pin(2,c);
    gotoxy(r+posX+26,posY+12);pin(2,c);
    gotoxy(r+posX+30,posY+12);pin(2,c);
    //cout << "\n\t";//6 linea
    gotoxy(r+posX-16,posY+13);pin(2,c);
    gotoxy(r+posX-12,posY+13);pin(2,c);
    gotoxy(r+posX-8,posY+13);pin(6,c);
    gotoxy(r+posX,posY+13);pin(2,c);
    gotoxy(r+posX+6,posY+13);pin(2,c);
    gotoxy(r+posX+10,posY+13);pin(2,c);
    gotoxy(r+posX+16,posY+13);pin(2,c);
    gotoxy(r+posX+20,posY+13);pin(4,c);
    gotoxy(r+posX+26,posY+13);pin(2,c);
    gotoxy(r+posX+30,posY+13);pin(2,c);

	c= 257 + (rand()% 267);
	if(kbhit()){
		char tecla = getch();
		if(tecla==13){
			break;
			}
		}
		
    Sleep(1000);
    }
	cambio_color(15);
}

void clave_incorrecta() {
    limpiarPantalla();        
    
	for(int i=0; i<58;i++){
		gotoxy(0,i);
		for(int j=0; j<18;j++){
		cout<<"ERROR 404 ";
		//Sleep(2);
		}

	}
	
	int a=45,b=22,c=116,d=25;
	cuadro(a,b-1,c,d+1); 
	for(int i=0; i<4; i++){
		gotoxy(a+1, b+i);
		for(int j =0; j<70;j++){
			cout<<" ";
		}
	}    
    gotoxy(a+11,b+1); cout << "INTENTO 3 VECES INGRRESAR CON UNA CLAVE INCORRECTA" << endl;
    gotoxy(a+11,b+2); cout << "	COMUNIQUESE CON EL ADMINISTRADOR";  
	
}

void creditos() {
    limpiarPantalla();         
    gotoxy(30,9); cout << "CREDITOS:" << endl;
    gotoxy(30,11); cout << "Desarrolladores del juego:";
    gotoxy(30,12); cout << "- Figueroa Campos, Cristhofer";
    gotoxy(30,13); cout << "- Pesantes Huaylla, Jhunior";
    gotoxy(30,14); cout << "- Horna Fabian, Isai";
    gotoxy(30,15); cout << "- Burgos Mendoza, Cristian";
    gotoxy(30,18); cout << "Presione una tecla para continuar" << endl;
    getch();
}

#endif 
