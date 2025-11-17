#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H
#define Nil NULL
#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama, nim;
    float nilaiTugas, nilaiUTS, nilaiUAS;
};

const int MAX = 6;
struct StackMahasiswa
{
    Mahasiswa dataMahasiswa[MAX];
    int Top;
};

bool isEmpty(StackMahasiswa StackMHS);
bool isFull(StackMahasiswa StackMHS);
void createStack(StackMahasiswa &StackMHS);
void Push(StackMahasiswa &StackMHS);
void Pop(StackMahasiswa &StackMHS);
void Update(StackMahasiswa &StackMHS, int posisi);
void view(StackMahasiswa StackMHS);
void searchNilaiAkhir(StackMahasiswa StackMHS);

#endif