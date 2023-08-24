#include "../include/AVL.h"
#include <iostream>
#include <windows.h>
using namespace std;

HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
          AVL :: AVL(){
    Setroot(nullptr);
}
bool      AVL :: isEmpty(){
    if(root==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int       AVL :: height(treeNode * r) {
    if (r == nullptr)
      return -1;
    else
    {
      /* compute the height of each subtree */
      int lheight = height(r ->Getleft());
      int rheight = height(r ->Getright());

      /* use the larger one */
      if (lheight > rheight)
        return (lheight + 1);
      else return (rheight + 1);
    }
}
int       AVL :: getBalanceFactor(treeNode * n){
    if (n == nullptr)
      return -1;
    return height(n ->Getleft()) - height(n ->Getright());
}
treeNode* AVL :: rightRotate(treeNode * y) {
    treeNode * x = y ->Getleft();
    treeNode * T2 = x ->Getright();

    // Perform rotation
    x ->Setright(y);
    y ->Setleft(T2);

    return x;
}
treeNode* AVL :: leftRotate(treeNode* x){
    treeNode * y = x ->Getright();
    treeNode * T2 = y ->Getleft();

    // Perform rotation
    y ->Setleft(x);
    x ->Setright(T2);

    return y;
}
treeNode* AVL :: insertInAVLtreeWithValue(int id,string name, string location){
     treeNode * new_node = new treeNode(id, name, location);
     Setroot(insertInAVLtree(root, new_node));
     cout << endl;
}
treeNode* AVL :: insertInAVLtree(treeNode * r, treeNode * new_node){

    if (r == nullptr)
    {
      r = new_node;
      SetConsoleTextAttribute(h,12);
      cout << "Value inserted successfully";
    }
    else if (new_node->GethotelName() < r ->GethotelName())
    {
        r ->Setleft(insertInAVLtree(r ->Getleft(), new_node));
    }
    else if (new_node ->GethotelName() > r ->GethotelName())
    {
        r ->Setright(insertInAVLtree(r ->Getright(), new_node));
    }
    else
    {
        cout << "No duplicate values allowed!" << endl;
        return r;
    }

    int bf = getBalanceFactor(r);
    // Left Left Case
    if (bf > 1 && new_node ->GethotelName() < r ->Getleft() ->GethotelName())
    {
      return rightRotate(r);
    }

    // Right Right Case
    if (bf < -1 && new_node ->GethotelName() > r ->Getright() ->GethotelName())
    {
      return leftRotate(r);
    }

    // Left Right Case
    if (bf > 1 && new_node ->GethotelName() > r ->Getleft() ->GethotelName())
    {
        r ->Setleft(leftRotate(r ->Getleft()));
        return rightRotate(r);
    }

    // Right Left Case
    if (bf < -1 && new_node ->GethotelName() < r ->Getright() ->GethotelName())
    {
        r ->Setright(rightRotate(r ->Getright()));
        return leftRotate(r);
    }

    /* return the (unchanged) node pointer */
    return r;

  }
void      AVL :: displayINODER(treeNode* Root){
    if(Root==nullptr)
    {
        return;
    }

    displayINODER(Root->Getleft());
    SetConsoleTextAttribute(h,5);
    cout << endl << "ID: "       << Root->Getid()             << "         " << endl;
    SetConsoleTextAttribute(h,1);
    cout         << "NAME: "     << Root->GethotelName()      << "         " << endl;
    SetConsoleTextAttribute(h,8);
    cout         << "LOCATION: " << Root->GethotelLocation()                 << endl;
    SetConsoleTextAttribute(h,7);
    displayINODER(Root->Getright());
}
treeNode* AVL :: displayINORDERByMain(){
    displayINODER(root);
}
treeNode* AVL :: minValueNode(treeNode* node){
    treeNode* current = node;
    // loop down to find the leftmost leaf
    while (current ->Getleft() != nullptr)
    {
        current = current ->Getleft();
    }
    return current;
}
treeNode* AVL :: deleteNode(treeNode* r,string v){
    // base case
    if (r == nullptr) {
      return nullptr;
    }
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    else if (v < r ->GethotelName()) {
      r ->Setleft(deleteNode(r ->Getleft(), v));
    }
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (v > r ->GethotelName()) {
      r ->Setright(deleteNode(r ->Getright(), v));

    }
    // if key is same as root's key, then This is the node to be deleted
    else {
      // node with only one child or no child
      if (r ->Getleft() == nullptr) {
        treeNode * temp = r ->Getright();
        delete r;
        return temp;
      } else if (r ->Getright() == nullptr) {
        treeNode * temp = r ->Getleft();
        delete r;
        return temp;
      } else {
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        treeNode * temp = minValueNode(r ->Getright());
        // Copy the inorder successor's content to this node
        r ->SethotelName(temp ->GethotelName());
        // Delete the inorder successor
        r ->Setright(deleteNode(r ->Getright(), temp ->GethotelName()));
        //deleteNode(r->right, temp->value);
      }
    }

    int bf = getBalanceFactor(r);
    // Left Left Imbalance/Case or Right rotation
    if (bf == 2 && getBalanceFactor(r ->Getleft()) >= 0)
      return rightRotate(r);
    // Left Right Imbalance/Case or LR rotation
    else if (bf == 2 && getBalanceFactor(r ->Getleft()) == -1) {
      r ->Setleft(leftRotate(r ->Getleft()));
      return rightRotate(r);
    }
    // Right Right Imbalance/Case or Left rotation
    else if (bf == -2 && getBalanceFactor(r ->Getright()) <= -0)
      return leftRotate(r);
    // Right Left Imbalance/Case or RL rotation
    else if (bf == -2 && getBalanceFactor(r ->Getright()) == 1) {
      r ->Setright(rightRotate(r ->Getright()));
      return leftRotate(r);
    }
    return r;
}
treeNode* AVL :: deleteNodeBYMAIN(string name){
    root=deleteNode(root,name);
    treeNode* x=Searchwithoutroot(name);
    if(x != nullptr)
    {
        cout << "DELETED." << endl;
    }
    else
    {
        cout << "NOT DELETED." << endl;
    }
    return root;
}
treeNode* AVL :: Search(treeNode* r,string val){
    //cout<< endl<< val<< " " << r->Getid() <<endl;
    if (r == nullptr || r ->GethotelName() == val)
      return r;

    else if (val < r ->GethotelName())
      return Search(r ->Getleft(), val);

    else
      return Search(r ->Getright(), val);
}
treeNode* AVL :: Searchwithoutroot(string val){
    return Search(root, val);
}
string    AVL :: upper_string(string str){
	for(int i=0;str[i]!='\0';i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')   //checking for lowercase characters
			str[i] = str[i] - 32;        //converting lowercase to uppercase
	}
	return str;
}
          AVL :: ~AVL(){
    //dtor
}
