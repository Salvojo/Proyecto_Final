#include <iostream>//Hola bebassssssssssssssssss 
#include <conio.h> 
#include <windows.h> 
#include <string.h> 
using namespace std; 
 void gotoxy(int x,int y) 
{     HANDLE hcon;   
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);   
      COORD dwPos;   
      dwPos.X = x;   
      dwPos.Y= y;   
      SetConsoleCursorPosition(hcon,dwPos);  }  
       
void cuadro(const int x,const int y,const int x1,const int y1) 
{   char si=201,ii=200,sd=187,id=188,v=186,h=205;  
  int i,j; 
  gotoxy(x,y); cout<<si; 
  gotoxy(x1,y); cout<<sd; 
  for(i=x+1;i<x1;i++) 
     { gotoxy(i,y); cout<<h;  }   
  for(j=y+1;j<y1;j++) 
     { gotoxy(x,j); cout<<v;  } 
  gotoxy(x,y1); cout<<ii; 
  gotoxy(x1,y1); cout<<id; 
  for(j=y+1;j<y1;j++) 
     { gotoxy(x1,j); cout<<v;  } 
   for(i=x+1;i<x1;i++) 
     { gotoxy(i,y1); cout<<h;  }   
} 
 
bool clave()  
{ 
              int intentos=0;//Solo puede tener 3 intentos(Lo pidio la profe yo ns xd)
              const string clav="1234";//CLAVE CORRECTA
              do{
              system("cls");
              system("color 0A");
              char caracter;
              string claveing ="";//Reinicia la clave (Yo tmb me loquie, pense q solo con el do era)
              cuadro (30,5,80,20);
              gotoxy(35,7); cout << "Bienvenido al juego ";
              gotoxy(35,9); cout << "por favor ingrese la clave: ";
              while((caracter=getch()) != 13){//El 13 es el codigo del enter
                            claveing.push_back(caracter);//se agrega el caracter a la clave p
                            cout << "*";//Muestra el asterisco en vez de la clave
              }
              if(claveing == clav){
                            return true;
              }
              else{
                            intentos++;
                            gotoxy(35,11); cout << "Clave incorrecta. Intento " << intentos << " de 3" << endl;
                            gotoxy(35,13); cout << "presione una tecla para continuar..."; getch();
              }
}while(intentos<3);
return false;
} 
  
void clave_incorrecta() 
{ 
              system("cls");
              system("color 0A");
              cuadro (28,5,80,20);
              gotoxy(35,7); cout << "Intento 3 veces ingresar con una clave incorrecta";
              gotoxy(35,9); cout << "Comunicate con el administrador del sistema :b";

} 
 
void bienvenida() 
{
              system("cls");
    char a = 177;
    char b = 219;
    system("color 0A");
    gotoxy(38,7); cout << "Espere porfavor esta cargando";
    cout << "\t\t\t\t";//el \t es para los espacios horizontales xd
    for (int i = 0;i <= 50;i++)
        cout << a;
    cout << "\r";//el \r para que se regrese al inicio de la linea
    cout << "\t\t\t\t";
    for (int i = 0;i <= 50;i++)
    {
        cout << b;
        Sleep(50);
    }   
} 
 
void presentacion() 
{ 
              system("cls");
              system("color 0A");
              cuadro (28,5,80,20);
              gotoxy(47,12); cout << "En desarrollo :D";
} 
void instruccion(){
              system ("cls");
              system ("color 0A");
              cuadro (28,5,80,20);
              gotoxy(35,7); cout << "INSTRUCCIONES DEL JUEGO";
              gotoxy(35,9); cout << "1. El objetivo del juego es de....";
              gotoxy(35,17); cout << "Pulse una tecla para retornar al menu";
              getch();
               
}
void jugar(){
              system ("cls");
              system ("color 0A");
              cuadro (28,5,80,20);
              gotoxy(35,7); cout << "JUGUEMOS";
              gotoxy(35,9); cout << " Juego en desarrollo....";
              gotoxy(35,17); cout << "Pulse una tecla para retornar al menu";
              
              getch();

}
    int menu(){
              system("cls");
              int opc=0;
              system("color 0A");
                            cuadro (28,5,80,20);
                            int x=32;//Posision horizontal del menu
                            int y=9;//Posición vertical de la flecha
                            bool flag = true;
                            gotoxy(35,7); cout << "Menu de opciones";
                            gotoxy(35,9); cout << "1. Instrucciones del juego";
                            gotoxy(35,11); cout << "2. Jugar";
                            gotoxy(35,13); cout << "3. Salir";
                            gotoxy(35,15); cout << "Ingrese la opci\xA2n deseada: ";
                            while(flag){
                                          gotoxy(x-2,y); cout << ">";
                                          gotoxy(x+30,y); cout << "<";
                                          if(kbhit()){//Verificando si el user presiono una tecla
                                                        char tecla= getch();
                                                        gotoxy(x-2,y); cout << " ";
                                                        gotoxy(x+30,y); cout << " ";
                                                        if(tecla==72){
                                                        if(y==9){
                                                                      y=13;//SI esta en la 1era opc se salta a la ult 
                                                        }
                                                        else{
                                                                      y-=2; //subir a la opc anterior
                                                        }}
                                                        if(tecla==80){
                                                                      if(y==13){
                                                                                    y=9; //Si esta en la ult opc pasa a la primera
                                                                      }
                                                                      else{
                                                                                    y+=2;//Bajar a la sgte opc
                                                                      }}
                                                                      if(tecla==13){//Si presiona enter
                                                                                    opc=(y-9)/2+1;
                                                                                    system("cls");
                                                                                    flag=false;
                                                                      switch(opc){
                                                                                    case 1 :  instruccion();  return menu();
                                                                                    break;
                                                                                    case 2 :  jugar();  return menu();
                                                                                    break;
                                                                                    case 3 : exit(0);
                                                                                    default : gotoxy(35,17); cout << "Opci\xA3n no v\xA0lida";
                                                                                    return menu();
                                                                      }
                                                                      
                                                                      
                            
                                                                      }
                                                        
                                          }
                            }
                            

              return 0;
}

 
int main () 
{ 
    system("mode con cols=140 lines=30"); 
 system("COLOR A0"); 
  
 bool flag; 
 flag= clave(); 
 if (flag==false) 
     clave_incorrecta(); 
 else 
      {system("cls"); 
    bienvenida(); Sleep(2000);  system("cls"); 
                              presentacion(); Sleep(2000);  system("cls"); 
                              menu();
                } 
    
 
   getch(); 
   return 0;
}
