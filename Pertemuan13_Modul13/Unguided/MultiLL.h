#ifndef MULTILL_H
#define MULTILL_H
#define Nil NULL
#include <iostream>
using namespace std;

struct golonganHewan
{
    string idGolongan, namaGolongan;
};

struct dataHewan
{
    string idHewan, namaHewan, habitat;
    bool ekor;
    float bobot;
};

typedef struct NodeParent *adrParent;
typedef struct NodeChild *adrChild;

struct NodeChild
{
    dataHewan isidata;
    adrChild next, prev;
};

struct listChild
{
    adrChild first, last;
};

struct NodeParent
{
    golonganHewan isiData;
    adrParent next, prev;
    listChild L_Child;
};

struct listParent
{
    adrParent first, last;
};

bool isEmptyParent(listParent &LParent);
bool isEmptyChild(listChild &LChild);
void createListParent(listParent &LParent);
void createListChild(listChild &LChild);
adrParent allocNodeParent(string idGol, string namaGol);
adrChild allocnodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);
void deallocNodeParent(adrParent &NParent);
void deallocNodeChild(adrChild &NChild);
void insertFirstParent(listParent &LParent, adrParent NodeParent);
void insertLastParent(listParent &LParent, adrParent NodeParent);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, adrParent NPrev);
void insertFirstChild(listChild &LChild, adrChild NodeChild);
void insertLastChild(listChild &LChild, adrChild NodeChild);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, adrChild NPrev);
void printMLLStructure(listParent &LParent);
void deleteListChild(listChild &LChild);

void searchHewanByEkor(listParent &LParent, bool tail);
#endif