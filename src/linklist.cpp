#include "../include/linklist.h"
#include<iostream>
using namespace std;
linklist::linklist(){
    head=nullptr;
    tail=nullptr;
}

void linklist::Sethead(node* val) { head = val; }
node* linklist::Gethead() { return head; }

void linklist::Settail(node* val) { tail = val; }
node* linklist::Gettail() { return tail; }

void linklist::insertAtTail(treeNode* val){
    node* newnode=new node();
    newnode->Setdata(val);
    //cout<< val << endl;

    if(Gethead()==nullptr && Gettail()==nullptr)
    {
        Sethead(newnode);
        Settail(newnode);
    }
    else if(Gethead()==Gettail())
    {
        Settail(newnode);
        Gethead()->Setnext(Gettail());
    }
    else
    {
        Gettail()->Setnext(newnode);
        Settail(newnode);
    }
}
void linklist::displayFullLinklist(){
   /* if(Gethead()==nullptr && Gettail()==nullptr)
    {
        cout<< "List is Empty." ;
    }*/
    node* ptr=Gethead();
    while(ptr!=nullptr)
    {
        cout<< ptr->Getdata() << " " ;
        ptr=ptr->Getnext();
    }
    cout<< endl;
}
void linklist::deleteAtHead(){
    /*if(Gethead()==nullptr && Gettail()==nullptr)
    {
        cout<< "List is Empty." << endl;
    }*/
    node* ptr=Gethead();
    if(Gethead()==Gettail())
    {
        Sethead(nullptr);
        Settail(nullptr);
        delete ptr;
        ptr=nullptr;
    }
    else
    {
        Sethead(Gethead()->Getnext());
        delete ptr;
        ptr=nullptr;
    }
}

linklist::~linklist(){
    //dtor
}
