# <h1 align="center">Laporan Praktikum Modul 6 - Doubly Linked List (Bagian Pertama)</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

Double Linked List (DLL) adalah struktur data linier yang terdiri dari node-node yang saling berhubungan, di mana setiap node memiliki dua pointer: satu menunjuk ke node sebelumnya dan satu lagi ke node berikutnya dalam daftar. Hal ini membedakan DLL dari Single Linked List (SLL) yang hanya memiliki satu pointer ke node berikutnya. Keunggulan utama DLL terdapat pada kemudahan operasi penyisipan dan penghapusan data karena memungkinkan navigasi dua arah dalam daftar. Dalam penerapannya, DLL digunakan untuk berbagai algoritma yang membutuhkan fleksibilitas dalam menambah atau menghapus data baik di awal, di tengah, maupun di akhir list.[1]

Namun, struktur ini juga memiliki kelemahan, yaitu memerlukan alokasi memori yang lebih besar dibandingkan Single Linked List karena setiap node harus menyimpan dua buah pointer. Dalam konteks pengolahan data mahasiswa yang dinamis, Double Linked List dapat menjadi pilihan yang tepat ketika aplikasi membutuhkan navigasi yang lebih fleksibel, meskipun implementasinya memerlukan pertimbangan terkait efisiensi memori dan kompleksitas kode.[2]

### A. Single Linked List<br/>

### 1. Insert

#### 1.1 Insert First

#### 1.2 Insert Last

#### 1.3 Insert After

#### 1.4 Insert Before

### 2. Delete

#### 2.1 Delete First

#### 2.2 Delete Last

#### 2.3 Delete After

#### 2.4 Delete Before

#### 3. Update

#### 4. View

#### 5. Searching

## Guided

### 1. listMakanan

#### listMakanan.h

```h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct makanan
{
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node
{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif

```

#### listMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &List)
{
    List.first = Nil;
    List.last = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis;
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodePrev != Nil)
        {
            if (nodePrev == List.last)
            {
                insertLast(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodeNext != Nil)
        {
            if (nodeNext == List.first)
            {
                insertFirst(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl;
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); // menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); // menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodeNext != Nil && nodeNext->prev != Nil)
        {
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

#### main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    // D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}
```

Program ini mengimplementasikan struktur data double linked list untuk menyimpan data makanan yang terdiri dari nama, jenis, harga, dan rating. Kode menyediakan berbagai operasi dasar seperti insert (first, last, before, after) dan update (first, last, before, after) pada node dalam list. Program demonstrasi dalam main() menunjukkan penggunaan operasi-operasi tersebut dengan membuat lima node makanan dan menampilkan hasilnya sebelum dan setelah proses update.

### 2. listMakanan (Searching & Delete)

#### listMakanan.h

```h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include <iostream>
using namespace std;

struct makanan
{
    string nama;
    string jenis;
    float harga;
    float rating;
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node
{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist
{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif
```

#### listMakanan.cpp

```C++
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List)
{
    if (List.first == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(linkedlist &List)
{
    List.first = Nil;
    List.last = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating)
{
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis;
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating = rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node)
{
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List))
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodePrev != Nil)
        {
            if (nodePrev == List.last)
            {
                insertLast(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        List.first = List.last = nodeBaru;
    }
    else
    {
        if (nodeNext != Nil)
        {
            if (nodeNext == List.first)
            {
                insertFirst(List, nodeBaru);
            }
            else
            {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        }
        else
        {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl;
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); // menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); // menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    {
        if (nodeNext != Nil && nodeNext->prev != Nil)
        {
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); // menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.nama == nama)
        {
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.jenis == jenis)
        {
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating)
{
    if (isEmpty(List))
    {
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while (p != Nil)
    {
        if (p->isidata.rating >= minRating)
        {
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if (List.first == List.last)
    {
        List.first = List.last = Nil;
    }
    else
    {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (Prev == Nil || Prev->next == Nil)
    {
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if (Prev->next == List.last)
    {
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext)
{
    if (isEmpty(List) == true)
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if (nodeNext == Nil || nodeNext->prev == Nil)
    {
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if (nodeNext->prev == List.first)
    {
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target)
{
    if (isEmpty(List) == true || target == Nil)
    {
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if (target == List.first)
    {
        deleteFirst(List);
    }
    else if (target == List.last)
    {
        deleteLast(List);
    }
    else
    {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama)
{
    if (isEmpty(List))
    {
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while (target != Nil && target->isidata.nama != nama)
    {
        target = target->next;
    }
    if (target == Nil)
    {
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}
```

#### main.cpp

```C++
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    // D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl
         << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}
```

Program ini merupakan lanjutan dari program sebelumnya yang telah dilengkapi dengan fitur pencarian dan penghapusan. Fitur pencarian dapat dilakukan berdasarkan nama, jenis, atau rating minimum, sedangkan fitur penghapusan menyediakan berbagai metode seperti hapus di posisi tertentu (first, last, before, after) atau berdasarkan nama.

## Unguided

### 1.Buatlah ADT Doubly Linked list sebagai berikut di dalam file “Doublylist.h”:

```h
Type infotype : kendaraan <
    nopol : string
    warna : string
    thnBuat : integer
>

Type address : pointer to ElmList

Type ElmList <
    info : infotype
    next :address
    prev : address
>

Type List <
    First : address
    Last : address
>

procedure CreateList( input/output L : List )
function alokasi( x : infotype ) → address
procedure dealokasi(input/output P : address )
procedure printInfo( input L : List )
procedure insertLast(input/output L : List, input P : address )
```

### Buatlah implementasi ADT Doubly Linked list pada file “Doublylist.cpp” dan coba hasil implementasi ADT pada file “main.cpp”.

#### Doublylist.h

```h
#ifndef KENDARAAN_H
#define KENDARAAN_H
#define Nil NULL
#include <iostream>
using namespace std;

struct kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList
{
    kendaraan info;
    address next;
    address prev;
};

struct List
{
    address First;
    address Last;
};

void CreateList(List &L);
bool isEmpty(List L);
address alokasi(kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void insertLast(List &L, address P);
#endif
```

#### Doublylist.cpp

```C++
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

void printInfoAddress(address P)
{
    cout << "No. Polisi : " << P->info.nopol << endl;
    cout << "Warna : " << P->info.warna << endl;
    cout << "Tahun : " << P->info.thnBuat << endl;
    cout << endl;
}

void insertLast(List &L, address P)
{
    L.Last->next = P;
    P->prev = L.Last;
    L.Last = P;
    cout << endl;
}
```

#### main.cpp

```C++
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

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan6_Modul6/Unguided/screenshot/unguided_1.png)

Program ini merupakan implementasi dari abstract data type (ADT) doubly linked list untuk mengelola data kendaraan yang terdiri dari nomor polisi, warna, dan tahun pembuatan. Program menyediakan operasi dasar seperti pembuatan list, alokasi node, penyisipan di akhir list, serta pencetakan informasi seluruh data kendaraan. Pada fungsi main, program menerima input data kendaraan dari pengguna untuk empat node yang kemudian disimpan dan ditampilkan kembali menggunakan struktur doubly linked list.

### 2. Buat Prosedur

#### Doublylist.h

```h
#ifndef KENDARAAN_H
#define KENDARAAN_H
#define Nil NULL
#include <iostream>
using namespace std;

struct kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList
{
    kendaraan info;
    address next;
    address prev;
};

struct List
{
    address First;
    address Last;
};

void CreateList(List &L);
bool isEmpty(List L);
address alokasi(kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void printInfoAddress(address P);
void insertLast(List &L, address P);

// Soal 2
address findElm(List L, string x);
```

#### Doublylist.cpp

```C++
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

```

#### main.cpp

```C++
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
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan6_Modul6/Unguided/screenshot/unguided_2.png)

Program ini merupakan lanjutan dari program sebelumnya yang telah ditambahkan fungsi findElm untuk mencari data kendaraan berdasarkan nomor polisi dan fungsi printInfoAddress untuk menampilkan informasi kendaraan dari alamat node tertentu. Fungsi findElm melakukan pencarian secara linear dalam doubly linked list dan mengembalikan alamat node jika ditemukan, sedangkan printInfoAddress menampilkan detail kendaraan dari node yang ditunjuk oleh parameter alamat.

### 3. Operasi Aritmatika

#### Doublylist.h

```h
#ifndef KENDARAAN_H
#define KENDARAAN_H
#define Nil NULL
#include <iostream>
using namespace std;

struct kendaraan
{
    string nopol;
    string warna;
    int thnBuat;
};

typedef struct ElmList *address;

struct ElmList
{
    kendaraan info;
    address next;
    address prev;
};

struct List
{
    address First;
    address Last;
};

void CreateList(List &L);
bool isEmpty(List L);
address alokasi(kendaraan x);
void dealokasi(address &P);
void printInfo(List L);
void printInfoAddress(address P);
void insertLast(List &L, address P);

// Soal 2
address findElm(List L, string x);

// Soal 3
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void deleteAfter(address &prec, address &P);
#endif
```

#### Doublylist.cpp

```C++
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

```

#### main.cpp

```C++
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
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan6_Modul6/Unguided/screenshot/unguided_3.png)

Prosedur delete (deleteFirst, deleteLast, deleteAfter) berfungsi untuk menghapus elemen dari list dengan menjaga integritas hubungan pointer prev dan next. Setiap operasi delete akan melepas memori elemen yang dihapus menggunakan prosedur dealokasi.

## Kesimpulan

Modul minggu ini mempelajari konsep dari <b>Double Linked List</b>. Pada DLL, node memiliki alamat ke node sebelumnya (prev), hal ini memungkikan pembacaan data secara 2 arah. Selain itu pada DLL, alamat node terakhir juga disimpan ke dalam element prev pada list. Terdapat penambahan fungsi baru untuk insert dan delete, yaitu insert before dan delete before, hal ini mungkin karena pada DLL setiap node memiliki alamat ke node sebelumnya, berbeda dengan SLL yang hanya menyimpan alamat node setelahnya.

## Referensi

<br>[1] Agung Wijoyo, Lalu Akbar Prayudi, Muhamad Fiqih, Rendi Dwi Santoso, Ricky Tri Setiawan Putra, Teguh Arifin, & Ahmad Farhan. (2024). Penggunaan Algoritma Doubly Linked List Untuk Insertion Dan Deletion. JRIIN :Jurnal Riset Informatika Dan Inovasi, 1(12), 1329–1331. Retrieved from https://jurnalmahasiswa.com/index.php/jriin/article/view/1282.
<br>
<br>[2] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan, 4(2), 441-444. Retrieved from https://doi.org/10.62357/jsit.v4i2.591.
<br>
