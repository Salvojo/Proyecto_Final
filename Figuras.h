#ifndef FIGURAS_H 
#define FIGURAS_H 
#include <iostream>
#include <conio.h>
using namespace std;
//contraseña
bool valcontra(void){
    int a;
    cin>>a;
    for(int control=1;control<3;control++){
        if(a==1523){
            cout<<"CLAVE CORRECTA"<<endl;;
            return true;
        }else {cout<<"Incorrecto"<<endl;
                cout<<"Ingrese clave";
                cin>>a;}
    }
    return false;
}
void imagen(){



    
}





#endif
