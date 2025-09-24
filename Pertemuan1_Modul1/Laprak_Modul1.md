# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

C++ merupakan bahasa pemrograman yang dikembangkan berdasarkan bahasa C. Bahasa C++ sudah digunakan oleh berbagai aplikasi besar, seperti Google Earth dan Skype [1]. Pada bahasa C++, terdapat berbagai perintah yang bisa dilakukan, seperti membuat variable, melakukan operasi serta membuat function.

### A. Pengenalan Struktur Code C++<br/>

Materi ini menjelaskan syntax dasar dan operasi yang bisa dilakukan pada bahasa pemrograman C++. Pada bagian ini dijelaskan cara menuliskan struktur kode C++, tipe data, operasi serta cara melakukan percabangan dan pengulangan di C++.

#### 1. Struktur Program C++

#### 2. Pengenal (Identifier)

#### 3. Tipe Data

#### 4. Variable & Konstanta

#### 5. Input/Output

#### 6. Operator

#### 7. Percabangan

#### 8. Perulangan

#### 9. Struct

## Guided

### 1. Input Output

```C++
#include <iostream>
using namespace std;

int main()
{
    int angka1, angka2;

    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    // penjumlahan
    cout << "Penjumlahan : " << angka1 + angka2 << endl;
    // pengurangan
    cout << "Pengurangan : " << angka1 - angka2 << endl;
    // perkalian
    cout << "Perkalian : " << angka1 * angka2 << endl;
    // pembagian
    cout << "Pembagian : " << angka1 / angka2 << endl;
    // modulus
    cout << "Modulus : " << angka1 % angka2;
    return 0;
}
```

Program ini dibuat untuk melakukan proses input dan output dalam bahasa C++. Program ini membuat 2 varible (angka 1 & angka 2) dengan tipe data integer, yang selanjutnya akan diinput dengan sejumlah value. Value yang telah diinput, akan di outputkan kembali setelah dilakukan operasi pertambahan, pengurangan, perkalian, pembagian dan modulus.

### 2. Percabangan

```C++
#include <iostream>
using namespace std;

int main()
{
    int angka1, angka2;

    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    if (angka1 > angka2)
    {
        cout << angka1 << " Lebih besar dari " << angka2 << endl;
    }
    else if (angka1 == angka2)
    {
        cout << angka1 << " Sama dengan " << angka2 << endl;
    }
    else if (angka1 < angka2)
    {
        cout << angka1 << " Lebih kecil dari " << angka2 << endl;
    }

    if (angka1 != angka2)
    {
        cout << angka1 << " Tidak sama dengan " << angka2;
    }
}
```

Tugas guided nomor 2, membuat program yang bertujuan untuk menjalankan proses percabangan dengan C++. Program ini akan meminta input untuk 2 buah variable, untuk selanjutnya value dari kedua variable akan dibandingkan (lebih besar / lebih kecil / sama dengan / tidak sama dengan).

### 3. Perulangan (For-Loop)

```C++
#include <iostream>
using namespace std;

int main()
{
    int angka1, angka2;

    cout << "Masukan angka 1 : ";
    cin >> angka1;
    cout << "Masukan angka 2 : ";
    cin >> angka2;

    cout << endl
         << "Increment" << endl;

    for (int i = 0; i <= angka1; i++) // increment
    {
        cout << i << " - ";
    }

    cout << endl
         << "Decrement" << endl;

    for (int i = angka2 + 20; i > angka2; i--) // decrement
    {
        cout << i << " - ";
    }
}
```

Pada persoalan kali ini, program yang dibuat adalah program untuk melakukan operasi perulangan. Dimana program akan meminta input <b>angka 1</b> dan <b> angka 2</b>. Nilai dari kedua variable tersebut akan dijadikan kondisi di dalam perulangan. Pada bagian output, program akan memberikan output value dari i sebanyak value pada angka satu dan value pada angka 2 + 20.

### 4. Perulangan (While & Do-While)

```C++
#include <iostream>
using namespace std;

int main()
{
    int angka1;

    cout << "Masukan angka 1 : ";
    cin >> angka1;

    int i = 0;
    while (i < angka1)
    {
        cout << i << " - ";
        i++; // increment
    }

    cout << endl;

    do
    {
        cout << i << " - ";
        i--; // decrement
    } while (0 < i);
}
```

Seperti pada no. 4, program ini berfungsi untuk melakukan operasi perulangan. Namun hal yang membedakan adalah pada bagian ini, program menggunakan operasi perulangan while dan do-while.

### 5. Struct

```C++
#include <iostream>
using namespace std;

int main()
{
    const int jumlah = 2;

    struct rapot
    {
        char nama[5];
        int jumlah;
    };

    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukan nama siswa : ";
        cin >> siswa[i].nama;
        cout << "Masukan nilai siswa : ";
        cin >> siswa[i].jumlah;
    }

    int i = 0;
    while (i < jumlah)
    {
        cout << "nama " << siswa[i].nama << " nilai " << siswa[i].jumlah << endl;
        i++;
    }
    return 0;
}
```

Program ini berfungsi untuk memperkenalkan cara membuat structure pada bahasa C++. Pada program ini structure yang dibuat bernama rapot dengan properti nama bertipe data char panjang 5, dan properti jumlah bertipe data int. Di sampaikan juga cara untuk mengubah dan menampilkan isi dari sebuah struct.

## Unguided

### 1. Buatlah program yang menerima input-an dua buah bilangan bertipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembahian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main()
{
    float bilangan1, bilangan2;

    cout << "Masukan nilai bilangan 1 : ";
    cin >> bilangan1;
    cout << "Masukan nilai bilangan 2 : ";
    cin >> bilangan2;

    // Penjumlahan
    cout << "Hasil dari " << bilangan1 << " + " << bilangan2 << " = " << bilangan1 + bilangan2 << endl;
    // Pengurangan
    cout << "Hasil dari " << bilangan1 << " - " << bilangan2 << " = " << bilangan1 - bilangan2 << endl;
    // Perkalian
    cout << "Hasil dari " << bilangan1 << " * " << bilangan2 << " = " << bilangan1 * bilangan2 << endl;
    // Pembangian
    cout << "Hasil dari " << bilangan1 << " / " << bilangan2 << " = " << bilangan1 / bilangan2;

    return 0;
}
```

### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot1_1.png)

##### Output 2

![Screenshot Output Unguided 1_2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot1_2.png)

Pada soal ini, diperintahkan untuk membuat sebuah program yang akan melakukan operasi pertambahan, pengurangan, perkalian, dan pembagian. Program ini akan meminta 2 buah input, untuk variable <b>angka 1</b> dan <b>angka 2</b>. Output yang dihasilkan berupa hasil dari setiap operasi yang dilakukan.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di-input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

int main()
{
    string angka[10] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan"};
    int bilangan, satuan, puluhan, ratusan;

    cout << "Masukan bilangan : ";
    cin >> bilangan;

    satuan = bilangan % 10;
    puluhan = (bilangan % 100) / 10;
    ratusan = bilangan / 100;

    if (bilangan >= 0 && bilangan <= 100)
    {
        if (bilangan <= 9 && bilangan >= 0)
        {
            cout << angka[satuan];
        }
        else if (bilangan >= 11 && bilangan <= 99)
        {
            if (puluhan == 1)
            {
                if (satuan == 0)
                {
                    cout << "sepuluh";
                }
                else if (satuan == 1)
                {
                    cout << "sebelas";
                }
                else
                {
                    cout << angka[satuan] + " " + "belas";
                }
            }
            else
            {
                if (satuan == 0)
                {
                    cout << angka[puluhan] + " " + "puluh";
                }
                else
                {
                    cout << angka[puluhan] + " " + "puluh" + " " + angka[satuan];
                }
            }
        }
        else
        {
            cout << "seratus";
        }
    }
    else
    {
        cout << "Bilangan harus pada rentang 0 - 100";
    }

    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2_1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot2_1.png)

##### Output 2

![Screenshot Output Unguided 2_2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot2_2.png)

Program ini berfungsi untuk mengubah input angka yang diberikan oleh user, ke dalam bentuk tulisan. Program ini membuat sebuah variable yang akan menampung sebuah angka untuk selanjutnya setiap digit angka akan dibaca oleh program. Apabila berjumlah 3 digit, maka program akan membaca sebagai ratusan, jika 2 digit, maka program akan membaca sebagai puluhan/belasan dan jika 1 digit, maka program akan membaca sebagai satuan.

### 3. Buatlah program yang dapat memberikan input dan output sbb.

```C++
#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Input : ";
    cin >> n;

    for (int j = n; 0 <= j; j--)
    {
        for (int h = 0; h < n - j; h++)
        {
            cout << "  ";
        }
        for (int i = j; 0 < i; i--)
        {
            cout << i << " ";
        }
        cout << "* ";
        for (int i = 1; i <= j; i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3_1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot3_1.png)

##### Output 2

![Screenshot Output Unguided 3_2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan1_Modul1/Unguided/Screenshot/Screenshot3_2.png)

Program ini berfungsi untuk memberikan output sesuai dengan format yang diberikan pada soal. Program ini menggunakan 4 perulangan yang akan mencetak value dari i, jumlah space kosong dan bintang untuk membentuk pola yang diberikan.

## Kesimpulan

Pada bagian modul 1, diberikan pengetahuan dasar terkait bahasa pemrograman C++. Materi yang diberikan diantaranya :

<ol>
    <li>Tipe data</li>
    <li>Operasi Aritmatika</li>
    <li>Operasi Logika</li>
    <li>Percabangan</li>
    <li>Perulangan</li>
</ol>

## Referensi

<br>[1] Indahyanti, U., & Rahmawati, Y. (2020). Buku Ajar Algoritma Dan Pemrograman Dalam Bahasa C++. Umsida Press, 1-146. Diakses pada 25 September 2025 melalui https://press.umsida.ac.id/index.php/umsidapress/article/view/978-623-6833-67-4/759.
<br>
