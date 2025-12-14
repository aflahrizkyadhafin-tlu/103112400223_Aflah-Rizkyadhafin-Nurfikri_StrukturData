# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori


### A. Graph<br/>

#### 1. Menggunakan multi linked list dengan node tipe SLL

#### 2. Menggunakan multi linked list dengan node tipe DLL

## Guided

### 1. Graph

#### graph.h

```h
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>

using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode
{
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge
{
    adrNode Node;
    adrEdge Next;
};

struct Graph
{
    adrNode First;
};

void CreateGraph(Graph &G);
adrNode AlokasiNode(infoGraph data);
adrEdge AlokasiEdge(adrNode nodeTujuan);
void InsertNode(Graph &G, infoGraph data);
adrNode FindNode(Graph G, infoGraph data);
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);
void DisconnectNode(adrNode Node1, adrNode Node2);
void DeleteNode(Graph &G, infoGraph X);
void PrintInfoGraph(Graph G);
void ResetVisited(Graph &G);
void PrintBFS(Graph G, infoGraph StartInfo);
void PrintDFS(Graph G, infoGraph StartInfo);

#endif
```

#### graph.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

// prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G)
{
    G.First = NULL;
}

// alokasi Node baru
adrNode AlokasiNode(infoGraph data)
{
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; // isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

// alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan)
{
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

// Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data)
{
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL)
    {
        G.First = nodeBaru;
    }
    else
    {
        // konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL)
        {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

// function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data)
{
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL)
    {
        if (nodeBantu->info == data)
        {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

// prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2)
{
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL)
    {
        // Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        // Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}

// prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2)
{
    if (node1 != NULL && node2 != NULL)
    {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        // Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2)
        {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL)
        { // jika Edge ditemukan
            if (PrevE == NULL)
            {
                // Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            }
            else
            {
                // Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

// prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X)
{
    // 1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL)
    {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    // 2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    // cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL)
    {
        DisconnectNode(nodeLainnya, nodeHapus); // putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    // 3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    // Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL)
    {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    // 4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus)
    {
        // jika nodeHapus di awal
        G.First = nodeHapus->Next;
    }
    else
    {
        // jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus)
        {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    // 5. delete nodeHapus
    delete nodeHapus;
}

// Menampilkan isi Graph (Adjacency List)
void PrintInfoGraph(Graph G)
{
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL)
    {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL)
        {
            cout << edgeBantu->Node->info << " "; // Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

// Reset status visited sebelum traversal
void ResetVisited(Graph &G)
{
    adrNode nodeReset = G.First;
    while (nodeReset != NULL)
    {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

// traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo)
{
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);

    if (StartNode == NULL)
        return;

    queue<adrNode> Qyu;

    // Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty())
    {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        // Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL)
        {
            if (edgeBantu->Node->visited == 0)
            {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

// Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo)
{
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);

    if (StartNode == NULL)
        return;

    stack<adrNode> Stak;

    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty())
    {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0)
        {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            // masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL)
            {
                if (edgeBantu->Node->visited == 0)
                {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
```

#### main.cpp

```C++
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    // Hubungkan antar node
    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ==" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << "=== HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if (FindNode(G, 'E') == NULL)
    {
        cout << "Node E berhasil terhapus" << endl;
    }
    else
    {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    return 0;
}
```

Program ini adalah implementasi lengkap dari Graf dalam C++.

## Unguided

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
```h

```

#### MultiLL.h

```h

```

#### MultiLL.cpp

```C++

```

#### main.cpp

```C++

```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan13_Modul13/Unguided/screenshot/soal_1.png)

Kode ini merupakan kode untuk menyimpan node dengan menggunakan MLL. Pada bagian ini program sudah bisa membuat list kosong, menambahkan data parent baru, menambahkan data child serta menghapus data parent/child.

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp. Ekspektasi output :

#### MultiLL.h

```h

```

#### MultiLL.cpp

```C++

```

#### main.cpp

```C++

```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan13_Modul13/Unguided/screenshot/soal_2.png)

Pada bagian kedua ini, ditambahkan fungsi searcHewanByEkor yang berfungsi untuk mencari informasi hewan yang memiliki/tidak memiliki ekor dari setiap Node Parent.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### MultiLL.h

```h

```

#### MultiLL.cpp

```C++

```

#### main.cpp

```C++

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
