#include <iostream>
using namespace std;

int main()
{
    const int jumlah = 2;

    struct rapot
    {
        char nama[5];
        int jumlah;
    };

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "Masukan nilai siswa : ";
        cin >> siswa[i].jumlah;
    }

    int i = 0;
    while (i < jumlah)
    {
        cout << "nama " << siswa[i].nama << " nilai " << siswa[i].jumlah << endl;
        i++;
    }
    return 0;
}