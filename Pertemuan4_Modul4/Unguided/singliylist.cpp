#include "singliylist.h"

// Latihan 1
void createList(List &L)
{
    L.first = Nil;
}

address alokasi(infotype x)
{
    address newElm = new ElmList();
    newElm->info = x;
    newElm->next = Nil;
    return newElm;
}

void dealokasi(address &P)
{
    P->next = Nil;
    delete P;
}

void printInfo(List L)
{
    address temp = L.first;
    while (temp != Nil)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

void insertFirst(List &L, address P)
{
    P->next = L.first;
    L.first = P;
}

// Latihan 2
void nbList(List L)
{
    int nodeLength = 0;
    address temp = L.first;
    while (temp != Nil)
    {
        cout << temp->info << " ";
        nodeLength++;
        temp = temp->next;
    }
    cout << endl
         << "Jumlah node : " << nodeLength << endl
         << endl;
}

void deleteFirst(List &L)
{
    address P = L.first;
    L.first = P->next;
    dealokasi(P);
}

void deleteAfter(address &P)
{
    address temp = P->next;
    P->next = P->next->next;
    dealokasi(temp);
}

void deleteLast(List &L)
{
    address P = L.first, prev = Nil;
    while (P->next != Nil)
    {
        prev = P;
        P = P->next;
    }
    prev->next = Nil;
    dealokasi(P);
}

void deleteList(List &L)
{
    address temp = L.first, P;
    while (temp != Nil)
    {
        P = temp;
        temp = temp->next;
        dealokasi(P);
    }
    L.first = Nil;
    cout << "- List Berhasil Terhapus -";
}
