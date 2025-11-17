#include "StackMahasiswa.h"

bool isEmpty(StackMahasiswa StackMHS)
{
    if (StackMHS.Top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool isFull(StackMahasiswa StackMHS)
{
    if (StackMHS.Top == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void createStack(StackMahasiswa &StackMHS)
{
    StackMHS.Top = -1;
};

void Push(StackMahasiswa &StackMHS)
{
    Mahasiswa newData;
    cout << "Nama : ";
    cin >> newData.nama;
    cout << "Nim : ";
    cin >> newData.nim;
    cout << "Nilai Tugas : ";
    cin >> newData.nilaiTugas;
    cout << "Nilai UTS : ";
    cin >> newData.nilaiUTS;
    cout << "Nilai UAS : ";
    cin >> newData.nilaiUAS;
    StackMHS.Top++;
    StackMHS.dataMahasiswa[StackMHS.Top] = newData;
};

void Pop(StackMahasiswa &StackMHS)
{
    StackMHS.dataMahasiswa == nullptr;
    StackMHS.Top--;
};

void Update(StackMahasiswa &StackMHS, int posisi);

void view(StackMahasiswa StackMHS)
{
    for (int i = 0; i < MAX; i++)
    {
    }
};

void searchNilaiAkhir(StackMahasiswa StackMHS);