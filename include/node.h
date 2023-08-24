#ifndef NODE_H
#define NODE_H
#include"../include/treeNode.h"

class node{
    public:
        node();
        virtual ~node();

        void Setdata(treeNode*);
        treeNode* Getdata();
        void Setnext(node*);
        node* Getnext();


    protected:

    private:
        treeNode* data;
        node* next;

};

#endif // NODE_H
