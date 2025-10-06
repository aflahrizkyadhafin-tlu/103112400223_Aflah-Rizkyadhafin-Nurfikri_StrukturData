#include "pelajaran.h"
#include <iostream>
using namespace std;

int main()
{
    string namaMapel = "Struktur Data", kodeMapel = "STD";
    pelajaran pel = create_pelajaran(namaMapel, kodeMapel);
    tampil_pelajaran(pel);
    return 0;
}