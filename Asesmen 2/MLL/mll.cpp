#include "mll.h"

void createListParent(listParent &L)
{
    L.first = Nil;
    L.last = Nil;
}

void createListChild(listChild &L)
{
    L.first = Nil;
    L.last = Nil;
}

adrParent alokasiNodeParent(string IDGenre, string namaGenre)
{
    adrParent newNode = new Parent;
    newNode->IDGenre = IDGenre;
    newNode->namaGenre = namaGenre;
    newNode->next = Nil;
    newNode->prev = Nil;
    createListChild(newNode->firstChild);
    return newNode;
}

adrChild alokasiNodeChild(string idFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm)
{
    adrChild newNode = new Child;
    newNode->idFilm = idFilm;
    newNode->judulFilm = judulFilm;
    newNode->durasiFilm = durasiFilm;
    newNode->tahunTayang = tahunTayang;
    newNode->ratingFilm = ratingFilm;
    newNode->next = Nil;
    newNode->prev = Nil;
    return newNode;
}

void dealokasiNodeParent(adrParent &N)
{
    N->next = Nil;
    N->prev = Nil;
    delete (N);
}

void dealokasiNodeChild(adrChild &N)
{
    N->next = Nil;
    N->prev = Nil;
    delete (N);
}

void insertFirstParent(listParent &L, adrParent &N)
{
    if (L.first == Nil && L.last == Nil)
    {
        L.first = L.last = N;
    }
    else
    {
        N->next = L.first;
        L.first->prev = N;
        L.first = N;
    }
}

void insertLastChild(listChild &L, adrChild &N)
{
    if (L.first == Nil && L.last == Nil)
    {
        L.first = L.last = N;
    }
    else
    {
        N->prev = L.last;
        L.last->next = N;
        L.last = N;
    }
}

void deleteAfterParent(listParent &L, adrParent &after)
{
    adrParent temp = after->next;
    after->next = after->next->next;
    after->next->prev = after;

    hapusListChild(L, temp);
    dealokasiNodeParent(temp);
}

void hapusListChild(listParent &L, adrParent &N)
{
    adrChild temp = N->firstChild.last;

    while (temp != Nil)
    {
        if (temp == N->firstChild.first)
        {
            N->firstChild.first = N->firstChild.last = Nil;
            break;
        }
        adrChild deleteData = temp;
        temp = temp->prev;
        dealokasiNodeChild(deleteData);
    }
}

void searchFilmByRatingRange(listParent L, float min, float max)
{
    adrParent temp = L.first;
    int countParent = 0;

    while (temp != Nil)
    {
        bool find = false;
        adrChild tempChild = temp->firstChild.first;
        int countChild = 0;
        while (tempChild != Nil)
        {
            if (tempChild->ratingFilm >= min && tempChild->ratingFilm <= max)
            {
                find = true;
                cout << "Data film berhasil ditemukan pada list child dari node parent " << temp->namaGenre << " pada posisi ke-" << countChild << "!" << endl;
                cout << "---- Data Film (Child) ----" << endl
                     << "Judul Film : " << tempChild->judulFilm << endl
                     << "Posisi pada list child : " << countChild << endl
                     << "ID Film : " << tempChild->idFilm << endl
                     << "Durasi Film : " << tempChild->durasiFilm << " menit" << endl
                     << "Tahun Tayang : " << tempChild->tahunTayang << endl
                     << "Rating Film : " << tempChild->ratingFilm << endl;
            }
            countChild++;
            tempChild = tempChild->next;
        }
        if (find)
        {
            cout << "---- Data Genre (Parent) ----" << endl
                 << "ID Genre = " << temp->IDGenre << endl
                 << "Posisi pada list parent = " << countParent << endl
                 << "Nama Genre = " << temp->namaGenre << endl;
        }
        countParent++;
        temp = temp->next;
    }
}

void printStrukturMLL(listParent L)
{
    adrParent temp = L.first;
    int countParent = 1;

    while (temp != Nil)
    {
        adrChild tempChild = temp->firstChild.first;
        int countChild = 1;
        cout << "==== Parent " << countParent << " ====" << endl
             << "ID Genre = " << temp->IDGenre << endl
             << "Nama Genre = " << temp->namaGenre << endl;
        while (tempChild != Nil)
        {
            cout << "  - Child " << countChild << " : " << endl
                 << "      ID Film : " << tempChild->idFilm << endl
                 << "      Judul Film : " << tempChild->judulFilm << endl
                 << "      Durasi Film : " << tempChild->durasiFilm << " menit" << endl
                 << "      Tahun Tayang : " << tempChild->tahunTayang << endl
                 << "      Rating Film : " << tempChild->ratingFilm << endl;
            countChild++;
            tempChild = tempChild->next;
        }
        countParent++;
        temp = temp->next;
    }
}
