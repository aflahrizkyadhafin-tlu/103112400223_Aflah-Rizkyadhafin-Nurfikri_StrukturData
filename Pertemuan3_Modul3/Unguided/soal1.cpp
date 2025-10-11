#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    int nim, uts, uas, tugas, nilaiAkhir;
};

int main()
{
    Mahasiswa daftarMahasiwa[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Masukan nama : ";
        cin >> daftarMahasiwa[i].nama;
        cout << "Masukan nim : ";
        cin >> daftarMahasiwa[i].nim;
        cout << "Masukan nilai UTS : ";
        cin >> daftarMahasiwa[i].uts;
        cout << "Masukan nilai UAS : ";
        cin >> daftarMahasiwa[i].uas;
        cout << "Masukan nilai tugas : ";
        cin >> daftarMahasiwa[i].tugas;
        daftarMahasiwa[i].nilaiAkhir = 0.3 * daftarMahasiwa[i].uts + 0.4 * daftarMahasiwa[i].uas + 0.3 * daftarMahasiwa[i].tugas;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Nama : " << daftarMahasiwa[i].nama << endl;
        cout << "NIM : " << daftarMahasiwa[i].nim << endl;
        cout << "Nilai UTS : " << daftarMahasiwa[i].uts << endl;
        cout << "Nilai UAS : " << daftarMahasiwa[i].uas << endl;
        cout << "Nilai tugas : " << daftarMahasiwa[i].tugas << endl;
        cout << "Nilai akhir : " << daftarMahasiwa[i].nilaiAkhir << endl;
    }
    return 0;
}