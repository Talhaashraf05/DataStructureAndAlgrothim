#ifndef AVL_H
#define AVL_H
#include"../include/treeNode.h"
#include<fstream>
using namespace std;

class AVL{
    public:
        AVL();
        virtual ~AVL();

        treeNode* Getroot() { return root; }
        void Setroot(treeNode* val) { root = val; }

        bool isEmpty();

        int height(treeNode*);

        treeNode* minValueNode(treeNode*);

        int getBalanceFactor(treeNode*);

        treeNode* rightRotate(treeNode*);
        treeNode* leftRotate(treeNode*);

        treeNode* createNode(int,std::string,std::string);
        treeNode* insertInAVLtree(treeNode *, treeNode * );
        treeNode* insertInAVLtreeWithValue(int,std::string,std::string);

        void displayINODER(treeNode*);
        treeNode* displayINORDERByMain();

        treeNode* deleteNode(treeNode*,std::string);
        treeNode* deleteNodeBYMAIN(std::string);

        treeNode* Search(treeNode*,std::string);
        treeNode* Searchwithoutroot(std::string);

        std::string upper_string(std::string);

    private:
        treeNode* root;

};

#endif // AVL_H
