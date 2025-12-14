# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

Graph adalah struktur data non-linier yang terbentuk dari himpunan simpul (vertex) dan himpunan sisi (edge), di mana simpul mewakili entitas data dan sisi merepresentasikan hubungan relasi antar simpul tersebut. Berbeda dengan struktur data linier, Graph mampu memodelkan masalah kompleks yang melibatkan keterhubungan banyak arah, seperti rute transportasi, jaringan komputer, atau jejaring sosial, karena strukturnya memungkinkan relasi antar objek yang tidak terbatas pada urutan sekuensial [1].

Dalam pemrosesannya, Graph sering ditelusuri menggunakan algoritma pencarian seperti Breadth-First Search (BFS) yang menyebar secara melebar atau Depth-First Search (DFS) yang menelusuri kedalaman. Metode penelusuran dan representasi graf ini sangat krusial dalam menyelesaikan berbagai masalah komputasi dan optimasi, seperti penentuan lintasan terpendek (shortest path) antar dua titik lokasi ataupun penyelesaian teka-teki logika [2].

### A. Graph<br/>

#### 1. Kelola node dengan menggunakan graph

#### 2. Print graph secara Breadth-First Search (BFS)

#### 3. Print graph secara Depth-First Search (DFS)

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

### 1. Buatlah ADT Graph tidak berarah file “graph.h”: :
```h
Type infoGraph: char
Type adrNode : pointer to ElmNode
Type adrEdge : pointer to ElmNode
Type ElmNode <
    info : infoGraph
    visited : integer
    firstEdge : adrEdge
    Next : adrNode
>
    Type ElmEdge <
    Node : adrNode
    Next : adrEdge
>
Type Graph <
    first : adrNode
>
procedure CreateGraph (input/output G : Graph)
procedure InsertNode (input/output G : Graph,
input X : infotype)
procedure ConnectNode (input/output N1, N2 : adrNode)
procedure PrintInfoGraph (input G : Graph)
```

#### graphLat.h

```h
#ifndef GRAPHLAT_H
#define GRAPHLAT_H
#define Nil NULL
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
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintInfoGraph(Graph G);

// Fungsi bantu
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);
adrNode FindNode(Graph G, infoGraph X);
#endif
```

#### graphLat.cpp

```C++
#include "graphLat.h"

void CreateGraph(Graph &G)
{
    G.first = Nil;
}

void InsertNode(Graph &G, infoGraph X)
{
    adrNode newNode = AlokasiNode(X);

    if (G.first == Nil)
    {
        G.first = newNode;
    }
    else
    {
        adrNode temp = G.first;
        while (temp->Next != Nil)
        {
            temp = temp->Next;
        }

        temp->Next = newNode;
    }
}

void ConnectNode(adrNode &N1, adrNode &N2)
{
    if (N1 != NULL && N2 != NULL)
    {
        adrEdge Edge1 = AlokasiEdge(N2);
        Edge1->Next = N1->firstEdge;
        N1->firstEdge = Edge1;

        adrEdge Edge2 = AlokasiEdge(N1);
        Edge2->Next = N2->firstEdge;
        N2->firstEdge = Edge2;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}

void PrintInfoGraph(Graph G)
{
    adrNode nodeBantu = G.first;
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

// Fungsi bantu
adrNode AlokasiNode(infoGraph X)
{
    adrNode newNode = new ElmNode;
    newNode->firstEdge = Nil;
    newNode->Next = Nil;
    newNode->visited = 0;
    newNode->info = X;
    return newNode;
}

adrEdge AlokasiEdge(adrNode N)
{
    adrEdge newEdge = new ElmEdge;
    newEdge->Next = Nil;
    newEdge->Node = N;
    return newEdge;
}

adrNode FindNode(Graph G, infoGraph X)
{
    adrNode temp = G.first;
    while (temp != Nil && temp->info != X)
    {
        temp = temp->Next;
    }
    return temp;
}

```

#### main.cpp

```C++
#include "graphLat.h"

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
     InsertNode(G, 'G');
     InsertNode(G, 'H');

     adrNode NodeA = FindNode(G, 'A');
     adrNode NodeB = FindNode(G, 'B');
     adrNode NodeC = FindNode(G, 'C');
     adrNode NodeD = FindNode(G, 'D');
     adrNode NodeE = FindNode(G, 'E');
     adrNode NodeF = FindNode(G, 'F');
     adrNode NodeG = FindNode(G, 'G');
     adrNode NodeH = FindNode(G, 'H');

     ConnectNode(NodeA, NodeB);
     ConnectNode(NodeA, NodeC);
     ConnectNode(NodeB, NodeD);
     ConnectNode(NodeB, NodeE);
     ConnectNode(NodeC, NodeF);
     ConnectNode(NodeC, NodeG);
     ConnectNode(NodeD, NodeH);
     ConnectNode(NodeE, NodeH);
     ConnectNode(NodeF, NodeH);
     ConnectNode(NodeG, NodeH);

     cout << "==== PRINT INFO GRAPH ====" << endl;
     PrintInfoGraph(G);
     return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan14_Modul14/Unguided/screenshot/soal_1.png)

Program ini mengimplementasikan struktur data graf tidak berarah (undirected graph) menggunakan representasi adjacency list dalam bahasa C++, yang mencakup operasi dasar seperti pembuatan graf, penambahan node, dan penghubungan antar node. 

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.

#### graphLat.h

```h
#ifndef GRAPHLAT_H
#define GRAPHLAT_H
#define Nil NULL
#include <iostream>
#include <stack>
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
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintInfoGraph(Graph G);

// Nomor 2
void PrintDFS(Graph G, adrNode N);
```

#### graphLat.cpp

```C++
#include "graphLat.h"

void CreateGraph(Graph &G)
{
    G.first = Nil;
}

void InsertNode(Graph &G, infoGraph X)
{
    adrNode newNode = AlokasiNode(X);

    if (G.first == Nil)
    {
        G.first = newNode;
    }
    else
    {
        adrNode temp = G.first;
        while (temp->Next != Nil)
        {
            temp = temp->Next;
        }

        temp->Next = newNode;
    }
}

void ConnectNode(adrNode &N1, adrNode &N2)
{
    if (N1 != NULL && N2 != NULL)
    {
        adrEdge Edge1 = AlokasiEdge(N2);
        Edge1->Next = N1->firstEdge;
        N1->firstEdge = Edge1;

        adrEdge Edge2 = AlokasiEdge(N1);
        Edge2->Next = N2->firstEdge;
        N2->firstEdge = Edge2;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}

void PrintInfoGraph(Graph G)
{
    adrNode nodeBantu = G.first;
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

// Soal 2
void PrintDFS(Graph G, adrNode N)
{
    adrNode nodeReset = G.first;
    while (nodeReset != NULL)
    {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }

    adrNode StartNode = N;

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

// Fungsi bantu
adrNode AlokasiNode(infoGraph X)
{
    adrNode newNode = new ElmNode;
    newNode->firstEdge = Nil;
    newNode->Next = Nil;
    newNode->visited = 0;
    newNode->info = X;
    return newNode;
}

adrEdge AlokasiEdge(adrNode N)
{
    adrEdge newEdge = new ElmEdge;
    newEdge->Next = Nil;
    newEdge->Node = N;
    return newEdge;
}

adrNode FindNode(Graph G, infoGraph X)
{
    adrNode temp = G.first;
    while (temp != Nil && temp->info != X)
    {
        temp = temp->Next;
    }
    return temp;
}

```

#### main.cpp

```C++
#include "graphLat.h"

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
     InsertNode(G, 'G');
     InsertNode(G, 'H');

     adrNode NodeA = FindNode(G, 'A');
     adrNode NodeB = FindNode(G, 'B');
     adrNode NodeC = FindNode(G, 'C');
     adrNode NodeD = FindNode(G, 'D');
     adrNode NodeE = FindNode(G, 'E');
     adrNode NodeF = FindNode(G, 'F');
     adrNode NodeG = FindNode(G, 'G');
     adrNode NodeH = FindNode(G, 'H');

     ConnectNode(NodeA, NodeB);
     ConnectNode(NodeA, NodeC);
     ConnectNode(NodeB, NodeD);
     ConnectNode(NodeB, NodeE);
     ConnectNode(NodeC, NodeF);
     ConnectNode(NodeC, NodeG);
     ConnectNode(NodeD, NodeH);
     ConnectNode(NodeE, NodeH);
     ConnectNode(NodeF, NodeH);
     ConnectNode(NodeG, NodeH);

     cout << "==== PRINT INFO GRAPH ====" << endl;
     PrintInfoGraph(G);

     // Soal 2
     cout << endl
          << "==== PRINT DFS ====" << endl;
     PrintDFS(G, NodeE);
     return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan14_Modul14/Unguided/screenshot/soal_2.png)

Pada bagian kedua ini, program menyediakan algoritma penelusuran graf yaitu DFS (Depth-First Search) menggunakan stack.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### graphLat.h

```h
#ifndef GRAPHLAT_H
#define GRAPHLAT_H
#define Nil NULL
#include <iostream>
#include <stack>
#include <queue>
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
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode &N1, adrNode &N2);
void PrintInfoGraph(Graph G);

// Nomor 2
void PrintDFS(Graph G, adrNode N);

// Nomor 3
void PrintBFS(Graph G, adrNode N);

// Fungsi bantu
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);
adrNode FindNode(Graph G, infoGraph X);
#endif
```

#### graphLat.cpp

```C++
#include "graphLat.h"

void CreateGraph(Graph &G)
{
    G.first = Nil;
}

void InsertNode(Graph &G, infoGraph X)
{
    adrNode newNode = AlokasiNode(X);

    if (G.first == Nil)
    {
        G.first = newNode;
    }
    else
    {
        adrNode temp = G.first;
        while (temp->Next != Nil)
        {
            temp = temp->Next;
        }

        temp->Next = newNode;
    }
}

void ConnectNode(adrNode &N1, adrNode &N2)
{
    if (N1 != NULL && N2 != NULL)
    {
        adrEdge Edge1 = AlokasiEdge(N2);
        Edge1->Next = N1->firstEdge;
        N1->firstEdge = Edge1;

        adrEdge Edge2 = AlokasiEdge(N1);
        Edge2->Next = N2->firstEdge;
        N2->firstEdge = Edge2;
    }
    else
    {
        cout << "Node tidak ditemukan!" << endl;
    }
}

void PrintInfoGraph(Graph G)
{
    adrNode nodeBantu = G.first;
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

// Soal 2
void PrintDFS(Graph G, adrNode N)
{
    adrNode nodeReset = G.first;
    while (nodeReset != NULL)
    {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }

    adrNode StartNode = N;

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

// Soal 3
void PrintBFS(Graph G, adrNode N)
{
    adrNode nodeReset = G.first;
    while (nodeReset != NULL)
    {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }

    adrNode StartNode = N;

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

// Fungsi bantu
adrNode AlokasiNode(infoGraph X)
{
    adrNode newNode = new ElmNode;
    newNode->firstEdge = Nil;
    newNode->Next = Nil;
    newNode->visited = 0;
    newNode->info = X;
    return newNode;
}

adrEdge AlokasiEdge(adrNode N)
{
    adrEdge newEdge = new ElmEdge;
    newEdge->Next = Nil;
    newEdge->Node = N;
    return newEdge;
}

adrNode FindNode(Graph G, infoGraph X)
{
    adrNode temp = G.first;
    while (temp != Nil && temp->info != X)
    {
        temp = temp->Next;
    }
    return temp;
}

```

#### main.cpp

```C++
#include "graphLat.h"

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
     InsertNode(G, 'G');
     InsertNode(G, 'H');

     adrNode NodeA = FindNode(G, 'A');
     adrNode NodeB = FindNode(G, 'B');
     adrNode NodeC = FindNode(G, 'C');
     adrNode NodeD = FindNode(G, 'D');
     adrNode NodeE = FindNode(G, 'E');
     adrNode NodeF = FindNode(G, 'F');
     adrNode NodeG = FindNode(G, 'G');
     adrNode NodeH = FindNode(G, 'H');

     ConnectNode(NodeA, NodeB);
     ConnectNode(NodeA, NodeC);
     ConnectNode(NodeB, NodeD);
     ConnectNode(NodeB, NodeE);
     ConnectNode(NodeC, NodeF);
     ConnectNode(NodeC, NodeG);
     ConnectNode(NodeD, NodeH);
     ConnectNode(NodeE, NodeH);
     ConnectNode(NodeF, NodeH);
     ConnectNode(NodeG, NodeH);

     cout << "==== PRINT INFO GRAPH ====" << endl;
     PrintInfoGraph(G);

     // Soal 2
     cout << endl
          << "==== PRINT DFS ====" << endl;
     PrintDFS(G, NodeE);

     // Soal 3
     cout << endl
          << "==== PRINT BFS ====" << endl;
     PrintBFS(G, NodeB);
     return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan14_Modul14/Unguided/screenshot/soal_3.png)

Pada bagian ketiga ini, program menyediakan algoritma penelusuran graf yaitu BFS (Breadth-First Search) menggunakan queue untuk mengunjungi seluruh node yang terhubung dari titik awal tertentu.

## Kesimpulan

Menggunakan struktur data tipe tree akan memiliki keuntungan, karena data yang disimpan bisa disesuaikan urutan/kelompoknya dengan data parentnya. Penelusuran dengan tree juga bisa terjadi lebih cepat, berkat tersusunya setiap node dengan lebih rapih sesuai dengan kondisi.

## Referensi

<br>[1] Tobing, F. L., & Tobing, F. A. T. (2022). Analisis Perbandingan Algoritma DFS, BFS dan Dijkstra untuk Menentukan Rute Terpendek pada Peta Geografis. Jurnal Mahasiswa Aplikasi Teknologi Komputer dan Informasi (JMApTeKsi), 4(1), 20-26.
<br>
<br>[2] Sari, Y. P., & Nurhadi, A. (2021). Penerapan Algoritma Breadth First Search (BFS) dan Depth First Search (DFS) pada Pencarian Rute Terpendek. Jurnal Sistem Informasi dan Teknologi (JBSITEK), 2(2), 25-32.
<br>
