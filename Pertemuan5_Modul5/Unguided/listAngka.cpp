#include "listAngka.h"

void CreateList(List &L)
{
    L.First = nullptr;
}

address alokasi(infotype x)
{
    address newNode = new infotype();
    newNode->angka = x.angka;
    newNode->Next = nullptr;
    return newNode;
}

void dealokasi(address &node)
{
    node->Next = nullptr;
    delete node;
}

void printList(List L)
{
    address temp = L.First;
    while (temp != nullptr)
    {
        cout << temp->angka << " - ";
        temp = temp->Next;
    }
    cout <<endl;
}

void insertFirst(List &L, address nodeBaru)
{
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(List &L, address nodeBaru)
{
    address temp = L.First;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
    }

    temp->Next = nodeBaru;
}

void insertAfter(address &nodeBaru, address &nodePrev)
{
    nodeBaru->Next = nodePrev->Next;
    nodePrev->Next = nodeBaru;
}

int nbList(List L)
{
    address temp = L.First;
    int countItem = 0;

    while (temp != nullptr)
    {
        countItem++;
        temp = temp->Next;
    }
    return countItem;
}

void delAfter(address &nodeHapus, address &nodePrev)
{
    nodePrev->Next = nodeHapus->Next;
    dealokasi(nodeHapus);
}

// Soal 1
void updateFirst(List &L)
{
    dataAngka D;
    cout << "Masukan update data node pertama : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    L.First->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};

void updateLast(List &L){
    dataAngka D;
    cout << "Masukan update data node terakhir : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    address last = L.First;
    while (last->Next != nullptr)
    {
        last = last->Next;
    }
    last->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};

void updateAfter(address &nodePrev)
{
    dataAngka D;
    cout << "Masukan update data setelah node " << nodePrev->angka << " : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    nodePrev->Next->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};