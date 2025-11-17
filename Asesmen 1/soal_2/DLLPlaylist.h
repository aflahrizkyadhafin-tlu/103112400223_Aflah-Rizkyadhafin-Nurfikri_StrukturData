#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H
#define Nil NULL
#include <iostream>
using namespace std;

struct Song
{
    string Title, Artist;
    int DurationSec, PlayCount;
    float Rating;
};

typedef struct Node *address;

struct Node
{
    Song info;
    address next, prev;
};

struct List
{
    address head, tail;
};

bool isEmpty(List L);
void createList(List &L);
address allocate(Song S);
void deallocate(address P);
void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, address &Q, Song S);
void insertBefore(List &L, address &Q, Song S);
void deleteFirst(List &L, Song S);
void deleteLast(List &L, Song S);
void deleteAfter(List &L, address &Q, Song S);
void deleteBefore(List &L, address &Q, Song S);
void updateAtPosition(List &L, int posisi);
void updateBefore(List &L, address &Q);
void viewList(List L);
void searchByPopularityRange(List L, float minPrice, float maxPrice);

#endif