#include "../include/treeNode.h"
#include<string>
using namespace std;
treeNode::treeNode(){
    SethotelName("");
    SethotelLocation("");
    Setid(0);
    Setleft(nullptr);
    Setright(nullptr);
}

treeNode::treeNode(int id, string name, string location){
    SethotelName(name);
    SethotelLocation(location);
    Setid(id);
    Setleft(nullptr);
    Setright(nullptr);
}

treeNode::~treeNode(){
    //dtor
}
