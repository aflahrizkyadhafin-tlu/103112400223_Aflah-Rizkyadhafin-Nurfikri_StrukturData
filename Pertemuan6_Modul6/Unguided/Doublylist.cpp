#include "Doublylist.h"
#include <iomanip>

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

        cout << "-------------- DATA LIST ---------------" << endl
             << endl;

        cout << string(40, '-') << endl
             << left
             << setw(15) << "No. Polisi"
             << setw(15) << "Warna"
             << setw(10) << "Tahun"
             << endl
             << string(40, '-') << endl;

        while (temp != Nil)
        {
            cout << left
                 << setw(15) << temp->info.nopol
                 << setw(15) << temp->info.warna
                 << setw(10) << temp->info.thnBuat
                 << endl;
            temp = temp->next;
        }
        cout << string(40, '-') << endl;
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
        if (findElm(L, P->info.nopol) != Nil)
        {
            cout << "Nomor polisi sudah terdaftar" << endl;
        }
        else
        {
            L.Last->next = P;
            P->prev = L.Last;
            L.Last = P;
        }
    }
    cout << endl;
}

// Soal 2
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

    return Nil;
}

// Soal 3
void deleteFirst(List &L, address &P)
{
    if (isEmpty(L))
    {
        cout << "Tidak ada kendaraan yang terdaftar" << endl;
    }
    else
    {
        if (findElm(L, P->info.nopol) == Nil)
        {
            cout << "Nomor polisi tidak terdaftar" << endl;
        }
        else
        {
            L.First->next->prev = Nil;
            L.First = L.First->next;
            dealokasi(P);
        }
    }
}

void deleteLast(List &L, address &P)
{
    if (isEmpty(L))
    {
        cout << "Tidak ada kendaraan yang terdaftar" << endl;
    }
    else
    {
        if (findElm(L, P->info.nopol) == Nil)
        {
            cout << "Nomor polisi tidak terdaftar" << endl;
        }
        else
        {
            L.Last->prev->next = Nil;
            L.Last = L.Last->prev;
            dealokasi(P);
        }
    }
}

void deleteAfter(address &prec, address &P)
{
    P = prec->next;
    prec->next = prec->next->next;
    prec->next->prev = prec;
    dealokasi(P);
}
