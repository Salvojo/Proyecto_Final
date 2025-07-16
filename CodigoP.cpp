#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <ctime>
#include "figuritas.h"
#include <clocale> 
using namespace std;
bool colision(int x1, int y1, int x2, int y2);

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
bool colision(int x1, int y1, int x2, int y2) {
    // Verificar si los rectángulos se superponen
    if (x1 < x2 + ancho_arbol && 
        x1 + ancho_personaje > x2 &&
        y1 < y2 + alto_arbol && 
        y1 + alto_personaje > y2) {
        
        // Verificar colisión píxel a píxel
        for (int i = 0; i < alto_personaje; i++) {
            for (int j = 0; j < ancho_personaje; j++) {
                if (personaje[i][j] == ' ') continue;

                int px = x1 + j;
                int py = y1 + i;

                for (int m = 0; m < alto_arbol; m++) {
                    for (int n = 0; n < ancho_arbol; n++) {
                        if (arbol[m][n] == ' ') continue;

                        int ax = x2 + n;
                        int ay = y2 + m;

                        if (px == ax && py == ay) return true;
                    }
                }
            }
        }
    }
    return false;
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
    // ==PUNTAJE==
    float score =0;
    int control_sleep=60;
    // ==VELOCIDAD==
    int velocidad =0;
    // === CONFIGURACIÓN DEL JUEGO ===
    const int ancho_camino = 130;
    const int posicion_piso = 27;
    
    // === VARIABLES DEL PERSONAJE ===
    int y_personaje = 22;
    int y_personaje_anterior = y_personaje;
    int gravedad = 1;
    int salto = 0;
    bool enelAire = false;
    
    // === VARIABLES DEL ÁRBOL ===
    int pos_X_arbol = 60;
    int pos_Y_arbol = 29;
    int pos_X_arbol_anterior = 60;
    
    // === VARIABLES DE LA PIEDRA ===
    int pos_X_piedra = 80;
    int pos_Y_piedra = 29;
    int pos_X_piedra_anterior = 80;
    
    // === VARIABLES DEL AVE ===
    int pos_X_ave = 100;
    int pos_Y_ave = 20;
    int pos_X_ave_anterior = 100;
    
    // === VARIABLES DEL ESCENARIO ===
    string PISO = "";
    string rocas = "";
    string rocas2 = "";
    string rocas3 = "";
    char piso1 = '_';
    
    // === CONTROL DE ENTRADA ===
    char tecla;
    
    // Generar el piso y las rocas
    for(int e = 0; e < ancho_camino; e++) {
        rocas += generarPiedras();
    }
    for(int p = 0; p < ancho_camino; p++) {
        rocas2 += generarPiedras2();
    }
    for(int j = 0; j < ancho_camino; j++) {
        rocas3 += generarPiedras3();
    }
    for(int r = 0; r < ancho_camino; r++) {
        PISO.push_back(piso1);
    }
    
    // Limpiar pantalla inicial
    system("cls");
    
    while(true) {
        // Borrar posición anterior del personaje usando la posición anterior guardada
        for (int i = 0; i < alto_personaje; i++) {
            gotoxy(5, y_personaje_anterior + i );
            cout << "     "; // 5 espacios
        }
        
        // Borrar posición anterior del árbol usando la posición anterior guardada
        for (int i = 0; i < alto_arbol; i++) {
            gotoxy(pos_X_arbol_anterior, pos_Y_arbol + i);
            cout << "   "; // 3 espacios
        }
        // Borrar posición anterior de la piedra usando la posición anterior guardada
        for (int i = 0; i < 3; i++) {
            gotoxy(pos_X_piedra_anterior, pos_Y_piedra + i);
            cout << "   "; // 3 espacios
        }
        // Borrar posición anterior del ave usando la posición anterior guardada
        for (int i = 0; i < alto_ave; i++) {
            gotoxy(pos_X_ave_anterior, pos_Y_ave + i);
            cout << "   "; // 3 espacios
        }
        
        // Dibujar el piso
        gotoxy(0, posicion_piso + 4); cout << PISO; //Empieza desde el 2 por las dimensiones - 1....
        gotoxy(0, posicion_piso + 5); cout << rocas; //....Las dimensiones del personaje y arbol
        gotoxy(0, posicion_piso + 6); cout << rocas2;
        gotoxy(0, posicion_piso + 7); cout << rocas3;

        // Mover las rocas (efecto de scroll)
        rocas = rocas.substr(1) + rocas[0];
        rocas2 = rocas2.substr(1) + rocas2[0];
        rocas3 = rocas3.substr(1) + rocas3[0];

        // Dibujar personaje
        for (int i = 0; i < alto_personaje; i++) {
            gotoxy(5, y_personaje + i );
            for (int j = 0; j < ancho_personaje; j++) {
                cout << personaje[i][j];
            }
        }
        

        for (int i = 0; i < alto_arbol; i++) {
            gotoxy(pos_X_arbol, pos_Y_arbol + i );
            for (int j = 0; j < ancho_arbol; j++) {
                if (arbol[i][j] == 'V') {
                    cambio_color(10); // Verde
                    cout << char(219);
                } else if (arbol[i][j] == 'A') {
                    cambio_color(6); // Amarillo
                    cout << char(219);
                } else {
                    cambio_color(7); // Color por defecto
                    cout << ' ';
                }
                cambio_color(7); // Restablece color
            }
        }

        // Dibujar piedra
        for (int i = 0; i < 3; i++) {
            gotoxy(pos_X_piedra, pos_Y_piedra + i );
            for (int j = 0; j < 3; j++) {
                cout << piedra[i][j];
            }
        }

        // Dibujar ave
        for (int i = 0; i < alto_ave; i++) {
            gotoxy(pos_X_ave, pos_Y_ave + i );
            for (int j = 0; j < ancho_ave; j++) {
                cout << ave[i][j];
            }
        }

        // Mover el árbol hacia la izquierda
        pos_X_arbol_anterior = pos_X_arbol;
        pos_X_arbol--;
        if(pos_X_arbol < 0) {
            pos_X_arbol = 80 + rand() % 40; // Posición aleatoria
        }
        
        // Mover la piedra hacia la izquierda
        pos_X_piedra_anterior = pos_X_piedra;
        pos_X_piedra--;
        if(pos_X_piedra < 0) {
            pos_X_piedra = 100 + rand() % 20; // Posición aleatoria
        }


        // Mover el ave de izquierda a derecha
        pos_X_ave_anterior = pos_X_ave;
        pos_X_ave--;
        if(pos_X_ave < 0) {
            pos_X_ave = 100 + rand() % 30; // Posición aleatoria de respawn
        }

        // Verificar colisión
        if (colision(5, y_personaje - 4, pos_X_arbol, pos_Y_arbol - 2)) {// Los "2" son las dimensiones - 1
            gotoxy(30, 5);
            cout << "GAME OVER! Presiona cualquier tecla...";
            getch();
            break;
        }
        // Verificar colisión
        if (colision(5, y_personaje - 4, pos_X_piedra, pos_Y_piedra - 2)) {// Los "2" son las dimensiones - 1
            gotoxy(30, 5);
            cout << "GAME OVER! Presiona cualquier tecla...";
            getch();
            break;
        }
        // Verificar colisión
        if (colision(5, y_personaje - 4, pos_X_ave, pos_Y_ave - 2)) {
            gotoxy(30, 5);
            cout << "GAME OVER! Presiona cualquier tecla...";
            getch();
            break;
        }

        // Controles
        if(kbhit()) {
            tecla = getch();

            if((tecla == 'w' || tecla == 32) && !enelAire) {
                salto = 10; // Altura del salto
                enelAire = true;
            }    
            
            if(tecla == 27) { // ESC para salir
                gotoxy(30, 5); 
                cout << "SALIENDO...";
                Sleep(1000);
                break;
            }
        }

        // Mecánica de salto y gravedad
        y_personaje_anterior = y_personaje; // Guardar posición anterior antes de cambiar
        if(salto > 0) {
            y_personaje -= 1; // Subir
            salto--;
        } else if (y_personaje < posicion_piso) {
            y_personaje += gravedad; // Caer por gravedad
        } else {
            enelAire = false;
        }

        // PUNTAJE
        if(score == int(score)){
        gotoxy(45, 2);cout << "PUNTAJE: "<<score;
        }
        score +=0.5;

        //VELOCIDAD
        if(velocidad%15==0 && control_sleep>10){
        control_sleep--;
        }
        velocidad++;
        Sleep(control_sleep);   

    }
	
	//variables
	
	
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
