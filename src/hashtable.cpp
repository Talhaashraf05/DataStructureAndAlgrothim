#include "../include/hashtable.h"
#include <iostream>
#include <windows.h>
using namespace std;

hashtable::hashtable(){}

     hashtable :: hashtable(int s){
    size=s;
    arr=new AVL[size];
}
int  hashtable :: hashing(string name){
    string a=name;
    char b;
    if(a[0]=='T' && a[1]=='H' && a[2]=='E' && a[3]==' ' )
    {
        b=a[4];
    }
    else
    {
        b=a[0];
    }
    int position=b%26;
    if(b>='A' && b<='M')
    {
        position= position-13;
    }
    else if(b>='N' && b<='Z')
    {
        position=position+13;
    }
    return position;

}
AVL* hashtable :: insertInHash(int id, string name, string location){
    int position;
    position=hashing(name);
    arr[position].insertInAVLtreeWithValue(id,name,location);
}
void hashtable :: displayByHash(){
    for(int i=0; i<size; i++)
    {
        //cout<< "INDEX NO: " << i << endl;
        arr[i].displayINORDERByMain();
    }
}
void hashtable :: searchinHash(string name){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int position=hashing(name);
    treeNode* x=arr[position].Searchwithoutroot(name);
    if(x != nullptr)
    {
        SetConsoleTextAttribute(h,12);
        cout << "Value found" << endl;
        SetConsoleTextAttribute(h,5);
        cout << "ID: "       << x->Getid()             << "         " << endl;
        SetConsoleTextAttribute(h,1);
        cout << "NAME: "     << x->GethotelName()      << "         " << endl;
        SetConsoleTextAttribute(h,8);
        cout << "LOCATION: " << x->GethotelLocation()                 << endl;
        SetConsoleTextAttribute(h,7);
    }
    else
    {
        SetConsoleTextAttribute(h,12);
        cout << "Value NOT found" << endl;
        SetConsoleTextAttribute(h,7);
    }
}
void hashtable :: deleteInHash(string name){
    int position=hashing(name);
    arr[position].deleteNodeBYMAIN(name);
}
void hashtable :: writeInFileByHAsh(string filename){
    int num=1;
    ofstream fout(filename);
    if(!fout.is_open())
    {
        cout<< "FILE NOT OPEN" << endl;
    }
    else
    {
        for(int i=0; i<size; i++)
        {
            if(arr[i].Getroot()==nullptr)
            {
                //cout<< "TREE IS EMPTY" <<endl;
            }
            else
            {
                queu q;
                q.enqueue(arr[i].Getroot());
                while(!q.isEmpty())
                    {
                        treeNode* tem=q.peak();
                        if(num==1)
                        {
                            fout<< tem->Getid() << endl;
                            fout<< tem->GethotelName() << endl;
                            fout<< tem->GethotelLocation();
                            num=num+1;
                        }
                        else
                        {
                            fout<< endl;
                            fout<< tem->Getid() << endl;
                            fout<< tem->GethotelName() << endl;
                            fout<< tem->GethotelLocation();
                        }
                        q.dequeue();
                        if(tem->Getleft() != nullptr)
                        {
                            q.enqueue(tem->Getleft());
                        }
                        if(tem->Getright() != nullptr)
                        {
                            q.enqueue(tem->Getright());
                        }
                    }
                }
        }
    }
    fout.close();
}
void hashtable :: readFromFileByHAsh(string filename){
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    int id;
    string name,location;
    ifstream fin;

    fin.open(filename);

    if(!fin.is_open())
    {
        SetConsoleTextAttribute(h,4);
        cout<< "      FILE DOES NOT EXIST." <<endl;
        return;
    }
    else
    {
        while(!fin.eof())
        {
            fin>>id;
            fin.ignore();
            getline(fin,name);
            getline(fin,location);

            insertInHash(id, name, location);
        }
    }
}
     hashtable :: ~hashtable(){
    //dtor
}
