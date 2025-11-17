#include "SLLInventory.h"

int main()
{
    List barangSimpanan;
    Product A, B, C;
    createList(barangSimpanan);

    A.Nama = "Pulpen";
    A.SKU = "A001";
    A.Jumlah = 20;
    A.HargaSatuan = 2500;
    A.DiskonPersen = 0;
    insertFirst(barangSimpanan, A);
    B.Nama = " Buku Tulis";
    B.SKU = "A002";
    B.Jumlah = 15;
    B.HargaSatuan = 5000;
    B.DiskonPersen = 10;
    insertFirst(barangSimpanan, B);
    C.Nama = " Penghapus";
    C.SKU = "A003";
    C.Jumlah = 30;
    C.HargaSatuan = 5000;
    C.DiskonPersen = 10;
    insertAfter(barangSimpanan, barangSimpanan.head, C);

    viewList(barangSimpanan);

    cout << "Delete First" << endl;
    Product D;
    deleteFirst(barangSimpanan, D);

    viewList(barangSimpanan);

    cout << "Update data in position" << endl;
    updateAtPosition(barangSimpanan, 2);

    cout << "Search Final Price Range" << endl;
    searchByFinalPriceRange(barangSimpanan, 2000, 7000);

    cout << "Max harga akhir" << endl;
    maxHargaAkhir(barangSimpanan);
    return 0;
}