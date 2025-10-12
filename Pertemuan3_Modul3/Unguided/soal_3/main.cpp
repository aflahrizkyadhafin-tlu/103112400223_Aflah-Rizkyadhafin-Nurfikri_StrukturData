#include "array.h"

int main()
{
    int arrA[3][3] = {{1, 2, 3},
                      {4, 5, 6},
                      {7, 8, 9}},
        arrB[3][3] = {{10, 11, 12},
                      {13, 14, 15},
                      {16, 17, 18}},
        *point1, *point2;

    point1 = &arrA[1][0];
    point2 = &arrB[1][2];
    cout << "--------------- Awal ---------------" << endl;
    tampil_array(arrA);
    tampil_array(arrB);
    cout << "--------------- Ubah ---------------" << endl;
    tukar_isi_array(arrA, arrB);
    tampil_array(arrA);
    tampil_array(arrB);
    return 0;
}