#include <iostream>
using namespace std;

int main()
{
    int angka1, angka2;

    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    cout << endl
         << "Increment" << endl;

    for (int i = 0; i <= angka1; i++) // increment
    {
        cout << i << " - ";
    }

    cout << endl
         << "Decrement" << endl;

    for (int i = angka2 + 20; i > angka2; i--) // decrement
    {
        cout << i << " - ";
    }
}