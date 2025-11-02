#include "Doublylist.h"

kendaraan dataKendaraan()
{
    kendaraan dataKendaraan;

    cout << "Masukan nomor polisi : ";
    cin >> dataKendaraan.nopol;
    cout << "Masukan warna kendaraan : ";
    cin >> dataKendaraan.warna;
    cout << "Masukan tahun kendaraan : ";
    cin >> dataKendaraan.thnBuat;
    return dataKendaraan;
}

int main()
{
    List listKendaraan;
    address nodeA, nodeB, nodeC, nodeD;
    CreateList(listKendaraan);

    nodeA = alokasi(dataKendaraan());
    insertLast(listKendaraan, nodeA);
    nodeB = alokasi(dataKendaraan());
    insertLast(listKendaraan, nodeB);
    nodeC = alokasi(dataKendaraan());
    insertLast(listKendaraan, nodeC);
    nodeD = alokasi(dataKendaraan());
    insertLast(listKendaraan, nodeD);

    printInfo(listKendaraan);
    cout << endl;

    cout << "======= Search Node by Nomor Polisi =======" << endl;
    string nomorKendaraan;
    cout << "Masukan nomor yang dicari : ";
    cin >> nomorKendaraan;
    address find = findElm(listKendaraan, nomorKendaraan);
    cout
        << endl;
    if (find == Nil)
    {
        cout << "Data kendaraan dengan nomor polisi " << nomorKendaraan << " tidak ditemukan" << endl;
    }
    else
    {
        printInfoAddress(find);
    };

    cout << "======= Delete Node =======" << endl
         << "Nomor polisi : D003" << endl
         << endl;
    address P;

    find = findElm(listKendaraan, "D003");
    if (find == listKendaraan.First)
    {
        deleteFirst(listKendaraan, P);
    }
    else if (find == listKendaraan.Last)
    {
        deleteLast(listKendaraan, P);
    }
    else
    {
        deleteAfter(find->prev, P);
    }
    printInfo(listKendaraan);
    return 0;
}