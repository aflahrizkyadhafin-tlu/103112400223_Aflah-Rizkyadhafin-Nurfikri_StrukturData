#include "graph.h"

int main()
{
    GraphKota daftarKota;
    createGraph(daftarKota);

    adrKota Bogor, Bekasi, Jakarta, Depok, Tangerang;
    Bogor = alokasiNode("Bogor");
    Bekasi = alokasiNode("Bekasi");
    Jakarta = alokasiNode("Jakarta");
    Depok = alokasiNode("Depok");
    Tangerang = alokasiNode("Tangerang");

    insertNode(daftarKota, Bogor);
    insertNode(daftarKota, Bekasi);
    insertNode(daftarKota, Jakarta);
    insertNode(daftarKota, Depok);
    insertNode(daftarKota, Tangerang);

    connectNode(Bogor, Bekasi, 60);
    connectNode(Bogor, Jakarta, 42);
    printGraph(daftarKota);
    return 0;
}