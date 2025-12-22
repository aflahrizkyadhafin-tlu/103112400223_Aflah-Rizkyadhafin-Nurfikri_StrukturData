#include "graph.h"

void createGraph(GraphKota &G)
{
    G.First = Nil;
}

adrKota alokasiNode(string namaKota)
{
    adrKota newNode = new ElmKota;
    newNode->namaKota = namaKota;
    newNode->visited = 0;
    newNode->firstEdge = Nil;
    newNode->next = Nil;
    return newNode;
}

adrEdge alokasiEdge(adrKota kotaTujuan, int jarak)
{
    adrEdge newNode = new ElmEdge;
    newNode->kotaTujuan = kotaTujuan;
    newNode->jarak = 0;
    newNode->next = Nil;
    return newNode;
}

void insertNode(GraphKota &G, adrKota &N)
{
    adrKota temp = G.First;

    if (temp == Nil)
    {
        G.First = N;
    }
    else
    {
        N->next = G.First;
        G.First = N;
    }
}

adrKota findNode(GraphKota &G, adrKota N)
{
    adrKota temp = G.First;

    while (temp != Nil)
    {
        if (temp == N)
        {
            return temp;
        }
        temp = temp->next;
    }
    return Nil;
}

void connectNode(adrKota &N1, adrKota &N2, int jarak)
{
    if (N1->firstEdge == Nil)
    {
        N1->firstEdge->kotaTujuan = N2;
        N1->firstEdge->jarak = jarak;
    }
    else
    {
        adrEdge prev = Nil, temp = N1->firstEdge;
        while (temp != Nil)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp;
        temp->kotaTujuan = N2;
        temp->jarak = jarak;
    }
    if (N2->firstEdge == Nil)
    {
        N2->firstEdge->kotaTujuan = N1;
        N2->firstEdge->jarak = jarak;
    }
    else
    {
        adrEdge prev = Nil, temp = N2->firstEdge;
        while (temp != Nil)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp;
        temp->kotaTujuan = N1;
        temp->jarak = jarak;
    }
}

void disconnectNode(adrKota &N1, adrKota &N2)
{
    adrEdge prev = Nil, temp = N1->firstEdge;
    while (temp != Nil && temp->kotaTujuan != N2)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != Nil)
    {
        prev->next = temp->next;
    }

    prev = Nil, temp = N2->firstEdge;
    while (temp != Nil && temp->kotaTujuan != N1)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp != Nil)
    {
        prev->next = temp->next;
    }
}

void deleteNode(GraphKota &G, adrKota N)
{
    adrKota prev = Nil, temp = G.First, deleteNode = Nil;
    while (temp != Nil)
    {
        if (temp->firstEdge->kotaTujuan == N)
        {
            disconnectNode(temp, N);
        }
        if (temp == N)
        {
            prev = temp;
            deleteNode = temp;
        }
        temp = temp->next;
    }
    if (deleteNode != Nil)
    {
        prev->next = temp->next;
        temp->next = Nil;
        delete temp;
    }
}

void printGraph(GraphKota G)
{
    adrKota temp = G.First;

    while (temp != Nil)
    {
        cout << "Node " << temp->namaKota << " terhubung ke: ";
        adrEdge tempEdge = temp->firstEdge;
        while (tempEdge != Nil)
        {
            cout << tempEdge->kotaTujuan->namaKota << "(" << tempEdge->jarak << " Km), ";
            tempEdge = tempEdge->next;
        }
        cout << endl;
        temp = temp->next;
    }
}
