#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama;
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m)
{
    cout << "Masukan nama mahasiswa : ";
    cin >> m.nama;
    cout << "Masukan nilai 1 : ";
    cin >> m.nilai1;
    cout << "Masukan nilai 2 : ";
    cin >> m.nilai2;
};

float rata2(mahasiswa m)
{
    return (m.nilai1 + m.nilai2) / 2;
};

int main()
{
    mahasiswa mhs;                                                   // Pemanggilan struct (ADT)
    inputMhs(mhs);                                                   // Pemanggilan prosedur
    cout << "Rata - rata nilai " << mhs.nama << " : " << rata2(mhs); // Pemanggilan fungsi
    return 0;
}