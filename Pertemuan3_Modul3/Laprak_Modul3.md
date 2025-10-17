# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

Tipe Data Abstrak (ADT), digunakan dengan tujuan untuk (mespesifikasi) sebuah sistem dengan membagi data yang digunakan secara abstrak melalui contructor dan operasi yang dijelaskan oleh directed equations yang beroperasi pada ekspresi yang dibangun oleh contructor tersebut [1]. Tipe Data Abstrak dibuat agar memiliki perilaku seperti built-in type atau tipe bawaan dari bahasa pemrograman, yaitu ketika kita akan menggunakan tipe data tersebut, kita hanya perlu memanggil operasinya tanpa tahu bagaimana tipe data didefinisikan atau disimpan di dalam memori [2].

### A. Pengenalan Abstract Data Type<br/>

#### 1. Struct

#### 2. Implementasi ADT (2 modul utama + 1 modul interface)

## Guided

### 1. Struct

```C++
#include <iostream>
using namespace std;

struct mahasiswa
{
    string nama;
    int nilai1, nilai2;
};

void inputMhs(mahasiswa &m)
{
    cout << "Masukan nama mahasiswa : ";
    cin >> m.nama;
    cout << "Masukan nilai 1 : ";
    cin >> m.nilai1;
    cout << "Masukan nilai 2 : ";
    cin >> m.nilai2;
};

float rata2(mahasiswa m)
{
    return (m.nilai1 + m.nilai2) / 2;
};

int main()
{
    mahasiswa mhs;                                                   // Pemanggilan struct (ADT)
    inputMhs(mhs);                                                   // Pemanggilan prosedur
    cout << "Rata - rata nilai " << mhs.nama << " : " << rata2(mhs); // Pemanggilan fungsi
    return 0;
}
```

Program ini dibuat untuk menjelaskan bagaimana cara membuat struct beserta cara menggunakan properti yang berada di dalamnya.

### 2. Abstract Data Type

#### pelajaran.h

```h
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <iostream>
using namespace std;

// Deklarasi ADT pelajaran
struct pelajaran
{
    string namaMapel, kodeMapel;
};

// Function membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodeMapel);

// Prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
```

#### pelajaran.cpp

```C++
#include "pelajaran.h"

// Implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodeMapel)
{
    pelajaran pel;
    pel.namaMapel = namaMapel;
    pel.kodeMapel = kodeMapel;
    return pel;
};

// Implementasi prosedur tampil pelajaran
void tampil_pelajaran(pelajaran pel)
{
    cout << "Nama pelajaran : " << pel.namaMapel << endl;
    cout << "Kode pelajaran : " << pel.kodeMapel << endl;
};
```

#### main.cpp

```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

int main()
{
    string namaMapel = "Struktur Data", kodeMapel = "STD";
    pelajaran pel = create_pelajaran(namaMapel, kodeMapel);
    tampil_pelajaran(pel);
    return 0;
}
```

Program ini dibuat untuk menunjukan penggunaan <b>Abstract Data Type</b> pada C++. Program terdiri dari 3 file, file pelajaran.h, pelajaran.cpp dan main.cpp. File pelajaran.h merupakan file yang berfungsi untuk mendefinisikan setiap struct dan fungsi/prosedur yang akan digunakan. File pelajaran.cpp digunakan untuk membuat aksi dari setipa fungsi/prosedur yang telah di definisikan di file header. File main.cpp merupakan file yang menyimpan fungsi utama program dan pemanggilan fungsi/prosedur lain yang sudah dibuat.

## Unguided

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus 0.3 x uts + 0.4 x uas + 0.3 x tugas.

```C++
#include <iostream>
using namespace std;

struct Mahasiswa
{
    string nama;
    int nim, uts, uas, tugas, nilaiAkhir;
};

int main()
{
    Mahasiswa daftarMahasiwa[10];

    for (int i = 0; i < 10; i++)
    {
        cout << "Masukan nama : ";
        cin >> daftarMahasiwa[i].nama;
        cout << "Masukan nim : ";
        cin >> daftarMahasiwa[i].nim;
        cout << "Masukan nilai UTS : ";
        cin >> daftarMahasiwa[i].uts;
        cout << "Masukan nilai UAS : ";
        cin >> daftarMahasiwa[i].uas;
        cout << "Masukan nilai tugas : ";
        cin >> daftarMahasiwa[i].tugas;
        daftarMahasiwa[i].nilaiAkhir = 0.3 * daftarMahasiwa[i].uts + 0.4 * daftarMahasiwa[i].uas + 0.3 * daftarMahasiwa[i].tugas;
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Nama : " << daftarMahasiwa[i].nama << endl;
        cout << "NIM : " << daftarMahasiwa[i].nim << endl;
        cout << "Nilai UTS : " << daftarMahasiwa[i].uts << endl;
        cout << "Nilai UAS : " << daftarMahasiwa[i].uas << endl;
        cout << "Nilai tugas : " << daftarMahasiwa[i].tugas << endl;
        cout << "Nilai akhir : " << daftarMahasiwa[i].nilaiAkhir << endl;
    }
    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan3_Modul3/Unguided/screenshot/screenshot_1.png)

Program ini bertujuan untuk menyimpan 10 data mahasiswa ke dalam sebuah array. Setiap data mahasiswa merupakan sebuah struct yang menyimpan properti nama, nim, uts, uas, tugas dan nilai akhir.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":

```h
Type pelajaran <
    namaMapel string
    kodeMapel: string
>
function create_pelajaran ( namapel : string, kodepel string ) → pelajaran
procedure tampil_pelajaran( input pel : pelajaran )
```

### Buat implementasi ADT pelajaran pada file "pelajaran.cpp"

### Cobalah hasil implementasi ADT pada file "main.cpp"

```C++
using namespace std;
int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

#### Jawaban

#### pelajaran.h

```h
#ifndef Pelajaran_h
#define Pelajaran_h
#include <iostream>
using namespace std;

struct Pelajaran
{
    string namaMapel, kodeMapel;
};

Pelajaran create_mapel(string namapel, string kodepel);
void tampil_pelajaran(Pelajaran pel);

#endif
```

#### pelajaran.cpp

```C++
#include "pelajaran.h"

Pelajaran create_mapel(string namapel, string kodepel)
{
    Pelajaran pel;
    pel.namaMapel = namapel;
    pel.kodeMapel = kodepel;
    return pel;
}

void tampil_pelajaran(Pelajaran pel)
{
    cout << "Nama pelajaran : " << pel.namaMapel << endl
         << "Nama pelajaran : " << pel.kodeMapel;
}
```

#### main.cpp

```C++
#include "pelajaran.h"

int main()
{
    string namapel = "Struktur Data", kodepel = "STD";
    Pelajaran pel = create_mapel(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan3_Modul3/Unguided/screenshot/screenshot_2.png)

Program ini merupakan implementasi dari materi ADT. Program ini membagi program ke dalam 2 modul (pelajaran.h dan pelajaran.cpp) dan 1 modul interface (main.cpp). Seluruh prosedur yang akan digunakan ditulis terlebih dahulu pada file pelajaran.h lalu diimplementasikan pada file pelajaran.cpp. Untuk pemanggilan setiap prosedur, dilakukan di file main.cpp. Program ini bertujuan untuk membuat sebuah varibel dengan tipe data pelajaran, yang kemudian akan diisi value dan diprint menggunakan prosedur.

### 3. Buatlah program dengan ketentuan :

### - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer

### - fungsi/prosedur yang menampilkan isi sebuah array integer 2D

### - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu

### - fungsi/prosedur yang akan menukarkan isi dari variable yang ditujuk oleh 2 buah pointer

#### array.h

```h
#ifndef Array_h
#define Array_h
#include <iostream>
using namespace std;

void tampil_array(int arr[3][3]);
void tukar_isi_array(int (&arr1)[3][3], int (&arr2)[3][3]);
void tukar_isi_variable(int *point1, int *point2);

#endif
```

#### array.cpp

```C++
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
    cout << endl;
}

void tukar_isi_array(int (&arr1)[3][3], int (&arr2)[3][3])
{
    int temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp = arr1[j][i];
            arr1[j][i] = arr2[i][j];
            arr2[i][j] = temp;
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

```

#### main.cpp

```C++
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
    cout << "--------------- Tukar isi array ---------------" << endl;
    tukar_isi_array(arrA, arrB);
    tampil_array(arrA);
    tampil_array(arrB);
    cout << "--------------- Tukar isi variable ---------------" << endl;
    tukar_isi_variable(point1, point2);
    tampil_array(arrA);
    tampil_array(arrB);
    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan3_Modul3/Unguided/screenshot/screenshot_3.png)

Program ini memiliki 3 prosedur utama, <b>tampil_array</b>,<b>tukar_isi_array</b> dan <b>tukar_isi_variable</b>. Prosedur <b>tampil_array</b> berfungsi untuk menampilkan setiap isi dari array yang diberikan. Lalu, prosedur <b>tukar_isi_array</b> berfungsi untuk menukar isi dari array pertama dan array kedua. Terakhir prosedur <b>tukar_isi_variable</b> berfungsi untuk menukar isi dari variabel yang ditujuk oleh dua buah pointer.

## Kesimpulan

Kesimpulan dari materi pertemuan kali ini, materi ini mengajarkan bagaimana penggunaan _Abstract Data Type_ (ADT). Dengan menggunakan ADT, program yang dibuat bisa lebih terorganisir dan setiap fungsi/prosedur yang akan dipakai akan digunakan akan lebih mudah dikenali.

## Referensi

<br>[1] Jouannaud, J. P., & Okada, M. (1997). Abstract data type systems. Theoretical computer science, 173(2), 349-391. Diakses pada 10 Oktober 2025 melalui https://www.sciencedirect.com/science/article/pii/S0304397596001612.
<br>
<br>[2] Liskov, B., & Zilles, S. (1974). Programming with abstract data types. ACM Sigplan Notices, 9(4), 50-59. Diakses pada 10 Oktober 2025 melalui https://dl.acm.org/doi/abs/10.1145/942572.807045.
<br>
