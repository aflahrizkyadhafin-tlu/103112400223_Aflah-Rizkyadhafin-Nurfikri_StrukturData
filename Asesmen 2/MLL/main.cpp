#include "mll.h"

int main()
{
    listParent daftarFilm;
    createListParent(daftarFilm);

    adrParent A, B, C, D;
    A = alokasiNodeParent("G001", "Action");
    B = alokasiNodeParent("G002", "Comedy");
    C = alokasiNodeParent("G003", "Horror");
    D = alokasiNodeParent("G004", "Romance");

    insertFirstParent(daftarFilm, D);
    insertFirstParent(daftarFilm, C);
    insertFirstParent(daftarFilm, B);
    insertFirstParent(daftarFilm, A);

    adrChild a;
    a = alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    insertLastChild(A->firstChild, a);
    a = alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    insertLastChild(B->firstChild, a);
    a = alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    insertLastChild(B->firstChild, a);
    a = alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    insertLastChild(C->firstChild, a);
    a = alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    insertLastChild(D->firstChild, a);
    a = alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    insertLastChild(D->firstChild, a);

    printStrukturMLL(daftarFilm);

    cout << endl
         << "===== Search Film =====" << endl;
    searchFilmByRatingRange(daftarFilm, 8.0, 8.5);

    cout << endl
         << "===== Delete Film =====" << endl;
    deleteAfterParent(daftarFilm, B);
    printStrukturMLL(daftarFilm);
    return 0;
}