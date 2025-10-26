#ifndef LISTANGKA
#define LISTANGKA
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct infotype *address;

struct infotype {
    dataAngka angka;
    address Next;
};

struct List{
    address First;
};

void CreateList(List &L);
address alokasi (infotype x);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(List &L, address nodeBaru, address nodePrev);
int nbList(List L);
void delAfter(List &L, address nodeHapus, address nodePrev);

#endif
