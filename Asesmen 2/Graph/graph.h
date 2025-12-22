#ifndef KOTA_H
#define KOTA_H
#define Nil NULL
#include <iostream>
using namespace std;

typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;

struct ElmKota
{
    string namaKota;
    int visited;
    adrEdge firstEdge;
    adrKota next;
};

struct ElmEdge
{
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};

struct GraphKota
{
    adrKota First;
};

void createGraph(GraphKota &G);
adrKota alokasiNode(string namaKota);
adrEdge alokasiEdge(adrKota kotaTujuan, int jarak);
void insertNode(GraphKota &G, adrKota &N);
adrKota findNode(GraphKota &G, adrKota N);
void connectNode(adrKota &N1, adrKota &N2, int jarak);
void disconnectNode(adrKota &N1, adrKota &N2);
void deleteNode(GraphKota &G, adrKota N);
void printGraph(GraphKota G);
#endif