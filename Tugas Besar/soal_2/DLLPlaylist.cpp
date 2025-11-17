#include "DLLPlaylist.h"

bool isEmpty(List L)
{
    if (L.head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void createList(List &L)
{
    L.head = L.tail = nullptr;
};

address allocate(Song S)
{
    address newElm = new Node();
    newElm->info.Artist = S.Artist;
    newElm->info.DurationSec = S.DurationSec;
    newElm->info.PlayCount = S.PlayCount;
    newElm->info.Rating = S.Rating;
    newElm->info.Title = S.Title;
    newElm->next = newElm->prev = nullptr;
    return newElm;
};

void deallocate(address P)
{
    P->next = P->prev = nullptr;
    delete P;
};

void insertFirst(List &L, Song S)
{
    address newNode = allocate(S);
    if (L.head == nullptr)
    {
        L.head = L.tail = newNode;
    }
    else
    {
        L.head->prev = newNode;
        newNode->next = L.head;
        L.head = newNode;
    }
};

void insertLast(List &L, Song S)
{
    address newNode = allocate(S);
    if (L.head == nullptr)
    {
        L.head = L.tail = newNode;
    }
    else
    {
        L.tail->next = newNode;
        newNode->prev = L.head;
        L.tail = newNode;
    }
};

void insertAfter(List &L, address &Q, Song S)
{
    address newNode = allocate(S);
    Q->next->prev = newNode;
    newNode->next = Q->next;
    newNode->prev = Q;
    Q->next = newNode;
};

void insertBefore(List &L, address &Q, Song S)
{
    address newNode = allocate(S);
    Q->prev->next = newNode;
    newNode->prev = Q->next;
    newNode->next = Q;
    Q->prev = newNode;
};

void deleteFirst(List &L, Song S);
void deleteLast(List &L, Song S);
void deleteAfter(List &L, address &Q, Song S);
void updateAtPosition(List &L, int posisi);
void viewList(List L)
{
    address temp = L.head;
    int posisi = 1;
    while (temp != nullptr)
    {
        cout << "indeks : " << posisi << endl
             << "Artist : " << temp->info.Artist << endl
             << "Title : " << temp->info.Title << endl
             << "Duration (sec) : " << temp->info.DurationSec << endl
             << "Playcount : " << temp->info.PlayCount << endl
             << "Rating : " << temp->info.Rating << endl
             << endl;
        posisi++;
        temp = temp->next;
    }
    cout << endl;
};
void searchByPopularityRange(List L, float minPrice, float maxPrice);
