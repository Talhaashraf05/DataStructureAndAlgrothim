#ifndef QUEU_H
#define QUEU_H
#include"../include/linklist.h"

class queu{
    public:
        queu();
        virtual ~queu();

        bool isEmpty();
        void enqueue(treeNode*);
        treeNode* dequeue();
        treeNode* peak();
        void displayFullLinklist();

    private:
        linklist list1;
};

#endif // QUEU_H
