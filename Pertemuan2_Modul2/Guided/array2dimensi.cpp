#include <iostream>
using namespace std;

void tampilkanMatriks(int arr[2][2])
{
    for (int i = 0; i < 2; i++)
    {
        cout << "{";
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << ", ";
        }
        cout << "},";
    }
    cout << endl;
}

int main()
{
    int arrA[2][2] = {{1, 2},
                      {3, 4}};
    int arrB[2][2] = {{2, 3},
                      {4, 5}};
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    // Penjumlahan Matriks
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil penjumlahan : ";
    tampilkanMatriks(arrC);

    // Perkalian matriks
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "Hasil perkalian : ";
    tampilkanMatriks(arrD);

    return 0;
}