#include <iostream>
using namespace std;

int CariMAX(int arr[], int ukuran)
{
    int MAX = arr[0];
    for (int i = 1; i < ukuran; i++)
    {
        if (arr[i] > MAX)
        {
            MAX = arr[i];
        }
    }
    return MAX;
}

void operasiAritmatika(int arr[], int ukuran)
{
    int totalJumlah = 0;
    for (int i = 0; i < ukuran; i++)
    {
        totalJumlah += arr[i];
    }
    cout << "Total penjumlahan : " << totalJumlah << endl;

    int totalKali = 1;
    for (int i = 0; i < ukuran; i++)
    {
        totalKali *= arr[i];
    }
    cout << "Total perkalian : " << totalKali << endl;
}

int main()
{
    int ukuran = 5;
    int arr[ukuran];

    for (int i = 0; i < ukuran; i++)
    {
        cout << "Masukan nilai indeks ke - " << i << " : ";
        cin >> arr[i];
    }
    cout << endl
         << "Nilai terbesar dalam array : " << CariMAX(arr, ukuran) << endl;
    operasiAritmatika(arr, ukuran);
    return 0;
}