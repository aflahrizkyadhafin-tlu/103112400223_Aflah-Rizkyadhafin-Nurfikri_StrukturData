#ifndef Pelajaran_h
#define Pelajaran_h
#include <iostream>
using namespace std;

struct Pelajaran
{
    string namaMapel, kodeMapel;
};

Pelajaran create_mapel(string namapel, string kodepel);
void tampil_pelajaran(Pelajaran pel);

#endif