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
