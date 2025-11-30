#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;
struct Node
{
    infotype info;
    address left, right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInOrder(address root);

#endif