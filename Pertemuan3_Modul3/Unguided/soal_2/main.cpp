#include "pelajaran.h"

int main()
{
    string namapel = "Struktur Data", kodepel = "STD";
    Pelajaran pel = create_mapel(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}