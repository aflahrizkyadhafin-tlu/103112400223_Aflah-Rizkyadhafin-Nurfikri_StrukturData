#include <iostream>
using namespace std;

int main()
{
    int angka1;

    cout << "Masukan angka 1 : ";
    cin >> angka1;

    int i = 0;
    while (i < angka1)
    {
        cout << i << " - ";
        i++; // increment
    }

    cout << endl;

    do
    {
        cout << i << " - ";
        i--; // decrement
    } while (0 < i);
}