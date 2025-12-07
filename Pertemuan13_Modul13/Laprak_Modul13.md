# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

Multi linked list merupakan pengembangan dari struktur linked list konvensional yang memungkinkan setiap node memiliki multiple pointer untuk terhubung dengan node-node lainnya. Hal ini memfasilitasi pembentukan relasi data yang lebih kompleks, seperti hubungan one-to-many maupun many-to-many. Struktur semacam ini umumnya diterapkan untuk merepresentasikan data bersifat hierarkis atau memiliki keterkaitan ganda, contohnya pada relasi antara dosen pembimbing dengan sejumlah mahasiswa bimbingannya, di mana pointer berfungsi menghubungkan elemen induk dengan kumpulan elemen turunannya tanpa menyebabkan redundansi alokasi memori [1]. Multi linked list terbukti sangat efisien dalam menangani keterbatasan memori utama pada sistem yang memerlukan pengelolaan data dinamis dengan ukuran yang fluktuatif [1].

Dari segi implementasi, multi linked list dapat dipahami sebagai sebuah list utama yang masing-masing elemennya dilengkapi pointer tambahan untuk merujuk ke list lain (sub-list). Sebagai ilustrasi, dalam struktur data yang menghubungkan pegawai dengan anak-anaknya, node pegawai akan memiliki pointer Next yang mengarah ke pegawai selanjutnya serta pointer Child yang mengarah ke node anak pertama, yang selanjutnya tersambung secara linear dengan anak-anak berikutnya [2]. Fleksibilitas seperti ini menjadikan multi linked list sebagai solusi yang tepat guna untuk menangani database yang tidak ternormalisasi ataupun sparse matrix, karena data dapat didistribusikan dan diakses melalui beragam jalur pointer tanpa mengharuskan penempatan di blok memori yang berkesinambungan sebagaimana pada array [1].

### A. Multi Linked List<br/>

#### 1. Menggunakan multi linked list dengan node tipe SLL

#### 2. Menggunakan multi linked list dengan node tipe DLL

## Guided

### 1. MLL

#### mll.h

```h
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan
{
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan
{
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild
{
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak
{
    NodeChild first;
    NodeChild last;
};

struct nodeParent
{
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk
{
    NodeParent first;
    NodeParent last;
};

// isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

// alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

// operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);
void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);
void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

// operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

// operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

// operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif

```

#### mll.cpp

```C++
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

// isEmpty & create list
bool isEmptyInduk(listInduk LInduk)
{
    if (LInduk.first == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak)
{
    if (LAnak.first == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListInduk(listInduk &LInduk)
{
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak)
{
    LAnak.first = LAnak.last = NULL;
}

// alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori)
{
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga)
{
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak)
{
    if (nodeAnak != NULL)
    {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk)
{
    if (nodeInduk != NULL)
    {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

// operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent)
{
    if (isEmptyInduk(LInduk) == true)
    {
        LInduk.first = LInduk.last = nodeBaruParent;
    }
    else
    {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent " << nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent)
{
    if (isEmptyInduk(LInduk) == true)
    {
        LInduk.first = LInduk.last = nodeBaruParent;
    }
    else
    {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent " << nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent)
{
    if (nodePrevParent == NULL)
    {
        cout << "Node Prev Parent tidak valid!" << endl;
    }
    else
    {
        if (nodePrevParent == LInduk.last)
        {
            insertLastParent(LInduk, nodeBaruParent);
            return;
        }
        else
        {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent " << nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent " << nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List Induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last)
        { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        }
        else
        {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if (nodeHapus->L_Anak.first != NULL)
        {
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List Induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last)
        {
            LInduk.first = NULL;
            LInduk.last = NULL;
        }
        else
        {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if (nodeHapus->L_Anak.first != NULL)
        {
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        if (nodePrev != NULL && nodePrev->next != NULL)
        {
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL)
            {
                (nodeHapus->next)->prev = nodePrev;
            }
            else
            {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if (nodeHapus->L_Anak.first != NULL)
            {
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        }
        else
        {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while (nodeBantu != NULL)
        {
            if (nodeBantu->isidata.idKategori == IDCari)
            {
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            }
            else
            {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if (!ketemu)
        {
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List Induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL)
        {
            if (nodeBantu->isidata.idKategori == IDCari)
            {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break;
            }
            else
            {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu)
        {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

// operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild)
{
    if (isEmptyAnak(LAnak))
    {
        LAnak.first = LAnak.last = nodeBaruChild;
    }
    else
    {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child " << nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild)
{
    if (isEmptyAnak(LAnak))
    {
        LAnak.first = LAnak.last = nodeBaruChild;
    }
    else
    {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child " << nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild)
{
    if (nodePrevChild == NULL)
    {
        cout << "Node Prev Parent tidak valid!" << endl;
    }
    else
    {
        if (nodePrevChild == LAnak.last)
        {
            insertLastChild(LAnak, nodeBaruChild);
            return;
        }
        else
        {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child " << nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child " << nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak)
{
    if (isEmptyAnak(LAnak) == true)
    {
        cout << "List anak kosong!" << endl;
    }
    else
    {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last)
        { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        }
        else
        {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak)
{
    if (isEmptyAnak(LAnak) == true)
    {
        cout << "List anak kosong!" << endl;
    }
    else
    {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last)
        {
            LAnak.first = NULL;
            LAnak.last = NULL;
        }
        else
        {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev)
{
    if (isEmptyAnak(LAnak) == true)
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        if (nodePrev != NULL && nodePrev->next != NULL)
        {
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL)
            {
                (nodeHapus->next)->prev = nodePrev;
            }
            else
            {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        }
        else
        {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while (nodeBantuParent != NULL)
        {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while (nodeBantuChild != NULL)
            {
                if (nodeBantuChild->isidata.idMakanan == IDCari)
                {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                }
                else
                {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if (ketemu)
            {
                break;
            }
            else
            {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if (!ketemu)
        {
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga)
{
    if (isEmptyInduk(LInduk) == true)
    {
        cout << "List Induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL)
        {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL)
            {
                if (nodeBantuChild->isidata.idMakanan == IDCari)
                {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                }
                else
                {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu)
            {
                break; // Break loop parent jika sudah ketemu di dalam
            }
            else
            {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu)
        {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

// operasi print
void printStrukturMLL(listInduk &LInduk)
{
    if (isEmptyInduk(LInduk))
    {
        cout << "List induk kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while (nodeBantuParent != NULL)
        {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            // print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if (nodeBantuChild == NULL)
            {
                cout << "  (tidak ada child)" << endl;
            }
            else
            {
                int indexChild = 1;
                while (nodeBantuChild != NULL)
                {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk)
{
    if (isEmptyInduk(LInduk))
    {
        cout << "List induk Kosong!" << endl;
    }
    else
    {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while (nodeBantuParent != NULL)
        {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk)
{
    if (isEmptyInduk(LInduk) == true || nodeInduk == NULL)
    {
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    }
    else
    {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if (nodeBantuChild == NULL)
        {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        }
        else
        {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while (nodeBantuChild != NULL)
            {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

// operasi hapus list
void hapusListInduk(listInduk &LInduk)
{
    NodeParent nodeBantu = LInduk.first;
    while (nodeBantu != NULL)
    {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        // panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak)
{
    NodeChild nodeBantu = LAnak.first;
    while (nodeBantu != NULL)
    {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}
```

#### main.cpp

```C++
#include "mll.h"
#include <iostream>

using namespace std;

int main()
{
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl
         << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);

    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu

    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);

    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01"); // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99"); // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;

    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;

    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;

    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak);

    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L);

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```

Program ini adalah implementasi lengkap dari Multi Linked List dalam C++ yang menggunakan Node dengan tipe Single Linked List.

## Unguided

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
```h
Type Struct golonganHewan <
idGolongan : String
namaGolongan : String
>
Type Struct dataHewan <
idHewan : String
namaHewan : String
habitat : String
ekor : Boolean //TRUE jika berekor, FALSE jika tidak berekor
bobot : float //dalam kg
>
typedef struct nodeParent *NodeParent; //alias pointer ke struct
nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct
nodeChild
Type Struct nodeChild <
isidata : dataHewan
next : NodeChild
prev : NodeChild
>
Type Struct listChild <
first : NodeChild
last : NodeChild
>
Type Struct nodeParent <
isidata : golonganHewan
next : NodeParent
prev : NodeParent
L_Child : listChild
>
Type Struct listParent <
first : NodeParent
last : NodeParent
>
Function isEmptyParent(input/output LParent : listParent) : Boolean
Function isEmptyChild(input/output LChild : listChild) : Boolean
Procedure createListParent(input/output LParent : listParent)
Procedure createListChild(input/output LChild : listChild)
Function allocNodeParent(input idGol : String, namaGol : String) : NodeParent
Function allocNodeChild(input idHwn : String, namaHwn : String, habitat :
String, tail : Boolean, weight : float) : NodeChild
Procedure deallocNodeParent(input/output NParent : NodeParent)
Procedure deallocNodeChild(input/output NChild : NodeChild)
Procedure insertFirstParent(input/output LParent : listParent, newNParent :
NodeParent)
Procedure insertLastParent(input/output LParent : listParent, newNParent :
NodeParent)
Procedure deleteFirstParent(input/output LParent : listParent)
Procedure deleteAfterParent(input/output LParent : listParent, NPrev :
NodeParent)
Procedure insertFirstChild(input/output LChild : listChild, newNChild :
NodeChild)
Procedure insertLastChild(input/output LChild : listChild, newNChild :
NodeChild)
Procedure deleteFirstChild(input/output LChild : listChild)
Procedure deleteAfterChild(input/output LChild : listChild, NPrev : NodeChild)
Procedure printMLLStructure(input/output LParent : listParent)
Procedure deleteListChild(input/output LChild : listChild)
```

#### MultiLL.h

```h
#ifndef MULTILL_H
#define MULTILL_H
#define Nil NULL
#include <iostream>
using namespace std;

struct golonganHewan
{
    string idGolongan, namaGolongan;
};

struct dataHewan
{
    string idHewan, namaHewan, habitat;
    bool ekor;
    float bobot;
};

typedef struct NodeParent *adrParent;
typedef struct NodeChild *adrChild;

struct NodeChild
{
    dataHewan isidata;
    adrChild next, prev;
};

struct listChild
{
    adrChild first, last;
};

struct NodeParent
{
    golonganHewan isiData;
    adrParent next, prev;
    listChild L_Child;
};

struct listParent
{
    adrParent first, last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocnodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(adrParent &NParent);
void deallocNodeChild(adrChild &NChild);
void insertFirstParent(listParent &LParent, adrParent NodeParent);
void insertLastParent(listParent &LParent, adrParent NodeParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, adrParent NPrev);
void insertFirstChild(listChild &LChild, adrChild NodeChild);
void insertLastChild(listChild &LChild, adrChild NodeChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, adrChild NPrev);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);
#endif
```

#### MultiLL.cpp

```C++
#include "MultiLL.h"

bool isEmptyParent(listParent &LParent)
{
    if (LParent.first == Nil && LParent.last == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyChild(listChild &LChild)
{
    if (LChild.first == Nil && LChild.last == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListParent(listParent &LParent)
{
    LParent.first = LParent.last = Nil;
}

void createListChild(listChild &LChild)
{
    LChild.first = LChild.last = Nil;
}

adrParent allocNodeParent(string idGol, string namaGol)
{
    adrParent newElm = new NodeParent;
    newElm->next = Nil;
    newElm->prev = Nil;
    newElm->L_Child = listChild();
    newElm->isiData.idGolongan = idGol;
    newElm->isiData.namaGolongan = namaGol;
    return newElm;
}

adrChild allocnodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight)
{
    adrChild newElm = new NodeChild;
    newElm->next = Nil;
    newElm->prev = Nil;
    newElm->isidata.idHewan = idHwn;
    newElm->isidata.namaHewan = namaHwn;
    newElm->isidata.habitat = habitat;
    newElm->isidata.ekor = tail;
    newElm->isidata.bobot = weight;
    return newElm;
}

void deallocNodeParent(adrParent &NParent)
{
    if (NParent != Nil)
    {
        NParent->next = NParent->prev = Nil;
        delete NParent;
        NParent = Nil;
    }
}

void deallocNodeChild(adrChild &NChild)
{
    if (NChild != Nil)
    {
        NChild->next = NChild->prev = Nil;
        delete NChild;
        NChild = Nil;
    }
}

void insertFirstParent(listParent &LParent, adrParent NodeParent)
{
    if (isEmptyParent(LParent))
    {
        LParent.first = LParent.last = NodeParent;
    }
    else
    {
        NodeParent->next = LParent.first;
        LParent.first->prev = NodeParent;
        LParent.first = NodeParent;
    }
}

void insertLastParent(listParent &LParent, adrParent NodeParent)
{
    if (isEmptyParent(LParent))
    {
        LParent.first = LParent.last = NodeParent;
    }
    else
    {
        NodeParent->prev = LParent.last;
        LParent.last->next = NodeParent;
        LParent.last = NodeParent;
    }
}

void deleteFirstParent(listParent &LParent)
{
    adrParent temp = LParent.first;
    if (!isEmptyParent(LParent))
    {
        LParent.first = LParent.first->next;
        LParent.first->prev = Nil;
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, adrParent NPrev)
{
    adrParent temp = NPrev->next;
    if (temp != Nil)
    {
        if (NPrev->next->next != Nil)
        {
            NPrev->next = NPrev->next->next;
            NPrev->next->prev = NPrev;
        }
        else
        {
            NPrev->next = Nil;
        }
        delete temp;
    }
}

void insertFirstChild(listChild &LChild, adrChild NodeChild)
{
    if (LChild.first == Nil)
    {
        LChild.first = LChild.last = NodeChild;
    }
    else
    {
        NodeChild->prev = LChild.last;
        LChild.last->next = NodeChild;
        LChild.last = NodeChild;
    }
}

void insertLastChild(listChild &LChild, adrChild NodeChild)
{
    if (LChild.last == Nil)
    {
        LChild.first = LChild.last = NodeChild;
    }
    else
    {
        NodeChild->prev = LChild.last;
        LChild.last->next = NodeChild;
        LChild.last = NodeChild;
    }
}

void deleteFirstChild(listChild &LChild)
{
    adrChild temp = LChild.first;
    if (LChild.first != Nil)
    {
        LChild.first = LChild.first->next;
        LChild.first->prev = Nil;
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, adrChild NPrev)
{
    adrChild temp = NPrev->next;
    if (temp->next == Nil)
    {
        NPrev->next = NPrev->next->next;
        NPrev->next->next->prev = NPrev;
        delete temp;
    }
}

void printMLLStructure(listParent &LParent)
{
    adrParent tempParent = LParent.first;
    int posP = 1;

    while (tempParent != Nil)
    {
        adrChild tempChild = tempParent->L_Child.first;
        int posC = 1;
        cout << "=== Parent " << posP << " ===" << endl
             << "ID Golongan : " << tempParent->isiData.idGolongan << endl
             << "Nama Golongan : " << tempParent->isiData.namaGolongan << endl;
        while (tempChild != Nil)
        {
            cout << "  - Child " << posC << endl
                 << "      ID Hewan : " << tempChild->isidata.idHewan << endl
                 << "      Nama Hewan : " << tempChild->isidata.namaHewan << endl
                 << "      Habitat : " << tempChild->isidata.habitat << endl
                 << "      Ekor : " << tempChild->isidata.ekor << endl
                 << "      Bobot : " << tempChild->isidata.bobot << endl;
            posC++;
            tempChild = tempChild->next;
        }
        if (tempParent->L_Child.first == Nil)
        {
            cout << "(Tidak ada child)" << endl;
        }
        cout << "-----------------------------------" << endl;
        posP++;
        tempParent = tempParent->next;
    }
}

void deleteListChild(listChild &LChild)
{
    adrChild temp = LChild.first;
    while (temp != Nil)
    {
        if (temp->next != Nil)
        {
            LChild.first = LChild.first->next;
        }
        else
        {
            LChild.first = LChild.last = Nil;
        }
        deallocNodeChild(temp);
        temp = LChild.first;
    }
}
```

#### main.cpp

```C++
#include "MultiLL.h"

int main()
{
    listParent kelompokHewan;
    createListParent(kelompokHewan);

    adrParent A, B, C, D, E;
    A = allocNodeParent("G001", "Aves");
    B = allocNodeParent("G002", "Mamalia");
    C = allocNodeParent("G003", "Pisces");
    D = allocNodeParent("G004", "Amfibi");
    E = allocNodeParent("G005", "Reptil");
    insertFirstParent(kelompokHewan, C);
    insertFirstParent(kelompokHewan, B);
    insertFirstParent(kelompokHewan, A);
    insertLastParent(kelompokHewan, D);
    insertLastParent(kelompokHewan, E);

    adrChild newChild;
    createListChild(A->L_Child);
    createListChild(B->L_Child);
    createListChild(D->L_Child);

    // Input Child G001
    newChild = allocnodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(A->L_Child, newChild);
    newChild = allocnodeChild("AV002", "Bebek", "Air", true, 2);
    insertFirstChild(A->L_Child, newChild);

    // Input Child G002
    newChild = allocnodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(B->L_Child, newChild);
    newChild = allocnodeChild("M003", "Gorilla", "Hutan", false, 160);
    insertFirstChild(B->L_Child, newChild);
    newChild = allocnodeChild("M002", "Kucing", "Darat", true, 4);
    insertFirstChild(B->L_Child, newChild);

    // Input Child G004
    newChild = allocnodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(D->L_Child, newChild);

    printMLLStructure(kelompokHewan);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan13_Modul13/Unguided/screenshot/soal_1.png)

Kode ini merupakan kode untuk menyimpan node dengan menggunakan MLL. Pada bagian ini program sudah bisa membuat list kosong, menambahkan data parent baru, menambahkan data child serta menghapus data parent/child.

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp. Ekspektasi output :

#### MultiLL.h

```h
#ifndef MULTILL_H
#define MULTILL_H
#define Nil NULL
#include <iostream>
using namespace std;

struct golonganHewan
{
    string idGolongan, namaGolongan;
};

struct dataHewan
{
    string idHewan, namaHewan, habitat;
    bool ekor;
    float bobot;
};

typedef struct NodeParent *adrParent;
typedef struct NodeChild *adrChild;

struct NodeChild
{
    dataHewan isidata;
    adrChild next, prev;
};

struct listChild
{
    adrChild first, last;
};

struct NodeParent
{
    golonganHewan isiData;
    adrParent next, prev;
    listChild L_Child;
};

struct listParent
{
    adrParent first, last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocnodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(adrParent &NParent);
void deallocNodeChild(adrChild &NChild);
void insertFirstParent(listParent &LParent, adrParent NodeParent);
void insertLastParent(listParent &LParent, adrParent NodeParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, adrParent NPrev);
void insertFirstChild(listChild &LChild, adrChild NodeChild);
void insertLastChild(listChild &LChild, adrChild NodeChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, adrChild NPrev);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

void searchHewanByEkor(listParent &LParent, bool tail);
#endif
```

#### MultiLL.cpp

```C++
#include "MultiLL.h"

bool isEmptyParent(listParent &LParent)
{
    if (LParent.first == Nil && LParent.last == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyChild(listChild &LChild)
{
    if (LChild.first == Nil && LChild.last == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListParent(listParent &LParent)
{
    LParent.first = LParent.last = Nil;
}

void createListChild(listChild &LChild)
{
    LChild.first = LChild.last = Nil;
}

adrParent allocNodeParent(string idGol, string namaGol)
{
    adrParent newElm = new NodeParent;
    newElm->next = Nil;
    newElm->prev = Nil;
    newElm->L_Child = listChild();
    newElm->isiData.idGolongan = idGol;
    newElm->isiData.namaGolongan = namaGol;
    return newElm;
}

adrChild allocnodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight)
{
    adrChild newElm = new NodeChild;
    newElm->next = Nil;
    newElm->prev = Nil;
    newElm->isidata.idHewan = idHwn;
    newElm->isidata.namaHewan = namaHwn;
    newElm->isidata.habitat = habitat;
    newElm->isidata.ekor = tail;
    newElm->isidata.bobot = weight;
    return newElm;
}

void deallocNodeParent(adrParent &NParent)
{
    if (NParent != Nil)
    {
        NParent->next = NParent->prev = Nil;
        delete NParent;
        NParent = Nil;
    }
}

void deallocNodeChild(adrChild &NChild)
{
    if (NChild != Nil)
    {
        NChild->next = NChild->prev = Nil;
        delete NChild;
        NChild = Nil;
    }
}

void insertFirstParent(listParent &LParent, adrParent NodeParent)
{
    if (isEmptyParent(LParent))
    {
        LParent.first = LParent.last = NodeParent;
    }
    else
    {
        NodeParent->next = LParent.first;
        LParent.first->prev = NodeParent;
        LParent.first = NodeParent;
    }
}

void insertLastParent(listParent &LParent, adrParent NodeParent)
{
    if (isEmptyParent(LParent))
    {
        LParent.first = LParent.last = NodeParent;
    }
    else
    {
        NodeParent->prev = LParent.last;
        LParent.last->next = NodeParent;
        LParent.last = NodeParent;
    }
}

void deleteFirstParent(listParent &LParent)
{
    adrParent temp = LParent.first;
    if (!isEmptyParent(LParent))
    {
        LParent.first = LParent.first->next;
        LParent.first->prev = Nil;
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, adrParent NPrev)
{
    adrParent temp = NPrev->next;
    if (temp != Nil)
    {
        if (NPrev->next->next != Nil)
        {
            NPrev->next = NPrev->next->next;
            NPrev->next->prev = NPrev;
        }
        else
        {
            NPrev->next = Nil;
        }
        delete temp;
    }
}

void insertFirstChild(listChild &LChild, adrChild NodeChild)
{
    if (LChild.first == Nil)
    {
        LChild.first = LChild.last = NodeChild;
    }
    else
    {
        NodeChild->prev = LChild.last;
        LChild.last->next = NodeChild;
        LChild.last = NodeChild;
    }
}

void insertLastChild(listChild &LChild, adrChild NodeChild)
{
    if (LChild.last == Nil)
    {
        LChild.first = LChild.last = NodeChild;
    }
    else
    {
        NodeChild->prev = LChild.last;
        LChild.last->next = NodeChild;
        LChild.last = NodeChild;
    }
}

void deleteFirstChild(listChild &LChild)
{
    adrChild temp = LChild.first;
    if (LChild.first != Nil)
    {
        LChild.first = LChild.first->next;
        LChild.first->prev = Nil;
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, adrChild NPrev)
{
    adrChild temp = NPrev->next;
    if (temp->next == Nil)
    {
        NPrev->next = NPrev->next->next;
        NPrev->next->next->prev = NPrev;
        delete temp;
    }
}

void printMLLStructure(listParent &LParent)
{
    adrParent tempParent = LParent.first;
    int posP = 1;

    while (tempParent != Nil)
    {
        adrChild tempChild = tempParent->L_Child.first;
        int posC = 1;
        cout << "=== Parent " << posP << " ===" << endl
             << "ID Golongan : " << tempParent->isiData.idGolongan << endl
             << "Nama Golongan : " << tempParent->isiData.namaGolongan << endl;
        while (tempChild != Nil)
        {
            cout << "  - Child " << posC << endl
                 << "      ID Hewan : " << tempChild->isidata.idHewan << endl
                 << "      Nama Hewan : " << tempChild->isidata.namaHewan << endl
                 << "      Habitat : " << tempChild->isidata.habitat << endl
                 << "      Ekor : " << tempChild->isidata.ekor << endl
                 << "      Bobot : " << tempChild->isidata.bobot << endl;
            posC++;
            tempChild = tempChild->next;
        }
        if (tempParent->L_Child.first == Nil)
        {
            cout << "(Tidak ada child)" << endl;
        }
        cout << "-----------------------------------" << endl;
        posP++;
        tempParent = tempParent->next;
    }
}

void deleteListChild(listChild &LChild)
{
    adrChild temp = LChild.first;
    while (temp != Nil)
    {
        if (temp->next != Nil)
        {
            LChild.first = LChild.first->next;
        }
        else
        {
            LChild.first = LChild.last = Nil;
        }
        deallocNodeChild(temp);
        temp = LChild.first;
    }
}

void searchHewanByEkor(listParent &LParent, bool tail)
{
    adrParent tempParent = LParent.first;
    int posP = 1;

    while (tempParent != Nil)
    {
        adrChild tempChild = tempParent->L_Child.first;
        int posC = 1;
        bool find = false;

        while (tempChild != Nil)
        {
            if (tempChild->isidata.ekor == tail)
            {
                cout << "Data ditemukan pada list anak dari node parent " << tempParent->isiData.namaGolongan << " pada posisi ke-" << posC << "!" << endl;
                cout << "--- Data Child ---" << endl
                     << "ID Child : " << tempChild->isidata.idHewan << endl
                     << "Posisi pada list anak : " << posC << endl
                     << "Nama Hewan : " << tempChild->isidata.namaHewan << endl
                     << "Habitat : " << tempChild->isidata.habitat << endl
                     << "Ekor : " << tempChild->isidata.ekor << endl
                     << "Bobot : " << tempChild->isidata.bobot << endl;
                find = true;
            }
            posC++;
            tempChild = tempChild->next;
        }
        if (find)
        {
            cout << "-----------------------------------" << endl;
            cout << "--- Data Parent ---" << endl
                 << "ID Parent : " << tempParent->isiData.idGolongan << endl
                 << "Posisi dalam list induk : " << posP << endl
                 << "Nama Golongan : " << tempParent->isiData.namaGolongan << endl;
            cout << "-----------------------------------" << endl;
        }
        posP++;
        tempParent = tempParent->next;
    }
}

```

#### main.cpp

```C++
#include "MultiLL.h"

int main()
{
    listParent kelompokHewan;
    createListParent(kelompokHewan);

    adrParent A, B, C, D, E;
    A = allocNodeParent("G001", "Aves");
    B = allocNodeParent("G002", "Mamalia");
    C = allocNodeParent("G003", "Pisces");
    D = allocNodeParent("G004", "Amfibi");
    E = allocNodeParent("G005", "Reptil");
    insertFirstParent(kelompokHewan, C);
    insertFirstParent(kelompokHewan, B);
    insertFirstParent(kelompokHewan, A);
    insertLastParent(kelompokHewan, D);
    insertLastParent(kelompokHewan, E);

    adrChild newChild;
    createListChild(A->L_Child);
    createListChild(B->L_Child);
    createListChild(D->L_Child);

    // Input Child G001
    newChild = allocnodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(A->L_Child, newChild);
    newChild = allocnodeChild("AV002", "Bebek", "Air", true, 2);
    insertFirstChild(A->L_Child, newChild);

    // Input Child G002
    newChild = allocnodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(B->L_Child, newChild);
    newChild = allocnodeChild("M003", "Gorilla", "Hutan", false, 160);
    insertFirstChild(B->L_Child, newChild);
    newChild = allocnodeChild("M002", "Kucing", "Darat", true, 4);
    insertFirstChild(B->L_Child, newChild);

    // Input Child G004
    newChild = allocnodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(D->L_Child, newChild);

    searchHewanByEkor(kelompokHewan, true);
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan13_Modul13/Unguided/screenshot/soal_2.png)

Pada bagian kedua ini, ditambahkan fungsi searcHewanByEkor yang berfungsi untuk mencari informasi hewan yang memiliki/tidak memiliki ekor dari setiap Node Parent.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### MultiLL.h

```h
#ifndef MULTILL_H
#define MULTILL_H
#define Nil NULL
#include <iostream>
using namespace std;

struct golonganHewan
{
    string idGolongan, namaGolongan;
};

struct dataHewan
{
    string idHewan, namaHewan, habitat;
    bool ekor;
    float bobot;
};

typedef struct NodeParent *adrParent;
typedef struct NodeChild *adrChild;

struct NodeChild
{
    dataHewan isidata;
    adrChild next, prev;
};

struct listChild
{
    adrChild first, last;
};

struct NodeParent
{
    golonganHewan isiData;
    adrParent next, prev;
    listChild L_Child;
};

struct listParent
{
    adrParent first, last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocnodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(adrParent &NParent);
void deallocNodeChild(adrChild &NChild);
void insertFirstParent(listParent &LParent, adrParent NodeParent);
void insertLastParent(listParent &LParent, adrParent NodeParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, adrParent NPrev);
void insertFirstChild(listChild &LChild, adrChild NodeChild);
void insertLastChild(listChild &LChild, adrChild NodeChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, adrChild NPrev);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

void searchHewanByEkor(listParent &LParent, bool tail);
#endif
```

#### MultiLL.cpp

```C++
#include "MultiLL.h"

bool isEmptyParent(listParent &LParent)
{
    if (LParent.first == Nil && LParent.last == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyChild(listChild &LChild)
{
    if (LChild.first == Nil && LChild.last == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListParent(listParent &LParent)
{
    LParent.first = LParent.last = Nil;
}

void createListChild(listChild &LChild)
{
    LChild.first = LChild.last = Nil;
}

adrParent allocNodeParent(string idGol, string namaGol)
{
    adrParent newElm = new NodeParent;
    newElm->next = Nil;
    newElm->prev = Nil;
    newElm->L_Child = listChild();
    newElm->isiData.idGolongan = idGol;
    newElm->isiData.namaGolongan = namaGol;
    return newElm;
}

adrChild allocnodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight)
{
    adrChild newElm = new NodeChild;
    newElm->next = Nil;
    newElm->prev = Nil;
    newElm->isidata.idHewan = idHwn;
    newElm->isidata.namaHewan = namaHwn;
    newElm->isidata.habitat = habitat;
    newElm->isidata.ekor = tail;
    newElm->isidata.bobot = weight;
    return newElm;
}

void deallocNodeParent(adrParent &NParent)
{
    if (NParent != Nil)
    {
        NParent->next = NParent->prev = Nil;
        delete NParent;
        NParent = Nil;
    }
}

void deallocNodeChild(adrChild &NChild)
{
    if (NChild != Nil)
    {
        NChild->next = NChild->prev = Nil;
        delete NChild;
        NChild = Nil;
    }
}

void insertFirstParent(listParent &LParent, adrParent NodeParent)
{
    if (isEmptyParent(LParent))
    {
        LParent.first = LParent.last = NodeParent;
    }
    else
    {
        NodeParent->next = LParent.first;
        LParent.first->prev = NodeParent;
        LParent.first = NodeParent;
    }
}

void insertLastParent(listParent &LParent, adrParent NodeParent)
{
    if (isEmptyParent(LParent))
    {
        LParent.first = LParent.last = NodeParent;
    }
    else
    {
        NodeParent->prev = LParent.last;
        LParent.last->next = NodeParent;
        LParent.last = NodeParent;
    }
}

void deleteFirstParent(listParent &LParent)
{
    adrParent temp = LParent.first;
    if (!isEmptyParent(LParent))
    {
        LParent.first = LParent.first->next;
        LParent.first->prev = Nil;
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, adrParent NPrev)
{
    adrParent temp = NPrev->next;
    if (temp != Nil)
    {
        if (NPrev->next->next != Nil)
        {
            NPrev->next = NPrev->next->next;
            NPrev->next->prev = NPrev;
        }
        else
        {
            NPrev->next = Nil;
        }
        delete temp;
    }
}

void insertFirstChild(listChild &LChild, adrChild NodeChild)
{
    if (LChild.first == Nil)
    {
        LChild.first = LChild.last = NodeChild;
    }
    else
    {
        NodeChild->prev = LChild.last;
        LChild.last->next = NodeChild;
        LChild.last = NodeChild;
    }
}

void insertLastChild(listChild &LChild, adrChild NodeChild)
{
    if (LChild.last == Nil)
    {
        LChild.first = LChild.last = NodeChild;
    }
    else
    {
        NodeChild->prev = LChild.last;
        LChild.last->next = NodeChild;
        LChild.last = NodeChild;
    }
}

void deleteFirstChild(listChild &LChild)
{
    adrChild temp = LChild.first;
    if (LChild.first != Nil)
    {
        LChild.first = LChild.first->next;
        LChild.first->prev = Nil;
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, adrChild NPrev)
{
    adrChild temp = NPrev->next;
    if (temp->next == Nil)
    {
        NPrev->next = NPrev->next->next;
        NPrev->next->next->prev = NPrev;
        delete temp;
    }
}

void printMLLStructure(listParent &LParent)
{
    adrParent tempParent = LParent.first;
    int posP = 1;

    while (tempParent != Nil)
    {
        adrChild tempChild = tempParent->L_Child.first;
        int posC = 1;
        cout << "=== Parent " << posP << " ===" << endl
             << "ID Golongan : " << tempParent->isiData.idGolongan << endl
             << "Nama Golongan : " << tempParent->isiData.namaGolongan << endl;
        while (tempChild != Nil)
        {
            cout << "  - Child " << posC << endl
                 << "      ID Hewan : " << tempChild->isidata.idHewan << endl
                 << "      Nama Hewan : " << tempChild->isidata.namaHewan << endl
                 << "      Habitat : " << tempChild->isidata.habitat << endl
                 << "      Ekor : " << tempChild->isidata.ekor << endl
                 << "      Bobot : " << tempChild->isidata.bobot << endl;
            posC++;
            tempChild = tempChild->next;
        }
        if (tempParent->L_Child.first == Nil)
        {
            cout << "(Tidak ada child)" << endl;
        }
        cout << "-----------------------------------" << endl;
        posP++;
        tempParent = tempParent->next;
    }
}

void deleteListChild(listChild &LChild)
{
    adrChild temp = LChild.first;
    while (temp != Nil)
    {
        if (temp->next != Nil)
        {
            LChild.first = LChild.first->next;
        }
        else
        {
            LChild.first = LChild.last = Nil;
        }
        deallocNodeChild(temp);
        temp = LChild.first;
    }
}

void searchHewanByEkor(listParent &LParent, bool tail)
{
    adrParent tempParent = LParent.first;
    int posP = 1;

    while (tempParent != Nil)
    {
        adrChild tempChild = tempParent->L_Child.first;
        int posC = 1;
        bool find = false;

        while (tempChild != Nil)
        {
            if (tempChild->isidata.ekor == tail)
            {
                cout << "Data ditemukan pada list anak dari node parent " << tempParent->isiData.namaGolongan << " pada posisi ke-" << posC << "!" << endl;
                cout << "--- Data Child ---" << endl
                     << "ID Child : " << tempChild->isidata.idHewan << endl
                     << "Posisi pada list anak : " << posC << endl
                     << "Nama Hewan : " << tempChild->isidata.namaHewan << endl
                     << "Habitat : " << tempChild->isidata.habitat << endl
                     << "Ekor : " << tempChild->isidata.ekor << endl
                     << "Bobot : " << tempChild->isidata.bobot << endl;
                find = true;
            }
            posC++;
            tempChild = tempChild->next;
        }
        if (find)
        {
            cout << "-----------------------------------" << endl;
            cout << "--- Data Parent ---" << endl
                 << "ID Parent : " << tempParent->isiData.idGolongan << endl
                 << "Posisi dalam list induk : " << posP << endl
                 << "Nama Golongan : " << tempParent->isiData.namaGolongan << endl;
            cout << "-----------------------------------" << endl;
        }
        posP++;
        tempParent = tempParent->next;
    }
}
```

#### main.cpp

```C++
#include "MultiLL.h"

int main()
{
    listParent kelompokHewan;
    createListParent(kelompokHewan);

    adrParent A, B, C, D, E;
    A = allocNodeParent("G001", "Aves");
    B = allocNodeParent("G002", "Mamalia");
    C = allocNodeParent("G003", "Pisces");
    D = allocNodeParent("G004", "Amfibi");
    E = allocNodeParent("G005", "Reptil");
    insertFirstParent(kelompokHewan, C);
    insertFirstParent(kelompokHewan, B);
    insertFirstParent(kelompokHewan, A);
    insertLastParent(kelompokHewan, D);
    insertLastParent(kelompokHewan, E);

    adrChild newChild;
    createListChild(A->L_Child);
    createListChild(B->L_Child);
    createListChild(D->L_Child);

    // Input Child G001
    newChild = allocnodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(A->L_Child, newChild);
    newChild = allocnodeChild("AV002", "Bebek", "Air", true, 2);
    insertFirstChild(A->L_Child, newChild);

    // Input Child G002
    newChild = allocnodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(B->L_Child, newChild);
    newChild = allocnodeChild("M003", "Gorilla", "Hutan", false, 160);
    insertFirstChild(B->L_Child, newChild);
    newChild = allocnodeChild("M002", "Kucing", "Darat", true, 4);
    insertFirstChild(B->L_Child, newChild);

    // Input Child G004
    newChild = allocnodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(D->L_Child, newChild);

    cout << "====== Sebelum dihapus ======" << endl;
    printMLLStructure(kelompokHewan);
    cout << endl
         << "====== Setelah dihapus ======" << endl;
    deleteListChild(D->L_Child);
    deleteAfterParent(kelompokHewan, C);
    printMLLStructure(kelompokHewan);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan13_Modul13/Unguided/screenshot/soal_3.png)

Melakukan operasi delete untuk Node Parent dengan ID Parent == G004, termasuk menghapus seluruh child yang berada di dalamnya.

## Kesimpulan

Struktur data tipe Multi Linked List memudahkan pengembangan aplikasi dengan data yang saling terhubung, di mana setiap elemen memiliki hubungan satu sama lain.

## Referensi

<br>[1] Sianturi, F. A. (2022). Pemanfaatan Link List Untuk Mengatasi Database Tidak Normal. LOFIAN: Jurnal Teknologi Informasi dan Komunikasi, 2(1), 16-23. 
<br>
<br>[2] Nadika, G. (n.d.). Detail Multi Linked List 1-N: Algoritma dan Struktur Data. Jurnal Struktur Data. Universitas Komputer Indonesia.
<br>
