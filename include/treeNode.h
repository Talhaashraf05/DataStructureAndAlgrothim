#ifndef TREENODE_H
#define TREENODE_H
#include<string>

class treeNode{
    public:
        treeNode();
        treeNode(int,std::string, std::string);
        virtual ~treeNode();

        int Getid() { return id; }
        void Setid(int val) { id = val; }
        treeNode* Getleft() { return left; }
        void Setleft(treeNode* val) { left = val; }
        treeNode* Getright() { return right; }
        void Setright(treeNode* val) { right = val; }
        std::string GethotelName() { return hotelName; }
        void SethotelName(std::string name) { hotelName = name; }
        std::string GethotelLocation() { return hoteLocation; }
        void SethotelLocation(std::string location) { hoteLocation = location; }

    private:
        int id;
        std::string hotelName;
        std::string hoteLocation;
        treeNode* left;
        treeNode* right;
};

#endif // TREENODE_H
