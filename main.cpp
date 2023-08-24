#include <iostream>
#include <windows.h>
#include "include/AVL.h"
#include "include/hashtable.h"
#include "include/loading.h"
using namespace std;

int main(){
  loading objload;
  AVL obj;
  hashtable objhash(26);
  int option;
  string filename, val;
  HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

  objload.load();

do{
    cout<< endl;
    SetConsoleTextAttribute(h,3);
    cout << "1. Insert Node" << endl;
    cout << "2. Delete Node" << endl;
    cout << "3. print INoder" << endl;
    cout << "4. Clear Screen" << endl;
    cout << "5. Search Node" << endl;
    cout << "6. Write in File." << endl;
    cout << "7. Read From File." << endl;
    cout << "0. Exit Program" << endl;
    SetConsoleTextAttribute(h,6);
    cout << endl << "ENTER OPTION: " ;
    cin >> option;

    SetConsoleTextAttribute(h,7);
    switch (option)
    {
    case 0:{
        break;
    }
    case 1:{
           int valu;
           string nam, loac;

           SetConsoleTextAttribute(h,5);
           cout << "AVL INSERT" << endl;
           cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
           cin >> valu;
           cin.ignore();
           cout << "Enter NAME of HOTEL: ";
           getline(cin, nam);
           nam = obj.upper_string(nam);
           cout << "Enter location of HOTEL: ";
           getline(cin, loac);
           loac = obj.upper_string(loac);

           SetConsoleTextAttribute(h,12);
           objhash.insertInHash(valu, nam, loac);
           cout << endl;
           break;
        }
    case 2:{
            SetConsoleTextAttribute(h,2);
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
            cin.ignore();
            getline(cin, val);
            val = obj.upper_string(val);

            SetConsoleTextAttribute(h,14);
            objhash.deleteInHash(val);
            break;
        }
    case 3:{
            objhash.displayByHash();
            break;
        }
    case 4:{
            system("cls");
            break;
        }
    case 5:{
            SetConsoleTextAttribute(h,8);
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
            cin.ignore();
            getline(cin, val);
            val=obj.upper_string(val);

            objhash.searchinHash(val);
            break;
        }
    case 6:{
            SetConsoleTextAttribute(h,10);
            cout<< "ENTER FILENAME: ";
            cin.ignore();
            getline(cin,filename);

            objhash.writeInFileByHAsh(filename);

//            cout<< "WRITING IN FILE."<<endl ;
//            for(int i=0;i<8;i++)
//            {
//                cout <<"- ";
//                Sleep(500);
//            }
//            cout<< " DONE."<< endl;
            break;
        }
    case 7:{
            SetConsoleTextAttribute(h,10);
            cout<< "ENTER FILENAME: ";
            cin.ignore();
            getline(cin,filename);

            objhash.readFromFileByHAsh(filename);

            break;
        }
    default:{
            SetConsoleTextAttribute(h,4);
            cout << "Enter Proper Option number " << endl;
        }
    }
} while (option != 0);

SetConsoleTextAttribute(h,8);

return 0;
}
