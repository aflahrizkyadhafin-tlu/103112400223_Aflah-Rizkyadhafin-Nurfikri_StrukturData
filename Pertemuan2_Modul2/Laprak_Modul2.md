# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

<!-- C++ merupakan bahasa pemrograman yang dikembangkan berdasarkan bahasa C. Bahasa C++ sudah digunakan oleh berbagai aplikasi besar, seperti Google Earth dan Skype [1]. Pada bahasa C++, terdapat berbagai perintah yang bisa dilakukan, seperti membuat variable, melakukan operasi serta membuat function. -->

### A. Pengenalan Struktur Code C++<br/>

<!-- Materi ini menjelaskan syntax dasar dan operasi yang bisa dilakukan pada bahasa pemrograman C++. Pada bagian ini dijelaskan cara menuliskan struktur kode C++, tipe data, operasi serta cara melakukan percabangan dan pengulangan di C++. -->

#### 1. Array

#### 2. Pointer

#### 3. Fungsi

#### 4. Prosedur

#### 5. Parameter Fungsi

## Guided

### 1. Array 1 Dimensi

```C++
#include <iostream>
using namespace std;

int main()
{
    int arr[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Masukan value indeks ke - " << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while (j < 5)
    {
        cout << "Isi indeks ke - " << j << " : " << arr[j] << endl;
        j++;
    }
    return 0;
}
```

Program ini dibuat untuk menjelaskan bagaimana cara membuat dan menggunakan value yang tersimpan pada array 1 dimensi.

### 2. Array 2 Dimensi

```C++
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
```

Program ini dibuat untuk menjelaskan bagaimana cara membuat dan menggunakan value yang tersimpan pada array 2 dimensi. Pada program ini juga diberlakukan operasi penjumlahan dan perkalian matriks.

### 3. Fungsi

```C++
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
```

Syntax ini menjelaskan bagaimana cara membuat dan memanggil function dan prosedur pada bahasa pemrograman C++. Pada setiap fungsi dan prosedur membutuhkan parameter untuk memenuhi aksi yang ada di dalamnya. Fungsi CariMAX akan mengembalikan nilai dengan tipe data integer sedangkan prosedur tidak akan mengembalikan nilai apapun.

### 4. Pointer

```C++
#include <iostream>
using namespace std;

void tukar(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 20, b = 30;
    int *ptr;

    ptr = &a;

    cout << "Value of a : " << a << endl;
    cout << "Address of a : " << &a << endl;
    cout << "Value stored int ptr (address of a) : " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    tukar(&a, &b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;
    return 0;
}
```

Program ini menjelaskan tentang cara penggunaan pointer baik untuk menyimpan address suatu variable maupun untuk penggunaannya di dalam sebuah fungsi. Pointer berfungsi untuk menyimpan sebuah address dari suatu variable. Ketika pointer di output tanpa menggunakan tanda "_" maka nilai yang dioutput merupakan address yang tersimpan. Namun apabila symbol "_" digunakan maka nilai dari address yang tersimpan akan dioutput.

### 5. Reference

```C++
#include <iostream>
using namespace std;

void tukar(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 20, b = 30;
    int &ref = a;

    ref = a;

    cout << "Value of a : " << a << endl;
    cout << "Address of a : " << &a << endl;
    cout << "Value stored int ref (address of a) : " << ref << endl;
    cout << "Address of ref : " << &ref << endl;

    ref = 50;
    cout << "\nSetelah ref = 50" << endl;
    cout << "Nilai a : " << a << endl;
    cout << "Nilai ref : " << ref << endl;

    tukar(a, b);
    cout << "After swapping, value of a = " << a << " and b = " << b << endl;
    return 0;
}
```

Program ini berfungsi untuk menjelaskan bagaimana cara menggunakan suatu reference di C++. Program ini menggunakan sebuah fungsi untuk menerapkan cara penggunaan sebuah reference. Perbedaan dengan pointer ialah, untuk reference kita hanya perlu mengirimkan langsung address ke parameter dari sebuah fungsi.

## Unguided

### 1. Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3

```C++
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
```

### Output Unguided 1 :

##### Output 1

<!-- ![Screenshot Output Unguided 1_1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot1_1.png) -->

##### Output 2

<!-- ![Screenshot Output Unguided 1_2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot1_2.png) -->

Program ini dibuat untuk menjelaskan bagaimana cara membuat dan menggunakan value yang tersimpan pada array 3x3. Pada program ini juga diberlakukan operasi penjumlahan, pengurangan dan perkalian matriks.

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++
#include <iostream>
using namespace std;

void tukarNilaiPointer(int *a, int *b, int *c)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = *c;
    *c = temp;
}

void tukarNilaiReference(int &a, int &b, int &c)
{
    int temp;
    temp = a;
    a = b;
    b = c;
    c = temp;
}

int main()
{
    int a = 30, b = 15, c = 20;

    // Menukar nilai a dengan b
    tukarNilaiPointer(&a, &b, &c);
    cout << "Hasil pertukaran a, b dan c dengan pointer" << endl;
    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;
    cout << "Nilai c = " << c << endl
         << endl;

    // Menukar nilai b dengan c
    tukarNilaiReference(a, b, c);
    cout << "Hasil pertukaran a, b dan c dengan reference" << endl;
    cout << "Nilai a = " << a << endl;
    cout << "Nilai b = " << b << endl;
    cout << "Nilai c = " << c << endl;

    return 0;
}

```

### Output Unguided 2 :

##### Output 1

<!-- ![Screenshot Output Unguided 2_1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot2_1.png) -->

##### Output 2

<!-- ![Screenshot Output Unguided 2_2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot2_2.png) -->

Program ini berfungsi untuk menukar nilai dari varibel a, b dan c, menggunakan metode pointer dan referensi. Untuk percobaan pertama program akan menukar nilai <b>a</b> dengan <b>b</b>, nilai <b>b</b> dengan <b>c</b> dan nilai <b>c</b> dengan <b>a</b> menggunakan prosedur tukaiNilaiPointer, sedangkan pada percobaan kedua menggunakan prosedur tukarNilaiReference.

### 3. Diketahui sebuah array 1 dimensi sebagai berikut :

### arrA = {11, 8, 5, 7, 12, 26, 3, 54, 33, 55}

### Buatlah program yang dapat mencari nilai minimum, maksimum, dan rata – rata dari array tersebut! Gunakan function cariMinimum() untuk mencari nilai minimum dan function cariMaksimum() untuk mencari nilai maksimum, serta gunakan prosedur hitungRataRata() untuk menghitung nilai rata – rata! Buat program menggunakan menu switch-case

```C++
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
```

### Output Unguided 3 :

##### Output 1

<!-- ![Screenshot Output Unguided 3_1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot3_1.png) -->

##### Output 2

<!-- ![Screenshot Output Unguided 3_2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot3_2.png) -->

Program ini memiliki fungsi untuk menampilkan nilai, mencari nilai maksimum, minimum dan rata-rata dari suatu array. Program ini menggunakan 2 fungsi (cariMaksimum dan cari Minimum) yang mengembalikan nilai dengan tipe data integer, serta menggunakan 1 prosedur (hitungRataRata).

## Kesimpulan

<!-- Pada bagian modul 1, diberikan pengetahuan dasar terkait bahasa pemrograman C++. Materi yang diberikan diantaranya :

<ol>
    <li>Tipe data</li>
    <li>Operasi Aritmatika</li>
    <li>Operasi Logika</li>
    <li>Percabangan</li>
    <li>Perulangan</li>
</ol> -->

## Referensi

<!-- <br>[1] Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Umsida Press, 1-146. Diakses pada 25 September 2025 melalui https://press.umsida.ac.id/index.php/umsidapress/article/view/978-623-6833-67-4/759.
<br> -->
