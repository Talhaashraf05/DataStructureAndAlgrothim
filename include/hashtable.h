#ifndef HASHTABLE_H
#define HASHTABLE_H
#include<string>
#include "../include/AVL.h"
#include"../include/treeNode.h"
#include"../include/queu.h"

class hashtable{
    public:
        hashtable();
        hashtable(int);
        virtual ~hashtable();

        int hashing(std::string);

        AVL* insertInHash(int, std::string, std::string);

        void searchinHash(std::string);

        void deleteInHash(std::string);

        void displayByHash();

        void writeInFileByHAsh(std::string);
        void readFromFileByHAsh(std::string);


        int Getsize() { return size; }
        void Setsize(int val) { size = val; }
        AVL* Getarr() { return arr; }
        void Setarr(AVL* val) { arr = val; }

    private:
        treeNode objtree;
        AVL* arr;
        int size;
};

#endif // HASHTABLE_H
