#include "../include/node.h"

node::node(){
    next=nullptr;
}

void node::Setdata(treeNode* val) { data = val; }
treeNode* node::Getdata() { return data; }

void node::Setnext(node* val) { next = val; }
node* node::Getnext() { return next; }

node::~node(){
    //dtor
}
