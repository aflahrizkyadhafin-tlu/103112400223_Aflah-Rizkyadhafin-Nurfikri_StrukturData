#include "pelajaran.h"

Pelajaran create_mapel(string namapel, string kodepel)
{
    Pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(Pelajaran pel)
{
    cout << "Nama pelajaran : " << pel.namaMapel << endl
         << "Nama pelajaran : " << pel.kodeMapel;
}