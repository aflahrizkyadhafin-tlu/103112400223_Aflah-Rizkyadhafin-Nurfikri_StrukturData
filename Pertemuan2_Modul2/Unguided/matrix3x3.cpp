#include <iostream>
using namespace std;

void tampilkanMatriks(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << "{";
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j];
            if (j < 2)
            {
                cout << ", ";
            }
        }
        cout << "}";
        if (i < 2)
        {
            cout << ", ";
        }
        cout << endl;
    }
    cout << endl
         << endl;
}

int main()
{
    int arrA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int arrB[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}};
    int arrC[3][3] = {0};

    // Pertambahan Matriks 3x3
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "Hasil dari pertambah matriks A + matriks B : " << endl;
    tampilkanMatriks(arrC);

    // Perngurangan Matriks 3x3
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    cout << "Hasil dari pengurangan matriks A - matriks B : " << endl;
    tampilkanMatriks(arrC);

    // Perkalian matriks
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "Hasil dari perkalian matriks A * matriks B : " << endl;
    tampilkanMatriks(arrC);

    return 0;
}