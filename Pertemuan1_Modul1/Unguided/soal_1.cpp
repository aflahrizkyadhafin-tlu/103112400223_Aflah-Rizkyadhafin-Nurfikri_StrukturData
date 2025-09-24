#include <iostream>
using namespace std;

int main()
{
    float bilangan1, bilangan2;

    cout << "Masukan nilai bilangan 1 : ";
    cin >> bilangan1;
    cout << "Masukan nilai bilangan 2 : ";
    cin >> bilangan2;

    // Penjumlahan
    cout << "Hasil dari " << bilangan1 << " + " << bilangan2 << " = " << bilangan1 + bilangan2 << endl;
    // Pengurangan
    cout << "Hasil dari " << bilangan1 << " - " << bilangan2 << " = " << bilangan1 - bilangan2 << endl;
    // Perkalian
    cout << "Hasil dari " << bilangan1 << " * " << bilangan2 << " = " << bilangan1 * bilangan2 << endl;
    // Pembangian
    cout << "Hasil dari " << bilangan1 << " / " << bilangan2 << " = " << bilangan1 / bilangan2;

    return 0;
}