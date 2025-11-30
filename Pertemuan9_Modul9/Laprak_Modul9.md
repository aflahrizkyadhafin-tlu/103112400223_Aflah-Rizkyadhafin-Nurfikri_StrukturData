# <h1 align="center">Laporan Praktikum Modul 10 - Tree</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori


Berbeda dengan struktur linear seperti array atau linked list, tree adalah struktur data non-linear yang mengorganisasi informasi secara hierarkis. Dalam model ini, setiap unit data (node) terhubung melalui hubungan induk-anak (parent-child). Struktur dimulai dari satu node pusat di puncak yang disebut root, lalu bercabang ke node-node di bawahnya hingga berakhir pada leaf (daun). Pendekatan ini memungkinkan pengelolaan data bertingkat yang lebih efisien [1].

Sifat hierarkis pada struktur data tree mengimplikasikan bahwa aksesibilitas informasi ditentukan oleh lintasan spesifik dari root menuju node tujuan. Dalam konfigurasi yang seimbang, struktur ini menawarkan optimasi kinerja yang signifikan untuk operasi komputasi seperti pencarian, penyisipan, dan penghapusan data. Meskipun setiap node diizinkan memiliki variasi jumlah turunan, integritas hierarki wajib dijaga dengan memastikan ketiadaan siklus (loop) dalam relasi antar elemen. Sebagai bentuk implementasi fundamental, binary tree merepresentasikan model ini dengan batasan bahwa setiap node hanya diperbolehkan memiliki maksimal dua entitas turunan [2].

### A. Queue<br/>

#### 1. Insert data dalam tree

#### 2. Mencari data pada tree

#### 3. Menampilkan seluruh data dalam tree (In Order, Pre Order dan Post Order)

#### 4. Menghapus data dalam tree

## Guided

### 1. Tree

#### bst.h

```h
#ifndef BST_H
#define BST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct BST *node;

struct BST
{
    int angka;
    node left, right;
};

typedef node BinTree;

bool isEmpty(BinTree tree);
void createTree(BinTree &tree);
node alokasi(int angka);
void dealokasi(node nodeHapus);

void insertNode(BinTree &tree, node nodeBaru);
void searchByData(BinTree tree, int angka);
void preOrder(BinTree tree);
void inOrder(BinTree tree);
void postOrder(BinTree tree);

bool deleteNode(BinTree &tree, int angka);
node mostRight(BinTree tree);
node mostLeft(BinTree tree);
void deleteTree(BinTree &tree);
int size(BinTree tree);
int height(BinTree tree);
#endif

```

#### bst.cpp

```C++
#include "bst.h"
#include <iostream>

using namespace std;
// NOTE : parameter tree disini maksudnya merujuk ke node; baik itu node root atau node lain dari tree

bool isEmpty(BinTree tree)
{
    if (tree == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createTree(BinTree &tree)
{
    tree = Nil;
}

node alokasi(int angkaInput)
{
    node nodeBaru = new BST;
    nodeBaru->angka = angkaInput;
    nodeBaru->left = Nil;
    nodeBaru->right = Nil;
    return nodeBaru;
}

void dealokasi(node nodeHapus)
{
    delete nodeHapus;
}

void insertNode(BinTree &tree, node nodeBaru)
{
    if (tree == Nil)
    {
        tree = nodeBaru;
        cout << "Node " << nodeBaru->angka << " berhasil ditambahkan ke dalam tree!" << endl;
        return;
    }
    else if (nodeBaru->angka < tree->angka)
    {
        insertNode(tree->left, nodeBaru);
    }
    else if (nodeBaru->angka > tree->angka)
    {
        insertNode(tree->right, nodeBaru);
    }
}

void searchByData(BinTree tree, int angkaCari)
{
    if (isEmpty(tree) == true)
    {
        cout << "Tree kosong!" << endl;
    }
    else
    {
        node nodeBantu = tree;
        node parent = Nil;
        bool ketemu = false;
        while (nodeBantu != Nil)
        {
            if (angkaCari < nodeBantu->angka)
            {
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            }
            else if (angkaCari > nodeBantu->angka)
            {
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            }
            else if (angkaCari == nodeBantu->angka)
            {
                ketemu = true;
                break;
            }
        }
        if (ketemu == false)
        {
            cout << "Data tidak ditemukan" << endl;
        }
        else if (ketemu == true)
        {
            cout << "Data ditemukan didalam tree!" << endl;
            cout << "Data Angka : " << nodeBantu->angka << endl;

            // menampilkan parentnya & pengecekan sibling
            node sibling = Nil;
            if (parent != Nil)
            {
                cout << "Parent : " << parent->angka << endl;
                if (parent->left == nodeBantu)
                {
                    sibling = parent->right;
                }
                else if (parent->right == nodeBantu)
                {
                    sibling = parent->left;
                }
            }
            else
            {
                cout << "Parent : - (node root)" << endl;
            }

            // menampilkan siblingnya
            if (sibling != Nil)
            {
                cout << "Sibling : " << sibling->angka << endl;
            }
            else
            {
                cout << "Sibling : - " << endl;
            }

            // menampilkan childnya
            if (nodeBantu->left != Nil)
            {
                cout << "Child kiri : " << nodeBantu->left->angka << endl;
            }
            else if (nodeBantu->left == Nil)
            {
                cout << "Child kiri : -" << endl;
            }
            if (nodeBantu->right != Nil)
            {
                cout << "Child kanan : " << nodeBantu->right->angka << endl;
            }
            else if (nodeBantu->right == Nil)
            {
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

void preOrder(BinTree tree)
{ // tengah - kiri - kanan atau root - child kiri - child kanan
    if (tree == Nil)
    {
        return;
    }
    cout << tree->angka << " - ";
    preOrder(tree->left);
    preOrder(tree->right);
}

void inOrder(BinTree tree)
{ // kiri - tengah - kanan atau child kiri - root - child kanan
    if (tree == Nil)
    {
        return;
    }
    inOrder(tree->left);
    cout << tree->angka << " - ";
    inOrder(tree->right);
}

void postOrder(BinTree tree)
{ // kiri - kanan - tengah atau child kiri - child kanan - root
    if (tree == Nil)
    {
        return;
    }
    postOrder(tree->left);
    postOrder(tree->right);
    cout << tree->angka << " - ";
}

bool deleteNode(BinTree &tree, int angka)
{
    if (tree == Nil)
    {
        return false; // data tidak ditemukan di subtree ini
    }
    else
    {
        if (angka < tree->angka)
        {
            return deleteNode(tree->left, angka);
        }
        else if (angka > tree->angka)
        {
            return deleteNode(tree->right, angka);
        }
        else
        {
            // jika node yang mau dihapus ditemukan
            // Case 1 : node yang mau dihapus adalah leaf
            if (tree->left == Nil && tree->right == Nil)
            {
                node tmp = tree;
                tree = Nil;
                dealokasi(tmp);
            }
            // Case 2 : node yang mau dihapus hanya punya right child
            else if (tree->left == Nil)
            {
                node tmp = tree;
                tree = tree->right;
                dealokasi(tmp);
            }
            // Case 3 : node yang mau dihapus hanya punya left child
            else if (tree->right == Nil)
            {
                node tmp = tree;
                tree = tree->left;
                dealokasi(tmp);
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else
            {
                // mostleft dari subtree kanan = node successor (node penerus)
                node successor = mostLeft(tree->right);
                // salin data successor ke node saat ini
                tree->angka = successor->angka;
                // hapus successor pada subtree kanan
                return deleteNode(tree->right, successor->angka);
            }
            return true; // berhasil dihapus
        }
    }
}

node mostRight(BinTree tree)
{
    while (tree->right != Nil)
    {
        tree = tree->right;
    }
    return tree;
}

node mostLeft(BinTree tree)
{
    while (tree->left != Nil)
    {
        tree = tree->left;
    }
    return tree;
}

void deleteTree(BinTree &tree)
{
    if (tree == Nil)
    {
        return;
    }
    else
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        dealokasi(tree);
        tree = Nil;
    }
}

int size(BinTree tree)
{ // mengembalikan jumlah semua node
    if (isEmpty(tree) == true)
    {
        return 0;
    }
    else
    {
        return 1 + size(tree->left) + size(tree->right);
    }
    cout << endl;
}

int height(BinTree tree)
{ // mengembalikan jumlah level tree
    if (isEmpty(tree) == true)
    {
        return -1; // tree kosong jika height = -1
    }
    else
    {
        int hl = height(tree->left);
        int hr = height(tree->right);
        int maxHeight;
        if (hl > hr)
        {
            maxHeight = hl;
        }
        else
        {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
    cout << endl;
}

```

#### main.cpp

```C++
#include <iostream>
#include "bst.h"

using namespace std;

int main()
{
    BinTree tree;
    createTree(tree);

    int pilih, angka;

    do
    {
        cout << "========= MENU BST =========" << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Tampilkan PreOrder" << endl;
        cout << "5. Tampilkan InOrder" << endl;
        cout << "6. Tampilkan PostOrder" << endl;
        cout << "7. Size Tree (jumlah node)" << endl;
        cout << "8. Height Tree (tinggi level)" << endl;
        cout << "9. Tampilkan mostright" << endl;
        cout << "10. Tampilkan mostleft" << endl;
        cout << "11. Delete Seluruh Tree" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan anda : ";
        cin >> pilih;
        cout << endl;

        switch (pilih)
        {
        case 1:
            cout << "Masukkan angka: ";
            cin >> angka;
            insertNode(tree, alokasi(angka));
            cout << endl;
            break;

        case 2:
            if (isEmpty(tree) == true)
            {
                cout << "Tree kosong!" << endl;
            }
            else
            {
                cout << "Masukkan angka yang ingin dihapus: ";
                cin >> angka;
                if (deleteNode(tree, angka))
                {
                    cout << "Data " << angka << " berhasil dihapus!" << endl;
                }
                else
                {
                    cout << "Data " << angka << " tidak ditemukan!" << endl;
                }
            }
            cout << endl;
            break;

        case 3:
            if (isEmpty(tree) == true)
            {
                cout << "Tree kosong!" << endl;
            }
            else
            {
                cout << "Masukkan angka yang ingin dicari: ";
                cin >> angka;
                searchByData(tree, angka);
            }
            cout << endl;
            break;

        case 4:
            if (isEmpty(tree) == true)
            {
                cout << "Tree kosong!" << endl;
            }
            else
            {
                cout << "PreOrder : ";
                preOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 5:
            if (isEmpty(tree) == true)
            {
                cout << "Tree kosong!" << endl;
            }
            else
            {
                cout << "InOrder : ";
                inOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 6:
            if (isEmpty(tree) == true)
            {
                cout << "Tree kosong!" << endl;
            }
            else
            {
                cout << "PostOrder : ";
                postOrder(tree);
                cout << endl;
            }
            cout << endl;
            break;

        case 7:
            cout << "Size Tree = " << size(tree) << endl;
            cout << endl;
            break;

        case 8:
            cout << "Height Tree = " << height(tree) << endl;
            cout << endl;
            break;

        case 9:
            if (isEmpty(tree) == true)
            {
                cout << "Tree kosong!" << endl;
                cout << endl;
            }
            else
            {
                cout << "Mostright : " << mostRight(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 10:
            if (isEmpty(tree) == true)
            {
                cout << "Tree kosong!" << endl;
                cout << endl;
            }
            else
            {
                cout << "Mostleft : " << mostLeft(tree)->angka << endl;
                cout << endl;
            }
            break;

        case 11:
            if (isEmpty(tree) == true)
            {
                cout << "Tree kosong!" << endl;
            }
            else
            {
                deleteTree(tree);
                cout << "Seluruh tree berhasil dihapus!" << endl;
            }
            cout << endl;
            break;

        case 0:
            cout << "Keluar dari program..." << endl;
            break;

        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
        }

    } while (pilih != 0);

    return 0;
}
```

Program ini adalah implementasi lengkap Binary Search Tree (BST) dalam C++ yang mendukung operasi insert, delete, search lengkap dengan info parent-sibling-child, serta print dengan jenis pre-order, in-order, post-order. Dilengkapi juga fungsi size, height, most left/right, dan delete seluruh tree.

## Unguided

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file "bstree.h" :
```h
Type infotype: integer
Type address : pointer to Node
Type Node: <
info : infotype
left, right : address
>
function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address,
input x : infotype )
function findNode( x : infotype, root : address )→address
procedure printInorder( input root : address )
```
### Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”.

#### bstree.h

```h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;
struct Node
{
    infotype info;
    address left, right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInOrder(address root);

#endif
```

#### bstree.cpp

```C++
#include "bstree.h"

address alokasi(infotype x)
{
    address newNode = new Node();
    newNode->info = x;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

void insertNode(address &root, infotype x)
{
    address newNode = alokasi(x);
    address check = findNode(root, x);

    if (check == Nil)
    {
        if (root == Nil)
        {
            root = newNode;
            return;
        }
        else if (x < root->info)
        {
            insertNode(root->left, x);
        }
        else
        {
            insertNode(root->right, x);
        }
    }
}

address findNode(address root, infotype x)
{
    if (root == Nil)
    {
        return Nil;
    }

    if (x == root->info)
    {
        return root;
    }
    else if (x < root->info)
    {
        return findNode(root->left, x);
    }
    else
    {
        return findNode(root->right, x);
    }
}

void printInOrder(address root)
{
    if (root == Nil)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}
```

#### main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    printInOrder(root);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan9_Modul9/Unguided/screenshot/soal_1.png)

Kode ini merupakan kode untuk menyimpan node dengan menggunakan tree. Pada bagian ini program dapat menambahkan data (termasuk cek data duplikat) dan print semua data yang terdapat dalam tree dari kecil ke besar.

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### queue.h

```h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;
struct Node
{
    infotype info;
    address left, right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);
void printInOrder(address root);

// Soal 2
int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);
#endif
```

#### bstree.cpp

```C++
#include "bstree.h"

address alokasi(infotype x)
{
    address newNode = new Node();
    newNode->info = x;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

void insertNode(address &root, infotype x)
{
    address newNode = alokasi(x);
    address check = findNode(root, x);

    if (check == Nil)
    {
        if (root == Nil)
        {
            root = newNode;
            return;
        }
        else if (x < root->info)
        {
            insertNode(root->left, x);
        }
        else
        {
            insertNode(root->right, x);
        }
    }
}

address findNode(address root, infotype x)
{
    if (root == Nil)
    {
        return Nil;
    }

    if (x == root->info)
    {
        return root;
    }
    else if (x < root->info)
    {
        return findNode(root->left, x);
    }
    else
    {
        return findNode(root->right, x);
    }
}

void printInOrder(address root)
{
    if (root == Nil)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->info << " - ";
    printInOrder(root->right);
}

// Soal 2
int hitungJumlahNode(address root)
{
    if (root == Nil)
    {
        return 0;
    }
    else
    {
        return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
    }
}

int hitungTotalInfo(address root)
{
    if (root == Nil)
    {
        return 0;
    }
    else
    {
        return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
    }
}

int hitungKedalaman(address root, int start)
{
    if (root == Nil)
    {
        return start;
    }
    else
    {
        int hl = hitungKedalaman(root->left, start);
        int hr = hitungKedalaman(root->right, start);
        int maxHeight;
        if (hl > hr)
        {
            maxHeight = hl;
        }
        else
        {
            maxHeight = hr;
        }
        return 1 + maxHeight;
    }
}
```

#### main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    printInOrder(root);
    cout << "\n";
    cout << "kedalaman : " << hitungKedalaman(root, 0) << endl;
    cout << "jumlah Node : " << hitungJumlahNode(root) << endl;
    cout << "total : " << hitungTotalInfo(root) << endl;
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan9_Modul9/Unguided/screenshot/soal_2.png)

Kode ini penambahan dari nomer satu, dengan menambahkan fungsi untuk menghitung kedalaman tree, jumlah node yang ada dan jumlah seluruh info yang terdapat di dalam node.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### queue.h

```h
#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef int infotype;
typedef struct Node *address;
struct Node
{
    infotype info;
    address left, right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
address findNode(address root, infotype x);

// Soal 3
void printPreOrder(address root);
void printPostOrder(address root);
#endif
```

#### bstree.cpp

```C++
#include "bstree.h"

address alokasi(infotype x)
{
    address newNode = new Node();
    newNode->info = x;
    newNode->left = Nil;
    newNode->right = Nil;
    return newNode;
}

void insertNode(address &root, infotype x)
{
    address newNode = alokasi(x);
    address check = findNode(root, x);

    if (check == Nil)
    {
        if (root == Nil)
        {
            root = newNode;
            return;
        }
        else if (x < root->info)
        {
            insertNode(root->left, x);
        }
        else
        {
            insertNode(root->right, x);
        }
    }
}

address findNode(address root, infotype x)
{
    if (root == Nil)
    {
        return Nil;
    }

    if (x == root->info)
    {
        return root;
    }
    else if (x < root->info)
    {
        return findNode(root->left, x);
    }
    else
    {
        return findNode(root->right, x);
    }
}

void printPreOrder(address root)
{
    if (root == Nil)
    {
        return;
    }
    cout << root->info << " - ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(address root)
{
    if (root == Nil)
    {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->info << " - ";
}
```

#### main.cpp

```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main()
{
    cout << "Hello World" << endl;
    address root = Nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    cout << endl
         << "========== Print Pre Order ==========" << endl;
    printPreOrder(root);
    cout << endl
         << endl
         << "========== Print Post Order ==========" << endl;
    printPostOrder(root);
    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan9_Modul9/Unguided/screenshot/soal_3.png)

Fungsi untuk menampilkan isi data dari tree secara pre order dan post order. Pada pre order root akan dicetak di awal, diteruskan oleh child kiri lalu terakhir child kanan. Sedangkan pada post order print akan dimulai dari child sebelah kiri, dilanjutkan dengan child kanan dan diakhiri dengan root.

## Kesimpulan

Menyimpan data dengan menggunakan metode tree akan mempersingkat waktu pencarian data. Pada metode BST (Binary Search Tree), data akan disusun dengan menggunakan aturan, child sebelah kiri lebih kecil dari parent sedangkan child sebelah kanan akan lebih besar dari parent.

## Referensi

<br>[1] Septian, H., Suhartini, I., Pertrio, I., & Jihad, L. A. (2021). Implementasi struktur data tree pada game Pacman dengan C. Jurnal Digit: Digital of Information Technology, 11(2), 120-129.
<br>
<br>[2] Djayusman, D., Suhartini, I., Gunawan, F. N., Alhakim, N. T., & Gunawan, T. (2021). IMPLEMENTASI STRUKTUR DATA TREE PADA GAME SNAKE DENGAN C. Jurnal Digit: Digital of Information Technology, 11(1), 20-27.
<br>
