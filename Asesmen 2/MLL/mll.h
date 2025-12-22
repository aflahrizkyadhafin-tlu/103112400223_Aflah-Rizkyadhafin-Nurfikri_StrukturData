#ifndef FILM_H
#define FILM_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef struct Parent *adrParent;
typedef struct Child *adrChild;

struct listParent
{
    adrParent first, last;
};

struct listChild
{
    adrChild first, last;
};

struct Parent
{
    string IDGenre, namaGenre;
    adrParent next, prev;
    listChild firstChild;
};

struct Child
{
    string idFilm, judulFilm;
    int durasiFilm, tahunTayang;
    float ratingFilm;
    adrChild next, prev;
};

void createListParent(listParent &L);
void createListChild(listChild &L);
adrParent alokasiNodeParent(string IDGenre, string namaGenre);
adrChild alokasiNodeChild(string idFilm, string judulFilm, int durasiFilm, int tahunTayang, float ratingFilm);
void dealokasiNodeParent(adrParent &N);
void dealokasiNodeChild(adrChild &N);
void insertFirstParent(listParent &L, adrParent &N);
void insertLastChild(listChild &L, adrChild &N);
void deleteAfterParent(listParent &L, adrParent &after);
void hapusListChild(listParent &L, adrParent &N);
void searchFilmByRatingRange(listParent L, float min, float max);
void printStrukturMLL(listParent L);

#endif