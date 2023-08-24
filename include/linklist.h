#ifndef LINKLIST_H
#define LINKLIST_H
#include"../include/node.h"

class linklist{
    public:
        linklist();
        virtual ~linklist();

        void Sethead(node*);
        node* Gethead();
        void Settail(node*);
        node* Gettail();

        void insertAtTail(treeNode*);
        void displayFullLinklist();
        void deleteAtHead();

    private:
        node* head;
        node* tail;
};

#endif // LINKLIST_H
