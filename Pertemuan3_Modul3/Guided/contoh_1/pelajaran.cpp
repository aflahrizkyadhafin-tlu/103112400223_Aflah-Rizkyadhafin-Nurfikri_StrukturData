#include "pelajaran.h"

// Implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodeMapel)
{
    pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
};

// Implementasi prosedur tampil pelajaran
void tampil_pelajaran(pelajaran pel)
{
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Kode pelajaran : " << pel.kodeMapel << endl;
};
