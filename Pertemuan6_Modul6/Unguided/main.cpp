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
    cout << endl;
    return dataKendaraan;
}

int main()
{
    List listKendaraan;
    address nodeA, nodeB, nodeC, nodeD;
    CreateList(listKendaraan);

    nodeA = alokasi(dataKendaraan());
    nodeB = alokasi(dataKendaraan());
    nodeC = alokasi(dataKendaraan());
    nodeD = alokasi(dataKendaraan());

    insertLast(listKendaraan, nodeA);
    insertLast(listKendaraan, nodeB);
    insertLast(listKendaraan, nodeC);
    insertLast(listKendaraan, nodeD);

    printInfo(listKendaraan);
    cout << endl;

    string nomorKendaraan;
    cout << "Masukan nomor yang dicari : ";
    cin >> nomorKendaraan;
    cout << endl;
    printInfoAddress(findElm(listKendaraan, nomorKendaraan));
    return 0;
}