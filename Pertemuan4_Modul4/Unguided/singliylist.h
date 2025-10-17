#ifndef SINGLIYLIST_H
#define SINGLIYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
};

struct List
{
    address first;
};

// Latihan 1
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// Latihan 2
void nbList(List L);
void deleteFirst(List &L);
void deleteAfter(address &P);
void deleteLast(List &L);
void deleteList(List &L);
#endif