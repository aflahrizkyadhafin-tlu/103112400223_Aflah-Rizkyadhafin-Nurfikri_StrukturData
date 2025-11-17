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

void deleteFirst(List &L, Song S)
{
    if (L.head != nullptr)
    {
        address temp = L.head;
        S = L.head->info;
        L.head->next->prev = nullptr;
        L.head = L.head->next;
        deallocate(temp);
    }
};

void deleteLast(List &L, Song S)
{
    if (L.tail != nullptr)
    {
        address temp = L.tail;
        S = L.tail->info;
        L.tail->prev->next = nullptr;
        L.tail = L.tail->prev;
        deallocate(temp);
    }
};

void deleteAfter(List &L, address &Q, Song S)
{
    address temp = Q->next;
    S = Q->next->info;
    Q->next->next->prev = Q;
    Q->next = Q->next->next;
    deallocate(temp);
};

void deleteBefore(List &L, address &Q, Song S)
{
    address temp = Q->next;
    S = Q->prev->info;
    Q->prev->prev->next = Q;
    Q->prev = Q->prev->prev;
    deallocate(temp);
};

void updateAtPosition(List &L, int posisi)
{
    address temp = L.head;
    int position = 1;

    while (temp != nullptr && position != posisi)
    {
        cout << (temp != nullptr && position != posisi) << endl;
        temp = temp->next;
        position++;
    }

    cout << "Title : ";
    cin >> temp->info.Title;
    cout << "Artist : ";
    cin >> temp->info.Artist;
    cout << "Duration (sec) : ";
    cin >> temp->info.DurationSec;
    cout << "Playcount : ";
    cin >> temp->info.PlayCount;
    cout << "Rating : ";
    cin >> temp->info.Rating;
    cout << endl;
};

void updateBefore(List &L, int posisi)
{
    address temp = L.head;
    int position = 1;

    while (temp != nullptr && position != posisi - 1)
    {
        cout << (temp != nullptr && position != posisi) << endl;
        temp = temp->next;
        position++;
    }

    cout << "Title : ";
    cin >> temp->info.Title;
    cout << "Artist : ";
    cin >> temp->info.Artist;
    cout << "Duration (sec) : ";
    cin >> temp->info.DurationSec;
    cout << "Playcount : ";
    cin >> temp->info.PlayCount;
    cout << "Rating : ";
    cin >> temp->info.Rating;
    cout << endl;
};

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

void searchByPopularityRange(List L, float minScore, float maxScore)
{
    address temp = L.head;
    int posisi = 1;
    float popularityScore;
    while (temp != nullptr)
    {
        popularityScore = 0.8 * temp->info.PlayCount + 20 * temp->info.Rating;
        if (popularityScore >= minScore && popularityScore <= maxScore)
        {
            cout << "indeks : " << posisi << endl
                 << "Artist : " << temp->info.Artist << endl
                 << "Title : " << temp->info.Title << endl
                 << "Duration (sec) : " << temp->info.DurationSec << endl
                 << "Playcount : " << temp->info.PlayCount << endl
                 << "Rating : " << temp->info.Rating << endl
                 << endl;
        }

        posisi++;
        temp = temp->next;
    }
    cout << endl;
};
