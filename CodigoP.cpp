#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <ctime>
#include "figuritas.h"
#include <clocale> 
using namespace std;

bool clave();

void instrucciones();
void jugar();
void salir();
void menu();


void juego ();

void ocultarCursor();

int main() {
  	//SetConsoleOutputCP(CP_UTF8);
	//system("mode con cols=105 lines=25");
	//system("COLOR E0");

	ocultarCursor();
	presentacion();
	
	bool flag = clave();
	
	if (flag == false)
	    clave_incorrecta();
	else {
		bienvenida(); 
    menu(); 
    }
    system("pause>NULL");
	return 0;
}


bool clave() {

  	//int ale = 1+ rand()%3
	string clave = "1";  
    int intentos = 0;      

	int q, r;
    do {
	    limpiarPantalla(); 
       string claveIngresada = "";  
       char caracter;

       	cara3();
 
   		gotoxy(75,9); cout << "INGRESE CLAVE: ";

		q=0;r=0;
        while ((caracter = getch()) != 13) { 
			//movimiento de la cara
			if(r==3)
			cara4();
			if(r==7)
			cara5();
			
			claveIngresada.push_back(caracter); 
            gotoxy(75+q,10);cout << "*"; 
			q++;r++;                  
        }
        cout << endl;

        if (claveIngresada == clave) {
            return true;  
        } else {
            intentos++;  
            gotoxy(75,11); cout << "CLAVE INCORRECTA.";
			gotoxy(75,12);cout<<"INTENTO "<< intentos << " de 3." << endl; getch();
        }

    } while (intentos < 3);  
    
    return false;
}

void instrucciones() {
    limpiarPantalla();         
    gotoxy(30,9); cout << "INSTRUCCIONES:"<< endl;
    gotoxy(30,11); cout << "1. Pulsar flecha hacia arriba o barra spaciadora para saltar.";
    gotoxy(30,12); cout << "2. Evitar chocar con los obstaculos.";
    gotoxy(30,13); cout << "3. Disfrutar el juego.";
    gotoxy(30,15); cout << "A divertirse!!";
    gotoxy(30,18); cout << "Presione una tecla para continuar"<<endl;
    getch();
}

void jugar() {
    limpiarPantalla();
    juego();
    
     
     
            
    gotoxy(30,9); cout << "JUGAR EN CONSTRUCCION" << endl;
    gotoxy(30,12); cout << "Presione una tecla para continuar" << endl;
	  getch();
}


void salir() {
    limpiarPantalla();        
    gotoxy(30,9); cout << "GRACIAS POR JUGAR. SALIENDO DEL JUEGO..." << endl;
    gotoxy(30,12); cout << "Presione una tecla para continuar" << endl;
    getch();
}
void menu() {
    system("CLS");

    // Variables de configuración del menú
    int menuX = 40;          // Posición X del menú
    int menuY = 10;          // Posición Y inicial del menú
    int espaciado = 2;       // Espaciado entre opciones
    int indicadorOffset = 5; // Distancia de los indicadores < >
    
    // Variables de navegación
    int x = menuX;           // Posición X base (igual que el menú)
    int y = menuY;           // Posición Y actual
    bool flag = true;

    while (flag) {
        // Mostrar todas las opciones del menú con sus respectivos colores
        
        // Opción 1: INSTRUCCIONES DEL JUEGO
        gotoxy(menuX, menuY);
        if (y == menuY) {
            cambio_color(14); // Amarillo brillante si está seleccionada
        } else {
            cambio_color(15); // Blanco si no está seleccionada
        }
        cout << "INSTRUCCIONES DEL JUEGO";
        
        // Opción 2: JUGAR
        gotoxy(menuX, menuY + espaciado);
        if (y == menuY + espaciado) {
            cambio_color(14); // Amarillo brillante si está seleccionada
        } else {
            cambio_color(15); // Blanco si no está seleccionada
        }
        cout << "JUGAR";
        
        // Opción 3: CREDITOS
        gotoxy(menuX, menuY + espaciado * 2);
        if (y == menuY + espaciado * 2) {
            cambio_color(14); // Amarillo brillante si está seleccionada
        } else {
            cambio_color(15); // Blanco si no está seleccionada
        }
        cout << "CREDITOS";
        
        // Opción 4: SALIR
        gotoxy(menuX, menuY + espaciado * 3);
        if (y == menuY + espaciado * 3) {
            cambio_color(14); // Amarillo brillante si está seleccionada
        } else {
            cambio_color(15); // Blanco si no está seleccionada
        }
        cout << "SALIR";
        
        // Mostrar las flechas indicadoras en color cian
        cambio_color(11); // Cian brillante para las flechas
        gotoxy(x - indicadorOffset, y); 
        cout << ">";
        gotoxy(x + 30, y); 
        cout << "<";
        
        // Restaurar color por defecto
        cambio_color(15);

        if (kbhit()) {
            char tecla = getch(); 

            // Limpiar las flechas indicadoras
            gotoxy(x - indicadorOffset, y); 
            cout << " ";
            gotoxy(x + 30, y); 
            cout << " ";

            if (tecla == 72) { // Flecha arriba
                if (y == menuY) {
                    y = menuY + espaciado * 3; // Ir a la última opción (SALIR)
                } else {
                    y = y - espaciado; // Subir una opción
                }
            }

            if (tecla == 80) { // Flecha abajo
                if (y == menuY + espaciado * 3) {
                    y = menuY; // Ir a la primera opción (INSTRUCCIONES)
                } else {
                    y = y + espaciado; // Bajar una opción
                }
            }

            if (tecla == 13) { // Enter
                limpiarPantalla(); 
                flag = false;         

                // Ejecutar la función correspondiente según la posición Y
                if (y == menuY) {
                    instrucciones();
                } else if (y == menuY + espaciado) {
                    jugar();
                } else if (y == menuY + espaciado * 2) {
                    creditos();
                } else if (y == menuY + espaciado * 3) {
                    salir();
                }
                
                // Volver al menú si no se seleccionó "SALIR"
                if (y != menuY + espaciado * 3) {
                    menu();
                }
            }
        }
    }
}
void juego (){
	srand(time(NULL));
	
	//variables
	char tecla;
	int mov =200;
	
	char piso1 = 95;
	
	//Representa la distancia del camino
	int ancho = 100;

	string PISO = "";
	string rocas ="";
	string rocas2 ="";
	string rocas3 ="";
	
	//PISO AVER
	
	//Algo aleatorio roquitas en la primera linea
	for(int e=0;e<ancho;e++){
		rocas += generarPiedras();
	}
	//Roquitas en la segunda linea
		for(int p=0;p<ancho;p++){
		rocas2 += generarPiedras2();
	}
	//Roquitas en la tercera linea
		for(int j=0;j<ancho;j++){
		rocas3 += generarPiedras3();
	}
	
	
	//Algo constante como el piso
	for(int r=0;r<ancho; r++){
		PISO.push_back(piso1);
	}
	
		
	
	while(true){
		
		gotoxy(0,21);
        cout<<PISO;
		
		
		gotoxy(0,22);
		cout<<rocas;
		rocas= rocas.substr(1)+ rocas[0];	
	
		gotoxy(0,23);
		cout<<rocas2;
		rocas2= rocas2.substr(1)+ rocas2[0];
	
	
		gotoxy(0,24);
		cout<<rocas3;
		rocas3= rocas3.substr(1)+ rocas3[0];
	
		if(kbhit()){
			
			tecla = getch();
			if(tecla==27){
				gotoxy(12,3);
				cout<<"SALIENDO..";
				break;
				
			}
		}
		
		
		
		Sleep(150);
		system("cls");
	}
	
	
}

void ocultarCursor() {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hcon != INVALID_HANDLE_VALUE) {
        CONSOLE_CURSOR_INFO cci;
        cci.dwSize = 1;
        cci.bVisible = FALSE;
        SetConsoleCursorInfo(hcon, &cci);
    }
}
