# <h1 align="center">Laporan Praktikum Modul 5 - Single Linked List (Bagian 2)</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

Single linked list adalah jenis struktur data yang tersusun dari sejumlah node, di mana setiap node berisi data dan alamat (referensi) ke node berikutnya dalam rangkaian. Berbeda dengan array yang menyimpan elemen secara berdampingan dalam memori, linked list menggunakan lokasi memori yang tersebar, sehingga urutan elemen ditentukan dengan mengikuti referensi dari satu node ke node selanjutnya [1]. Dalam penerapannya, operasi dasar pada single linked list mencakup menambahkan data baru di bagian akhir list, mencari data tertentu dengan memeriksa node-node satu per satu mulai dari awal, menghapus node yang sesuai dengan data yang dicari, serta menampilkan semua data yang ada di dalam list [2].

### A. Single Linked List<br/>

#### 1. Update isi node

#### 2. Cari node

#### 3. Operasi data pada node

## Guided

### 1. ListBuah

#### listBuah.h

```h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif

```

#### listBuah.cpp

```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}
```

#### main.cpp

```C++
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

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

Program di atas, adalah program yang menjelaskan bagaimana cara implementasi Single Linked List dengan mneggunakan bahasa pemrograman C++. Program ini akan mendefinisikan semua tipe data bentukan (struct) dan function yang akan digunakan pada file list.h. Selanjutnya setiap fungsi akan diberikan aksi pada file list.cpp. File main.cpp digunakan untuk memanggil setiap fungsi yang sudah dibuat.

## Unguided

### Preparation
#### listAngka.h

```h
#ifndef LISTANGKA
#define LISTANGKA
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct infotype *address;

struct infotype {
    dataAngka angka;
    address Next;
};

struct List{
    address First;
};

void CreateList(List &L);
address alokasi (infotype x);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(address &nodeBaru, address &nodePrev);
int nbList(List L);
void delAfter(address &nodeHapus, address &nodePrev);
#endif
```

#### listAngka.cpp

```C++
#include "listAngka.h"

void CreateList(List &L)
{
    L.First = nullptr;
}

address alokasi(infotype x)
{
    address newNode = new infotype();
    newNode->angka = x.angka;
    newNode->Next = nullptr;
    return newNode;
}

void dealokasi(address &node)
{
    node->Next = nullptr;
    delete node;
}

void printList(List L)
{
    address temp = L.First;
    while (temp != nullptr)
    {
        cout << temp->angka << " - ";
        temp = temp->Next;
    }
    cout <<endl;
}

void insertFirst(List &L, address nodeBaru)
{
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(List &L, address nodeBaru)
{
    address temp = L.First;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
    }

    temp->Next = nodeBaru;
}

void insertAfter(address &nodeBaru, address &nodePrev)
{
    nodeBaru->Next = nodePrev->Next;
    nodePrev->Next = nodeBaru;
}

int nbList(List L)
{
    address temp = L.First;
    int countItem = 0;

    while (temp != nullptr)
    {
        countItem++;
        temp = temp->Next;
    }
    return countItem;
}

void delAfter(address &nodeHapus, address &nodePrev)
{
    nodePrev->Next = nodeHapus->Next;
    dealokasi(nodeHapus);
}
```

#### main.cpp

```C++
#include "listAngka.h"

int main()
{
    List linkedList;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF,nodeG = nullptr;
    infotype infoA, infoB, infoC, infoD, infoE, infoF;
    CreateList(linkedList);

    infoA.angka = 8;
    nodeA = alokasi(infoA);
    infoB.angka = 13;
    nodeB = alokasi(infoB);
    infoC.angka = 18;
    nodeC = alokasi(infoC);
    infoD.angka = 25;
    nodeD = alokasi(infoD);
    infoE.angka = 33;
    nodeE = alokasi(infoE);
    infoF.angka = 40;
    nodeF = alokasi(infoF);
    nodeG = alokasi(infotype());

    insertFirst(linkedList, nodeB);
    insertLast(linkedList, nodeA);
    insertAfter(nodeD, nodeB);
    insertFirst(linkedList, nodeC);
    insertLast(linkedList, nodeE);
    insertFirst(linkedList, nodeF);
    delAfter(nodeB, nodeC);
    printList(linkedList);
    return 0;
}
```
### Output Unguided Preparation :

##### Output 1

![Screenshot Output Unguided Preparation](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan5_Modul5/Unguided/screenshot/Pre-test.png)

Kode ini merupakan tipe data abstract untuk mengerjakan soal unguided modul 5 Struktur Data.

### 1.Buat Prosedur
### Procedure updateFirst (input / outputL: List)
### Procedure updatelast (input/outputL: List)
### Procedure updateAfter (input / output L : List, input nodePrev : address )

#### listAngka.h

```h
#ifndef LISTANGKA
#define LISTANGKA
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct infotype *address;

struct infotype {
    dataAngka angka;
    address Next;
};

struct List{
    address First;
};

void CreateList(List &L);
address alokasi (infotype x);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(address &nodeBaru, address &nodePrev);
int nbList(List L);
void delAfter(address &nodeHapus, address &nodePrev);

// Soal 1
void updateFirst(List &L);
void updateLast(List &L);
void updateAfter(address &nodePrev);

#endif
```

#### listAngka.cpp

```C++
#include "listAngka.h"

void CreateList(List &L)
{
    L.First = nullptr;
}

address alokasi(infotype x)
{
    address newNode = new infotype();
    newNode->angka = x.angka;
    newNode->Next = nullptr;
    return newNode;
}

void dealokasi(address &node)
{
    node->Next = nullptr;
    delete node;
}

void printList(List L)
{
    address temp = L.First;
    while (temp != nullptr)
    {
        cout << temp->angka << " - ";
        temp = temp->Next;
    }
    cout <<endl;
}

void insertFirst(List &L, address nodeBaru)
{
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(List &L, address nodeBaru)
{
    address temp = L.First;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
    }

    temp->Next = nodeBaru;
}

void insertAfter(address &nodeBaru, address &nodePrev)
{
    nodeBaru->Next = nodePrev->Next;
    nodePrev->Next = nodeBaru;
}

int nbList(List L)
{
    address temp = L.First;
    int countItem = 0;

    while (temp != nullptr)
    {
        countItem++;
        temp = temp->Next;
    }
    return countItem;
}

void delAfter(address &nodeHapus, address &nodePrev)
{
    nodePrev->Next = nodeHapus->Next;
    dealokasi(nodeHapus);
}

// Soal 1
void updateFirst(List &L)
{
    dataAngka D;
    cout << "Masukan update data node pertama : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    L.First->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};

void updateLast(List &L){
    dataAngka D;
    cout << "Masukan update data node terakhir : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    address last = L.First;
    while (last->Next != nullptr)
    {
        last = last->Next;
    }
    last->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};

void updateAfter(address &nodePrev)
{
    dataAngka D;
    cout << "Masukan update data setelah node " << nodePrev->angka << " : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    nodePrev->Next->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
}
```

#### main.cpp

```C++
#include "listAngka.h"

int main()
{
    List linkedList;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF,nodeG = nullptr;
    infotype infoA, infoB, infoC, infoD, infoE, infoF;
    CreateList(linkedList);

    infoA.angka = 8;
    nodeA = alokasi(infoA);
    infoB.angka = 13;
    nodeB = alokasi(infoB);
    infoC.angka = 18;
    nodeC = alokasi(infoC);
    infoD.angka = 25;
    nodeD = alokasi(infoD);
    infoE.angka = 33;
    nodeE = alokasi(infoE);
    infoF.angka = 40;
    nodeF = alokasi(infoF);
    nodeG = alokasi(infotype());

    insertFirst(linkedList, nodeB);
    insertLast(linkedList, nodeA);
    insertAfter(nodeD, nodeB);
    insertFirst(linkedList, nodeC);
    insertLast(linkedList, nodeE);
    insertFirst(linkedList, nodeF);
    delAfter(nodeB, nodeC);
    printList(linkedList);

    // Soal 1
    updateFirst(linkedList);
    updateAfter(nodeD);
    updateLast(linkedList);
    updateAfter(linkedList.First);
    printList(linkedList);
    return 0;
}

```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan5_Modul5/Unguided/screenshot/Soal_1.png)

Program ini memiliki tiga prosedur utama untuk mengubah data pada node dalam linked list, yaitu updateFirst, updateLast, dan updateAfter. Prosedur updateFirst mengubah nilai pada node pertama, updateLast memperbarui nilai pada node terakhir dengan melakukan penelusuran sampai akhir list, sementara updateAfter mengganti data pada node yang berada tepat setelah node tertentu. Ketiga prosedur ini bertujuan untuk memodifikasi isi data tanpa merubah hubungan antar node dalam linked list.

### 2. Buat Prosedur
### Procedure SearchByData(inputL: List, input data : integer)
### Procedure SearchByAddress( input L : List, input node : address )
### Procedure SearchByRange( input L : List, input nilaiMin : integer)

#### listAngka.h

```h
#ifndef LISTANGKA
#define LISTANGKA
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct infotype *address;

struct infotype {
    dataAngka angka;
    address Next;
};

struct List{
    address First;
};

void CreateList(List &L);
address alokasi (infotype x);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(address &nodeBaru, address &nodePrev);
int nbList(List L);
void delAfter(address &nodeHapus, address &nodePrev);

// Soal 1
void updateFirst(List &L);
void updateLast(List &L);
void updateAfter(address &nodePrev);

// Soal 2
void searchByData(List L, dataAngka data);
void searchByAddress(List L, address node);
void searchByRange(List L, int nilaiMin);

#endif

```

#### listAngka.cpp

```C++
#include "listAngka.h"

void CreateList(List &L)
{
    L.First = nullptr;
}

address alokasi(infotype x)
{
    address newNode = new infotype();
    newNode->angka = x.angka;
    newNode->Next = nullptr;
    return newNode;
}

void dealokasi(address &node)
{
    node->Next = nullptr;
    delete node;
}

void printList(List L)
{
    address temp = L.First;
    while (temp != nullptr)
    {
        cout << temp->angka << " - ";
        temp = temp->Next;
    }
    cout <<endl;
}

void insertFirst(List &L, address nodeBaru)
{
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(List &L, address nodeBaru)
{
    address temp = L.First;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
    }

    temp->Next = nodeBaru;
}

void insertAfter(address &nodeBaru, address &nodePrev)
{
    nodeBaru->Next = nodePrev->Next;
    nodePrev->Next = nodeBaru;
}

int nbList(List L)
{
    address temp = L.First;
    int countItem = 0;

    while (temp != nullptr)
    {
        countItem++;
        temp = temp->Next;
    }
    return countItem;
}

void delAfter(address &nodeHapus, address &nodePrev)
{
    nodePrev->Next = nodeHapus->Next;
    dealokasi(nodeHapus);
}

// Soal 1
void updateFirst(List &L)
{
    dataAngka D;
    cout << "Masukan update data node pertama : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    L.First->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};

void updateLast(List &L){
    dataAngka D;
    cout << "Masukan update data node terakhir : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    address last = L.First;
    while (last->Next != nullptr)
    {
        last = last->Next;
    }
    last->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};

void updateAfter(address &nodePrev)
{
    dataAngka D;
    cout << "Masukan update data setelah node " << nodePrev->angka << " : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    nodePrev->Next->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
}

// Soal 2
void searchByData(List L, dataAngka data) {
    bool findData = false;
    int indxFind = 1;
    address temp = L.First;

    while (temp != nullptr)
    {
        if (temp->angka == data){
            findData = true;
            cout << "Node dengan data " << data << " ditemukan pada posisi ke-" << indxFind <<endl;
        }
        indxFind++;
        temp = temp->Next;
    }
    if (!findData){
        cout << "Node dengan data " << data << " tidak ditemukan pada list " << endl;
    }
}

void searchByAddress(List L, address A) {
    bool findData = false;
    address temp = L.First;

    while (temp != nullptr)
    {
        if (temp == A){
            findData = true;
            cout << "Node dengan alamat " << A << " ditemukan pada list ini"<<endl;
        }
        temp = temp->Next;
    }
    if (!findData){
        cout << "Node dengan alamat " << A << " tidak ditemukan pada list " << endl;
    }
}

void searchByRange(List L, int nilaiMin) {
    bool findData = false;
    int indxFind = 1;
    address temp = L.First;

    while (temp != nullptr)
    {
        if (temp->angka > nilaiMin){
            findData = true;
            cout << "Data ditemukan pada posisi ke-" << indxFind << ", nilai : "<< temp->angka << endl;
        }
        indxFind++;
        temp = temp->Next;
    }
    if (!findData){
        cout << "Node dengan data lebih besar dari " << nilaiMin << " tidak ditemukan pada list " << endl;
    }
}
```

#### main.cpp

```C++
#include "listAngka.h"

int main()
{
    List linkedList;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF,nodeG = nullptr;
    infotype infoA, infoB, infoC, infoD, infoE, infoF;
    CreateList(linkedList);

    infoA.angka = 8;
    nodeA = alokasi(infoA);
    infoB.angka = 13;
    nodeB = alokasi(infoB);
    infoC.angka = 18;
    nodeC = alokasi(infoC);
    infoD.angka = 25;
    nodeD = alokasi(infoD);
    infoE.angka = 33;
    nodeE = alokasi(infoE);
    infoF.angka = 40;
    nodeF = alokasi(infoF);
    nodeG = alokasi(infotype());

    insertFirst(linkedList, nodeB);
    insertLast(linkedList, nodeA);
    insertAfter(nodeD, nodeB);
    insertFirst(linkedList, nodeC);
    insertLast(linkedList, nodeE);
    insertFirst(linkedList, nodeF);
    delAfter(nodeB, nodeC);
    printList(linkedList);

    // Soal 1
    updateFirst(linkedList);
    updateAfter(nodeD);
    updateLast(linkedList);
    updateAfter(linkedList.First);
    printList(linkedList);

    // Soal 2
    searchByData(linkedList, 20);
    searchByData(linkedList, 55);
    cout << endl;
    
    searchByAddress(linkedList, nodeB);
    searchByAddress(linkedList, nodeA);
    cout << endl;

    cout << "================ Data diatas 40 ================" << endl;
    searchByRange(linkedList, 40);
    cout << endl;
    
    cout << "================ Data diatas 99 ================" << endl;
    searchByRange(linkedList, 99);
    cout << endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan5_Modul5/Unguided/screenshot/Soal_2.png)

Tiga prosedur pencarian menggunakan parameter sebagai kunci untuk menemukan data dalam linked list, yaitu searchByData yang mencari node berdasarkan nilai data tertentu, searchByAddress yang mencari berdasarkan alamat node, dan searchByRange yang menampilkan semua node dengan nilai lebih besar dari batas yang ditentukan. Parameter pertama pada semua fungsi adalah list yang akan dijelajah, sedangkan parameter kedua menentukan kriteria pencarian. Ketiganya hanya membaca data tanpa mengubah struktur linked list.

### 3. Operasi Aritmatika

#### listAngka.h

```h
#ifndef LISTANGKA
#define LISTANGKA
#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct infotype *address;

struct infotype {
    dataAngka angka;
    address Next;
};

struct List{
    address First;
};

void CreateList(List &L);
address alokasi (infotype x);
void dealokasi(address &node);
void printList(List L);
void insertFirst(List &L, address nodeBaru);
void insertLast(List &L, address nodeBaru);
void insertAfter(address &nodeBaru, address &nodePrev);
int nbList(List L);
void delAfter(address &nodeHapus, address &nodePrev);

// Soal 1
void updateFirst(List &L);
void updateLast(List &L);
void updateAfter(address &nodePrev);

// Soal 2
void searchByData(List L, dataAngka data);
void searchByAddress(List L, address node);
void searchByRange(List L, int nilaiMin);

// Soal 3
void aritmatika(List L);
#endif
```

#### listAngka.cpp

```C++
#include "listAngka.h"

void CreateList(List &L)
{
    L.First = nullptr;
}

address alokasi(infotype x)
{
    address newNode = new infotype();
    newNode->angka = x.angka;
    newNode->Next = nullptr;
    return newNode;
}

void dealokasi(address &node)
{
    node->Next = nullptr;
    delete node;
}

void printList(List L)
{
    address temp = L.First;
    while (temp != nullptr)
    {
        cout << temp->angka << " - ";
        temp = temp->Next;
    }
    cout <<endl;
}

void insertFirst(List &L, address nodeBaru)
{
    nodeBaru->Next = L.First;
    L.First = nodeBaru;
}

void insertLast(List &L, address nodeBaru)
{
    address temp = L.First;
    while (temp->Next != nullptr)
    {
        temp = temp->Next;
    }

    temp->Next = nodeBaru;
}

void insertAfter(address &nodeBaru, address &nodePrev)
{
    nodeBaru->Next = nodePrev->Next;
    nodePrev->Next = nodeBaru;
}

int nbList(List L)
{
    address temp = L.First;
    int countItem = 0;

    while (temp != nullptr)
    {
        countItem++;
        temp = temp->Next;
    }
    return countItem;
}

void delAfter(address &nodeHapus, address &nodePrev)
{
    nodePrev->Next = nodeHapus->Next;
    dealokasi(nodeHapus);
}

// Soal 1
void updateFirst(List &L)
{
    dataAngka D;
    cout << "Masukan update data node pertama : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    L.First->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};

void updateLast(List &L){
    dataAngka D;
    cout << "Masukan update data node terakhir : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    address last = L.First;
    while (last->Next != nullptr)
    {
        last = last->Next;
    }
    last->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
};

void updateAfter(address &nodePrev)
{
    dataAngka D;
    cout << "Masukan update data setelah node " << nodePrev->angka << " : " << endl;
    cout << "Masukan angka : ";
    cin >> D;
    nodePrev->Next->angka = D;
    cout << "Data berhasil di update!" <<endl<< endl;
}

// Soal 2
void searchByData(List L, dataAngka data) {
    bool findData = false;
    int indxFind = 1;
    address temp = L.First;

    while (temp != nullptr)
    {
        if (temp->angka == data){
            findData = true;
            cout << "Node dengan data " << data << " ditemukan pada posisi ke-" << indxFind <<endl;
        }
        indxFind++;
        temp = temp->Next;
    }
    if (!findData){
        cout << "Node dengan data " << data << " tidak ditemukan pada list " << endl;
    }
}

void searchByAddress(List L, address A) {
    bool findData = false;
    address temp = L.First;

    while (temp != nullptr)
    {
        if (temp == A){
            findData = true;
            cout << "Node dengan alamat " << A << " ditemukan pada list ini"<<endl;
        }
        temp = temp->Next;
    }
    if (!findData){
        cout << "Node dengan alamat " << A << " tidak ditemukan pada list " << endl;
    }
}

void searchByRange(List L, int nilaiMin) {
    bool findData = false;
    int indxFind = 1;
    address temp = L.First;

    while (temp != nullptr)
    {
        if (temp->angka > nilaiMin){
            findData = true;
            cout << "Data ditemukan pada posisi ke-" << indxFind << ", nilai : "<< temp->angka << endl;
        }
        indxFind++;
        temp = temp->Next;
    }
    if (!findData){
        cout << "Node dengan data lebih besar dari " << nilaiMin << " tidak ditemukan pada list " << endl;
    }
}

// Soal 3
void aritmatika(List L) {
    int penjumlahan = 0, pengurangan = L.First->angka, perkalian = 1;
    address temp = L.First;

    while (temp != nullptr)
    {
        pengurangan-=temp->angka;
        penjumlahan+=temp->angka;
        perkalian*=temp->angka;
        temp = temp->Next;
    }

    cout << "Total penjumlahan : " << penjumlahan <<endl;
    cout << "Total pengurangan : " << pengurangan <<endl;
    cout << "Total perkalian : " << perkalian <<endl;
};
```

#### main.cpp

```C++
#include "listAngka.h"

int main()
{
    List linkedList;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF,nodeG = nullptr;
    infotype infoA, infoB, infoC, infoD, infoE, infoF;
    CreateList(linkedList);

    infoA.angka = 8;
    nodeA = alokasi(infoA);
    infoB.angka = 13;
    nodeB = alokasi(infoB);
    infoC.angka = 18;
    nodeC = alokasi(infoC);
    infoD.angka = 25;
    nodeD = alokasi(infoD);
    infoE.angka = 33;
    nodeE = alokasi(infoE);
    infoF.angka = 40;
    nodeF = alokasi(infoF);
    nodeG = alokasi(infotype());

    insertFirst(linkedList, nodeB);
    insertLast(linkedList, nodeA);
    insertAfter(nodeD, nodeB);
    insertFirst(linkedList, nodeC);
    insertLast(linkedList, nodeE);
    insertFirst(linkedList, nodeF);
    delAfter(nodeB, nodeC);
    printList(linkedList);

    // Soal 1
    updateFirst(linkedList);
    updateAfter(nodeD);
    updateLast(linkedList);
    updateAfter(linkedList.First);
    printList(linkedList);

    // Soal 2
    searchByData(linkedList, 20);
    searchByData(linkedList, 55);
    cout << endl;
    
    searchByAddress(linkedList, nodeB);
    searchByAddress(linkedList, nodeA);
    cout << endl;

    cout << "================ Data diatas 40 ================" << endl;
    searchByRange(linkedList, 40);
    cout << endl;
    
    cout << "================ Data diatas 99 ================" << endl;
    searchByRange(linkedList, 99);
    cout << endl;

    // Soal 3
    aritmatika(linkedList);

    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan5_Modul5/Unguided/screenshot/Soal_3.png)

Prosedur aritmatika(List L) melakukan perhitungan operasi aritmatika dasar pada seluruh elemen dalam list. Prosedur ini menghitung total penjumlahan, pengurangan, dan perkalian dari semua nilai angka yang terdapat pada node-list. Namun, terdapat kesalahan logika pada operasi pengurangan karena nilai awal di-set sebagai elemen pertama lalu dikurangi setiap elemen (termasuk elemen pertama lagi), sehingga hasilnya tidak akurat untuk operasi pengurangan beruntun.

## Kesimpulan

Modul minggu ini mempelajari bagaimana implementasi Single Linked List pada bahasa C++. Fungsi yang dibuat dan digunakan diantaranya, fungsi untuk mengubah isi dari suatu node, mencari node berdasarkan data/alamat nodenya dan melakukan operasi aritmatika isi dari setiap nodenya.

## Referensi

<br>[1] Dietz, P. F. (1982, May). Maintaining order in a linked list. In Proceedings of the fourteenth annual ACM symposium on Theory of computing (pp. 122-127). Diakses pada 17 Oktober 2025 melalui https://dl.acm.org/doi/pdf/10.1145/800070.802184.
<br>
<br>[2] Mbejo, M. T., Nopa, L. A., Putri, J. S., & Risky, M. (2025). Analisis Struktur Data Linked List Dalam Pengolahan Data Mahasiswa. Jurnal Sains Informatika Terapan, 4(2), 441-444. Diakses pada 17 Oktober 2025 melalui https://rcf-indonesia.org/jurnal/index.php/jsit/article/view/591/418.
<br>
