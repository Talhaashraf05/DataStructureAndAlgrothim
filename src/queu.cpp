#include "../include/queu.h"
#include<iostream>
using namespace std;

queu::queu(){
}

queu::~queu(){
    //dtor
}

bool queu::isEmpty(){
    if(list1.Gethead()==nullptr && list1.Gettail()==nullptr)
    {
        return true;
    }
    else
        return false;
}

void queu::enqueue(treeNode* val){
    list1.insertAtTail(val);
}

treeNode* queu::peak(){
    if(isEmpty())
    {
        cout<< "Don't have Front val. Queue is Empty." <<endl;
        return 0;
    }
    return list1.Gethead()->Getdata();
}

treeNode* queu::dequeue(){
    if(isEmpty())
    {
        cout<< "Don't have Any Value to Delete. Queue is Empty." << endl;
        return 0;
    }
    treeNode* head=peak();
    list1.deleteAtHead();
    return head;
}

void queu::displayFullLinklist(){
    if(isEmpty())
    {
        cout<< "Nothing to Display. Queue is Empty." << endl;
    }
    list1.displayFullLinklist();
}
