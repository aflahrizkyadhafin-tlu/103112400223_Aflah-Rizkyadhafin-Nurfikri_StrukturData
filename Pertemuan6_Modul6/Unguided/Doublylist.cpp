#include "Doublylist.h"

void CreateList(List &L)
{
    L.First = Nil;
    L.Last = Nil;
}

bool isEmpty(List L)
{
    if (L.First == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

address alokasi(kendaraan x)
{
    address newNode = new ElmList;
    newNode->info.nopol = x.nopol;
    newNode->info.thnBuat = x.thnBuat;
    newNode->info.warna = x.warna;
    newNode->next = Nil;
    newNode->prev = Nil;
    return newNode;
}

void dealokasi(address &P)
{
    P->next = Nil;
    P->prev = Nil;
    delete P;
}

void printInfo(List L)
{
    if (isEmpty(L))
    {
        cout << "Tidak ada data pada List 1!!!" << endl;
    }
    else
    {
        address temp = L.First;

        cout << "DATA LIST 1" << endl
             << endl;
        while (temp != Nil)
        {
            cout << "No. Polisi : " << temp->info.nopol << endl;
            cout << "Warna : " << temp->info.warna << endl;
            cout << "Tahun : " << temp->info.thnBuat << endl;
            temp = temp->next;
        }
    }
}

void printInfoAddress(address P)
{
    cout << "No. Polisi : " << P->info.nopol << endl;
    cout << "Warna : " << P->info.warna << endl;
    cout << "Tahun : " << P->info.thnBuat << endl;
    cout << endl;
}

void insertLast(List &L, address P)
{
    if (isEmpty(L))
    {
        L.First = L.Last = P;
    }
    else
    {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

address findElm(List L, string x)
{
    address temp = L.First;

    while (temp != Nil)
    {
        if (temp->info.nopol == x)
        {
            return temp;
        }
        temp = temp->next;
    }

    cout << "Data kendaraan dengan nomor polisi " << x << " tidak ditemukan" << endl;
    return Nil;
}
