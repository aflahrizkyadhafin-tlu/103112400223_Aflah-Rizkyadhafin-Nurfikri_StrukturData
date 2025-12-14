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

// Fungsi bantu
adrNode AlokasiNode(infoGraph X);
adrEdge AlokasiEdge(adrNode N);

#endif