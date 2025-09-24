#include <iostream>
using namespace std;

int main()
{
    string angka[10] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    int bilangan, satuan, puluhan, ratusan;

    cout << "Masukan bilangan : ";
    cin >> bilangan;

    satuan = bilangan % 10;
    puluhan = (bilangan % 100) / 10;
    ratusan = bilangan / 100;

    if (bilangan >= 0 && bilangan <= 100)
    {
        if (bilangan <= 9 && bilangan >= 0)
        {
            cout << angka[satuan];
        }
        else if (bilangan >= 11 && bilangan <= 99)
        {
            if (puluhan == 1)
            {
                if (satuan == 0)
                {
                    cout << "sepuluh";
                }
                else if (satuan == 1)
                {
                    cout << "sebelas";
                }
                else
                {
                    cout << angka[satuan] + " " + "belas";
                }
            }
            else
            {
                if (satuan == 0)
                {
                    cout << angka[puluhan] + " " + "puluh";
                }
                else
                {
                    cout << angka[puluhan] + " " + "puluh" + " " + angka[satuan];
                }
            }
        }
        else
        {
            cout << "seratus";
        }
    }
    else
    {
        cout << "Bilangan harus pada rentang 0 - 100";
    }

    return 0;
}