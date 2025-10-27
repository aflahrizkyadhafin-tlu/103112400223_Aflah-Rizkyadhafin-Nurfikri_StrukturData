#ifndef KENDARAAN_H
#define KENDARAAN_H
#define Nil NULL
#include <iostream>
using namespace std;

struct kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList
{
    kendaraan info;
    address next;
    address prev;
};

struct List
{
    address First;
    address Last;
};

void CreateList(List &L);
bool isEmpty(List L);
address alokasi(kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void printInfoAddress(address P);
void insertLast(List &L, address P);

// Soal 2
address findElm(List L, string x);
#endif