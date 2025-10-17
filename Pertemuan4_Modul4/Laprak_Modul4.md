# <h1 align="center">Laporan Praktikum Modul 4 - Single Linked List</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

Single linked list adalah jenis struktur data yang tersusun dari sejumlah node, di mana setiap node berisi data dan alamat (referensi) ke node berikutnya dalam rangkaian. Berbeda dengan array yang menyimpan elemen secara berdampingan dalam memori, linked list menggunakan lokasi memori yang tersebar, sehingga urutan elemen ditentukan dengan mengikuti referensi dari satu node ke node selanjutnya [1]. Dalam penerapannya, operasi dasar pada single linked list mencakup menambahkan data baru di bagian akhir list, mencari data tertentu dengan memeriksa node-node satu per satu mulai dari awal, menghapus node yang sesuai dengan data yang dicari, serta menampilkan semua data yang ada di dalam list [2].

### A. Pengenalan Single Linked List<br/>

#### 1. Membuat List Kosong

#### 2. Menambahkan Element(Node) baru ke List

#### 3. Menampilkan isi setiap Node

#### 4. Menghapus Node

## Guided

### 1. Struct

#### list.h

```h
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

#endif

```

#### list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
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

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim
                 << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

#### main.cpp

```C++
#include "list.h"

#include <iostream>
using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

Program di atas, adalah program yang menjelaskan bagaimana cara implementasi Single Linked List dengan mneggunakan bahasa pemrograman C++. Program ini akan mendefinisikan semua tipe data bentukan (struct) dan function yang akan digunakan pada file list.h. Selanjutnya setiap fungsi akan diberikan aksi pada file list.cpp. File main.cpp digunakan untuk memanggil setiap fungsi yang sudah dibuat.

### 2. Abstract Data Type

#### list.h

```h
#ifndef List_h
#define List_h
#define Nil NULL

#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama, nim;
    int umur;
};

typedef mahasiswa dataMahasiswa;
typedef struct node *address;

struct node
{
    dataMahasiswa isidata;
    address next;
};

struct linkedlist
{
    address first;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address prev);
void insertLast(linkedlist &list, address nodeBaru);

void delFirst(linkedlist &list);
void delLast(linkedlist &list);
void delAfter(linkedlist &list, address nodeHapus, address nodePrev);
int nbList(linkedlist list);
void deleteList(linkedlist &list);
#endif
```

#### list.cpp

```C++
#include "list.h"
#include <iostream>
using namespace std;

// I.S = Initial State / kondisi awal
// F.S = Final State / kondisi akhir

// fungsi untuk cek apakah list kosong atau tidak
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

// pembuatan linked list kosong
void createList(linkedlist &List)
{
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

// pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur)
{
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim;
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

// penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node)
{
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

// prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first;
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev)
{
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil)
    {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    }
    else
    {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru)
{
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List))
    {
        List.first = nodeBaru;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil)
        {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

// prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node pertama di list terhapus*/
    address nodeHapus;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List)
{
    /* I.S. list tidak kosong
    F.S. node terakhir di list terhapus */
    address nodeHapus, nodePrev;
    if (isEmpty(List) == false)
    {
        nodeHapus = List.first;
        if (nodeHapus->next == Nil)
        {
            List.first->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            while (nodeHapus->next != Nil)
            {
                nodePrev = nodeHapus;
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil;
            dealokasi(nodeHapus);
        }
    }
    else
    {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev)
{
    /* I.S. list tidak kosng, Prev alamat salah satu elemen list
    F.S. nodeBantu adalah alamat dari Prev→next, menghapus Prev→next dari list */
    if (isEmpty(List) == true)
    {
        cout << "List kosong!" << endl;
    }
    else
    { // jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil)
        {
            nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            nodeHapus->next = Nil;
            dealokasi(nodeHapus);
        }
        else
        {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// prosedur untuk menampilkan isi list
void printList(linkedlist List)
{
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List))
    {
        cout << "List kosong." << endl;
    }
    else
    {
        address nodeBantu = List.first;
        while (nodeBantu != Nil)
        {
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

// function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List)
{
    /* I.S. list sudah ada
       F.S. menampilkan jumlah node didalam list*/
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        count++;
        nodeBantu = nodeBantu->next;
    }
    return count;
}

// prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List)
{
    /* I.S. list sudah ada
       F.S. menghapus semua node didalam list*/
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while (nodeBantu != Nil)
    {
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus);
    }
    List.first = Nil;
    cout << "List sudah terhapus!" << endl;
}
```

#### main.h

```C++
#include "list.h"

#include <iostream>
using namespace std;

int main()
{
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

Program ini merupakan kelanjutan dari program di soal guided 1. Perbedaannya terletak pada penambahan prosedur deleteFirst(), deleteAfter(), deleteLast(), deleteList() dan fungsi nbList(). Prosedur deleteFirst() digunakan untuk menghapus node pertama dari List, deleteAfter() digunakan untuk menghapus node setelah node p dari List, deleteLast() digunakan untuk menghapus node terkahir dari List, deleteList() digunakan untuk menghapus seluruh node di List dan fungsi nbList() digunakan menghitung jumlah node yang ada dari suatu List.

## Unguided

### 1.

#### singliylist.h

```h
#ifndef SINGLIYLIST_H
#define SINGLIYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
};

struct List
{
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
#endif
```

#### singliylist.cpp

```C++
#include "singliylist.h"

// Latihan 1
void createList(List &L)
{
    L.first = Nil;
}

address alokasi(infotype x)
{
    address newElm = new ElmList();
    newElm->info = x;
    newElm->next = Nil;
    return newElm;
}

void dealokasi(address &P)
{
    P->next = Nil;
    delete P;
}

void printInfo(List L)
{
    address temp = L.first;
    while (temp != Nil)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

void insertFirst(List &L, address P)
{
    P->next = L.first;
    L.first = P;
}
```

#### main.h

```C++
#include "singliylist.h"

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan4_Modul4/Unguided/Screenshot/screenshot_1.png)

Kode ini mengelola struktur data singly linked list dengan beberapa fungsi dasar, antara lain createList untuk menginisialisasi list kosong, alokasi untuk membuat node baru dengan nilai tertentu, dealokasi untuk menghapus node, insertFirst untuk menambahkan node di awal list, serta printInfo untuk menampilkan semua isi list.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":

#### singliylist.h

```h
#ifndef SINGLIYLIST_H
#define SINGLIYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList
{
    infotype info;
    address next;
};

struct List
{
    address first;
};

// Latihan 1
void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

// Latihan 2
void nbList(List L);
void deleteFirst(List &L);
void deleteAfter(address &P);
void deleteLast(List &L);
void deleteList(List &L);
#endif
```

#### singliylist.cpp

```C++
#include "singliylist.h"

// Latihan 1
void createList(List &L)
{
    L.first = Nil;
}

address alokasi(infotype x)
{
    address newElm = new ElmList();
    newElm->info = x;
    newElm->next = Nil;
    return newElm;
}

void dealokasi(address &P)
{
    P->next = Nil;
    delete P;
}

void printInfo(List L)
{
    address temp = L.first;
    while (temp != Nil)
    {
        cout << temp->info << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}

void insertFirst(List &L, address P)
{
    P->next = L.first;
    L.first = P;
}

// Latihan 2
void nbList(List L)
{
    int nodeLength = 0;
    address temp = L.first;
    while (temp != Nil)
    {
        cout << temp->info << " ";
        nodeLength++;
        temp = temp->next;
    }
    cout << endl
         << "Jumlah node : " << nodeLength << endl
         << endl;
}

void deleteFirst(List &L)
{
    address P = L.first;
    L.first = P->next;
    dealokasi(P);
}

void deleteAfter(address &P)
{
    address temp = P->next;
    P->next = P->next->next;
    dealokasi(temp);
}

void deleteLast(List &L)
{
    address P = L.first, prev = Nil;
    while (P->next != Nil)
    {
        prev = P;
        P = P->next;
    }
    prev->next = Nil;
    dealokasi(P);
}

void deleteList(List &L)
{
    address temp = L.first, P;
    while (temp != Nil)
    {
        P = temp;
        temp = temp->next;
        dealokasi(P);
    }
    L.first = Nil;
    cout << "- List Berhasil Terhapus -";
}

```

#### main.h

```C++
#include "singliylist.h"

int main()
{
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    deleteFirst(L);
    deleteAfter(P4);
    deleteLast(L);
    nbList(L);
    deleteList(L);
    nbList(L);

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan4_Modul4/Unguided/Screenshot/screenshot_2.png)

Lanjutan dari program unguided 1, dimana pada bagian unguided 2 ditambahkan prosedur deleteFirst(), deleteAfter(), deleteLast(), deleteList() dan nbList(). Prosedur deleteFirst berfungsi untuk menghapus node pertama, deleteAfter untuk menghapus node setelah node tertentu, deleteLast untuk menghapus node terakhir, deleteList untuk menghapus seluruh node dan nbList untuk menampilkan jumlah node yang tersedia pada suatu list.

## Kesimpulan

Modul minggu ini mempelajari bagaimana implementasi Single Linked List pada bahasa C++. Dari pembahasan minggu ini terlihat perbedaan bentuk serta penggunaan Single Linked List dengan Array. Dimana Single Linked List dihubungkan dengan menggunakan address dari node berikutnya.

## Referensi

<br>[1] Dietz, P. F. (1982, May). Maintaining order in a linked list. In Proceedings of the fourteenth annual ACM symposium on Theory of computing (pp. 122-127). Diakses pada 17 Oktober 2025 melalui https://dl.acm.org/doi/pdf/10.1145/800070.802184.
<br>
<br>[2] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan, 4(2), 441-444. Diakses pada 17 Oktober 2025 melalui https://rcf-indonesia.org/jurnal/index.php/jsit/article/view/591/418.
<br>
