#include "array.h"

void tampil_array(int arr[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukar_isi_array(int (*arr1)[3][3], int (*arr2)[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int temp = *arr1[i][j];
            *arr1[i][j] = *arr2[i][j];
            *arr2[i][j] = temp;
        }
    }
}

void tukar_isi_variable(int *point1, int *point2)
{
    int temp;
    temp = *point1;
    *point1 = *point2;
    *point2 = temp;
}
