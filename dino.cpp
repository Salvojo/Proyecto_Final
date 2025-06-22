#include <iostream>//ya no quiero programar xd 
#include <conio.h>
#include <windows.h>
using namespace std;
void gotoxy(int x,int y)
{ 
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);   
    COORD dwPos;   
    dwPos.X = x;    
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);}

void parado(int a){  
system("cls");   
gotoxy(10,a);
cout<<"              ########"<<endl;
gotoxy(10,a+1);
cout<<"             ####  ####"<<endl;
gotoxy(10,a+2);
cout<<"             ##########"<<endl;
gotoxy(10,a+3);
cout<<"             ######"<<endl;
gotoxy(10,a+4);
cout<<" #          #########"<<endl;
gotoxy(10,a+5);
cout<<" ####    ########"<<endl;
gotoxy(10,a+6);
cout<<" #####  #############"<<endl;
gotoxy(10,a+7);
cout<<" ################  ##"<<endl;
gotoxy(10,a+8);
cout<<"   #############"<<endl;
gotoxy(10,a+9);
cout<<"     #####  #####"<<endl;
gotoxy(10,a+10);
cout<<"     ##    ##"<<endl;
gotoxy(10,a+11);
cout<<"     #     #"<<endl;
gotoxy(10,a+12);
cout<<"     ##    ##"<<endl;
}    

void figura(int c){
    bool control=true;
for(int a=0;a>=0;a++){
system("color 04");
Sleep(100);
system("cls");
gotoxy(10,c);
cout<<"              ########"<<endl;
gotoxy(10,c+1);
cout<<"             ####  ####"<<endl;
gotoxy(10,c+2);
cout<<"             ##########"<<endl;
gotoxy(10,c+3);
cout<<"             ######"<<endl;
gotoxy(10,c+4);
cout<<" #          #########"<<endl;
gotoxy(10,c+5);
cout<<" ####    ########"<<endl;
gotoxy(10,c+6);
cout<<" #####  #############"<<endl;
gotoxy(10,c+7);
cout<<" ################  ##"<<endl;
gotoxy(10,c+8);
cout<<"   #############"<<endl;
gotoxy(10,c+9);
cout<<"     #####  #####"<<endl;
gotoxy(10,c+10);
cout<<"     ##    ##"<<endl;
gotoxy(10,c+11);
cout<<"     #      "<<endl;
gotoxy(10,c+12);
cout<<"     ##     "<<endl;
Sleep(100);
system("cls");
gotoxy(10,c);
cout<<"              ########"<<endl;
gotoxy(10,c+1);
cout<<"             ####  ####"<<endl;
gotoxy(10,c+2);
cout<<"             ##########"<<endl;
gotoxy(10,c+3);
cout<<"             ######"<<endl;
gotoxy(10,c+4);
cout<<" #          #########"<<endl;
gotoxy(10,c+5);
cout<<" ####    ########"<<endl;
gotoxy(10,c+6);
cout<<" #####  #############"<<endl;
gotoxy(10,c+7);
cout<<" ################  ##"<<endl;
gotoxy(10,c+8);
cout<<"   #############"<<endl;
gotoxy(10,c+9);
cout<<"     #####  #####"<<endl;
gotoxy(10,c+10);
cout<<"     #      ##"<<endl;
gotoxy(10,c+11);
cout<<"            #"<<endl;
gotoxy(10,c+12);
cout<<"            ##"<<endl;
if (kbhit()){
    char tecla = getch();
     if (tecla == 72){
        parado(5);
        Sleep(95);
        c=15;
                    }
     //if(tecla == 80)
       // c=15;

}   
}}

int main(){
figura(15);
}

