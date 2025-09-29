#include <iostream>
using namespace std;

int cariMaksimum(int arr[], int ukuran)
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

int cariMinimum(int arr[], int ukuran)
{
    int MIN = arr[0];
    for (int i = 1; i < ukuran; i++)
    {
        if (arr[i] < MIN)
        {
            MIN = arr[i];
        }
    }
    return MIN;
}

void hitungRataRata(int arr[], int ukuran)
{
    int jumlah = 0;
    for (int i = 0; i < ukuran; i++)
    {
        jumlah += arr[i];
    }

    cout << "Rata-rata nilai array : " << jumlah / ukuran;
}

int main()
{
    int arrA[] = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55};
    int ukuran = sizeof(arrA) / sizeof(int);
    int menu;

    cout << "--- Menu Program Array ---" << endl;
    cout << "1. Tampilkan isi array" << endl;
    cout << "2. cari nilai maksimum" << endl;
    cout << "3. cari nilai minimum" << endl;
    cout << "4. Hitung nilai rata - rata" << endl;
    cout << "Pilihan menu : ";
    cin >> menu;

    switch (menu)
    {
    case 1:
        for (int i = 0; i < ukuran; i++)
        {
            cout << "Nilai indeks ke - " << i << " = " << arrA[i] << endl;
        }
        break;
    case 2:
        cout << "Nilai maksimum dari array : " << cariMaksimum(arrA, ukuran);
        break;
    case 3:
        cout << "Nilai minimum dari array : " << cariMinimum(arrA, ukuran);
        break;
    case 4:
        hitungRataRata(arrA, ukuran);
        break;
    default:
        cout << "Kode menu salah!!!";
        break;
    }

    return 0;
}