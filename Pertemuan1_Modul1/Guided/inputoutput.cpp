#include <iostream>
using namespace std;

int main()
{
    int angka1, angka2;

    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    // penjumlahan
    cout << "Penjumlahan : " << angka1 + angka2 << endl;
    // pengurangan
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    // perkalian
    cout << "Perkalian : " << angka1 * angka2 << endl;
    // pembagian
    cout << "Pembagian : " << angka1 / angka2 << endl;
    // modulus
    cout << "Modulus : " << angka1 % angka2;
    return 0;
}