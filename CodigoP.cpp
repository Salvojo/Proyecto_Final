#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include <string.h>
#include <ctime>

using namespace std;

void gotoxy(int x,int y);
void cuadro(const int x,const int y,const int x1,const int y1);
void limpiarPantalla();
bool clave();
void clave_incorrecta();
void bienvenida();
void presentacion();
void instrucciones();
void jugar();
void creditos();
void salir();
void menu();
//funciones de la presentacion
void pin(int, int);
void cambio_color(int );

void cara1();
void cara2();
void cara3();
void cara4();
void cara5();
void juego ();
char generarPiedras();
char generarPiedras2();
char generarPiedras3();
void ocultarCursor();

int main() {
  	//SetConsoleOutputCP(CP_UTF8);
	//system("mode con cols=105 lines=25");
	//system("COLOR E0");
	//primero es la presentación (aqui algunas imagenes)
	ocultarCursor();
	presentacion();
	
	bool flag = clave();
	
	if (flag == false)
	    clave_incorrecta();
	else {
		bienvenida(); Sleep(200);
		system("mode con cols=105 lines=25"); 
     //Sleep(200);  
    menu(); 
    }
    system("pause>NULL");
	return 0;
}

void gotoxy(int x,int y) {
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);
}

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
    system("CLS");
}

bool clave() {

	srand(time(NULL));
  	//int ale = 1+ rand()%3
	string clave = "sipapiquerico";  
    int intentos = 0;      
	int aleatorio;
	int q;
    do {
	    limpiarPantalla(); 
       string claveIngresada = "";  
       char caracter;
       
       
       	cara3();
		//cuadro(20,8,90,12);     
   		gotoxy(40,9); cout << "INGRESE CLAVE: ";
   		
   		
		q=0;
        while ((caracter = getch()) != 13) {
               
			//movimiento de la cara
			aleatorio= (rand()% 3);

			if(aleatorio==1){
				cara3();
			}else if(aleatorio==2){
				cara4();
			}else if(aleatorio==3){
				cara5();
			}
				
			claveIngresada.push_back(caracter); 
            gotoxy(40+q,10);cout << "*"; 
			q++;                    
        }
        cout << endl;

        if (claveIngresada == clave) {
            return true;  
        } else {
            intentos++;  
            gotoxy(40,11); cout << "CLAVE INCORRECTA.";
			gotoxy(40,12);cout<<"INTENTO "<< intentos << " de 3." << endl; getch();
        }

    } while (intentos < 3);  
    
    return false;
}

void clave_incorrecta() {
    limpiarPantalla();        
    cuadro(20,8,90,12);     
    gotoxy(30,9); cout << "Intento 3 veces ingresar con una clave incorrecta." << endl;
    gotoxy(30,10); cout << "Comuniquese con el administrador";    
}

void bienvenida() {
    limpiarPantalla();        
    gotoxy(30,9); cout << "BIENVENIDO(A) AL JUEGO!!!";
}

void presentacion(){
    //VARIABLES CONTROL
    srand(time(NULL));
    int posX=50,posY=6;
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

void salir() {
    limpiarPantalla();        
    gotoxy(30,9); cout << "GRACIAS POR JUGAR. SALIENDO DEL JUEGO..." << endl;
    gotoxy(30,12); cout << "Presione una tecla para continuar" << endl;
    getch();
}

void menu() {
    limpiarPantalla();

    int x = 30; 
    int y = 10; 
    bool flag = true; 

    gotoxy(33,10); cout << "Instrucciones del Juego"; 
    gotoxy(33,12); cout << "Jugar";                  
    gotoxy(33,14); cout << "Creditos";               
    gotoxy(33,16); cout << "Salir";                  

    while (flag) {
        gotoxy(x - 2, y); cout << ">";
        gotoxy(x + 30, y); cout << "<";

        if (kbhit()) {
            char tecla = getch(); 

            gotoxy(x - 2, y); cout << " ";
            gotoxy(x + 30, y); cout << " ";

            if (tecla == 72) {
                if (y == 10)
                    y = 16; 
                else
                    y -= 2; 
            }

            if (tecla == 80) {
                if (y == 16)
                    y = 10; 
                else
                    y += 2; 
            }

            if (tecla == 13) {
                limpiarPantalla(); 
                flag = false;         

                switch (y) {
                    case 10: instrucciones();break;
                    case 12: jugar();break;
                    case 14: creditos();break;
                    case 16:salir();   break;
                }
                
                if (y != 16)
                    menu();
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

void cara1(){
	//OJOS DERECHO
	char a= 223, c=219;
	//para manejar el for
	const int m=40;
	//ancho de la cara
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
		gotoxy(m+i+2,21); cout<<" ";
		gotoxy(m+i+7,21); cout<<" ";
		
		gotoxy(m+i+2,22); cout<<" ";
		gotoxy(m+i+7,22); cout<<" ";
		
		gotoxy(m+i+2,23); cout<<" ";
		gotoxy(m+i+7,23); cout<<" ";
	}
	//iris
		gotoxy(m+2,21); cout<<a;
		gotoxy(m+7,21); cout<<a;
	
	
}

void cara2(){
	//OJOS IZQUIERDO
	char a= 223, c=219;
	//para manejar el for
	const int m=40;
	//ancho de la cara
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
		gotoxy(m+i+10,21); cout<<" ";
		gotoxy(m+i+15,21); cout<<" ";
		
		gotoxy(m+i+10,22); cout<<" ";
		gotoxy(m+i+15,22); cout<<" ";
		
		gotoxy(m+i+10,23); cout<<" ";
		gotoxy(m+i+15,23); cout<<" ";
	}
	//iris
		gotoxy(m+12,21); cout<<a;
		gotoxy(m+17,21); cout<<a;
	
}

void cara3(){
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

void pin (int x, int c){
    
    cambio_color (c);
    for (int i = 0; i < x; i++) {
        cout<<char(219);
    }

}
void cambio_color(int x){
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
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
