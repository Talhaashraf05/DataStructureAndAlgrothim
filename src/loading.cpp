#include "../include/loading.h"
#include <iostream>
#include <windows.h>
#include <dos.h>
using namespace std;

     loading :: loading(){
}
void loading :: load(){
   system("color B");
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    LOADING\n";
   char a=177, b=219;
   cout<<"\t\t\t\t\t\t";
   for (int i=0;i<=15;i++)
    cout<<a;
   cout<<"\r";
   cout<<"\t\t\t\t\t\t";
   for (int i=0;i<=15;i++)
    {
        cout<<b;
        Sleep(200);
    }
    system("cls");
}
     loading ::~loading(){
}
