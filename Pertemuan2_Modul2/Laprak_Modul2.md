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

<!-- Program ini dibuat untuk melakukan proses input dan output dalam bahasa C++. Program ini membuat 2 varible (angka 1 & angka 2) dengan tipe data integer, yang selanjutnya akan diinput dengan sejumlah value. Value yang telah diinput, akan di outputkan kembali setelah dilakukan operasi pertambahan, pengurangan, perkalian, pembagian dan modulus. -->

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

<!-- Tugas guided nomor 2, membuat program yang bertujuan untuk menjalankan proses percabangan dengan C++. Program ini akan meminta input untuk 2 buah variable, untuk selanjutnya value dari kedua variable akan dibandingkan (lebih besar / lebih kecil / sama dengan / tidak sama dengan). -->

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

<!-- Pada persoalan kali ini, program yang dibuat adalah program untuk melakukan operasi perulangan. Dimana program akan meminta input <b>angka 1</b> dan <b> angka 2</b>. Nilai dari kedua variable tersebut akan dijadikan kondisi di dalam perulangan. Pada bagian output, program akan memberikan output value dari i sebanyak value pada angka satu dan value pada angka 2 + 20. -->

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

<!-- Seperti pada no. 4, program ini berfungsi untuk melakukan operasi perulangan. Namun hal yang membedakan adalah pada bagian ini, program menggunakan operasi perulangan while dan do-while. -->

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

<!-- Program ini berfungsi untuk memperkenalkan cara membuat structure pada bahasa C++. Pada program ini structure yang dibuat bernama rapot dengan properti nama bertipe data char panjang 5, dan properti jumlah bertipe data int. Di sampaikan juga cara untuk mengubah dan menampilkan isi dari sebuah struct. -->

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

<!-- Pada soal ini, diperintahkan untuk membuat sebuah program yang akan melakukan operasi pertambahan, pengurangan, perkalian, dan pembagian. Program ini akan meminta 2 buah input, untuk variable <b>angka 1</b> dan <b>angka 2</b>. Output yang dihasilkan berupa hasil dari setiap operasi yang dilakukan. -->

### 2. Berdasarkan guided pointer dan reference sebelumnya, buatlah keduanya dapat menukar nilai dari 3 variabel

```C++

```

### Output Unguided 2 :

##### Output 1

<!-- ![Screenshot Output Unguided 2_1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot2_1.png) -->

##### Output 2

<!-- ![Screenshot Output Unguided 2_2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot2_2.png) -->

<!-- Program ini berfungsi untuk mengubah input angka yang diberikan oleh user, ke dalam bentuk tulisan. Program ini membuat sebuah variable yang akan menampung sebuah angka untuk selanjutnya setiap digit angka akan dibaca oleh program. Apabila berjumlah 3 digit, maka program akan membaca sebagai ratusan, jika 2 digit, maka program akan membaca sebagai puluhan/belasan dan jika 1 digit, maka program akan membaca sebagai satuan. -->

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

<!-- Program ini berfungsi untuk memberikan output sesuai dengan format yang diberikan pada soal. Program ini menggunakan 4 perulangan yang akan mencetak value dari i, jumlah space kosong dan bintang untuk membentuk pola yang diberikan. -->

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
