<<<<<<< HEAD
# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

Stack atau Tumpukan adalah struktur data linier fundamental yang beroperasi berdasarkan prinsip LIFO (Last In, First Out), artinya elemen yang terakhir dimasukkan adalah elemen yang pertama kali dikeluarkan, mirip dengan tumpukan piring [1]. Operasi utamanya meliputi Push, yaitu menambahkan elemen baru ke bagian atas (Top), dan Pop, yaitu menghapus elemen dari bagian atas tersebut [2]. Karena hanya mengizinkan akses dan modifikasi melalui satu ujung saja, yaitu Top, Stack sangat efisien dan banyak digunakan dalam berbagai aplikasi komputasi. Penerapan utama dari Stack mencakup manajemen panggilan fungsi (Call Stack) pada sistem operasi, penanganan fitur Undo/Redo, dan evaluasi ekspresi aritmatika. Dengan demikian, Stack adalah alat penting yang menjamin urutan pemrosesan yang terstruktur dan teratur.

### A. Single Linked List<br/>

### 1. Push

### 2. Pop

#### 3. Update

#### 4. View

#### 5. Search

## Guided

### 1. Stack

#### stack.h

```h
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

#### stack.cpp

```C++

#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s)
{
    return s.top == -1;
}
bool isFull(stackTable s)
{
    return s.top == MAX - 1;
}
void createStack(stackTable &s)
{
    s.top = -1;
}
void push(stackTable &s, int angka)
{

    if (isFull(s))
    {
        cout << "Stack penuh!" << endl;
    }
    else
    {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data" << angka << "berhasil ditambahkan kedalam stack !" << endl;
    }
}

void pop(stackTable &s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        int val = s.data[s.top];
        s.top--;
        cout << "Data" << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi)
{
    if (isEmpty(s))
    {
    }
    cout << "Stack kosong!" << endl;
    return;
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    // index = top

    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i)
    {
        if (s.data[i] == data)
        {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found)
    {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

```

#### main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}

```

Kode C++ ini mengimplementasikan struktur data Stack (Tumpukan) menggunakan linked list (daftar berantai). Stack dibuat dengan fungsi seperti push (menambah elemen ke top/atas), pop (menghapus elemen dari top/atas), isEmpty, view, dan fungsi tambahan seperti update dan searchData (meskipun operasi update dan searchData jarang ada di stack murni karena stack beroperasi hanya di satu ujung, yaitu top). Program utama (main.cpp) mendemonstrasikan operasi-operasi dasar stack: membuat, menambahkan lima node, menghapus dua node, memperbarui node pada posisi tertentu (hitung dari top), dan mencari data.

## Unguided

```h
#ifndef STACK_INT
#define STACK_INT
#include <iostream>
using namespace std;

typedef int infotype;
struct Stack
{
    int info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack &S);
void balikStack(Stack &S);

// Soal 2
void pushAscending(Stack &S, infotype x);

// Soal 3
void getInputStream(Stack &S);
#endif
```

#### Doublylist.cpp

```C++
#include "stackInt.h"

void createStack(Stack &S)
{
    S.top = -1;
}

void push(Stack &S, infotype x)
{
    if (S.top < 20)
    {
        S.top++;
        S.info[S.top] = x;
    }
    else
    {
        cout << "Stack tidak memiliki ruang kosong!!!" << endl;
    }
}

infotype pop(Stack &S)
{
    infotype temp = 0;
    if (S.top > -1)
    {
        temp = S.info[S.top];
        S.info[S.top] = 0;
        S.top--;
    }
    else
    {
        cout << "Stack tidak memiliki elemen!!!" << endl;
    }

    return temp;
}

void printInfo(Stack &S)
{
    int n = S.top;

    cout << "[top] ";

    while (n > -1)
    {
        cout << S.info[n] << " ";
        n--;
    }
    cout << endl;
}

void balikStack(Stack &S)
{
    int n = S.top;
    Stack temp;
    createStack(temp);

    while (n > -1)
    {
        push(temp, S.info[n]);
        pop(S);
        n--;
    }
    S = temp;
}

// Soal 2
void pushAscending(Stack &S, infotype x)
{
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.info[S.top] > x)
    {
        infotype valueToMove = S.info[S.top];
        push(temp, valueToMove);
        pop(S);
    }

    push(S, x);

    while (temp.top != -1)
    {
        infotype valueToReturn = temp.info[temp.top];
        push(S, valueToReturn);
        pop(temp);
    }
}

// Soal 3
void getInputStream(Stack &S)
{
    char checkenter;
    while (true)
    {
        cin.get(checkenter);
        if (checkenter == '\n')
            break;
        cout << checkenter << endl;
        push(S, checkenter - '0');
    }
}
```

#### main.cpp No. 1

```C++
#include "stackInt.h"

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balikstack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

#### main.cpp No. 2

```C++
#include "stackInt.h"

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

#### main.cpp No. 3

```C++
 int main()
 {
 cout << "Hello world!" << endl;
 Stack S;
 createStack(S);
 getInputStream(S);
 printInfo(S);
 cout<<"balik stack"<<endl;
 balikStack(S);
 printInfo(S);
 return 0;
 }
```

#### Unguided 1

Program ini menguji operasi dasar Stack: push, pop, dan balikStack. Setelah beberapa kali push dan pop, Stack akan berisi elemen 9, 8, 4, 3 (dari Top ke Bottom). Fungsi balikStack kemudian akan membalik urutan elemen menjadi 3, 4, 8, 9 (dari Top ke Bottom), yang dicetak di akhir program.

### Output Unguided :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan6_Modul6/Unguided/screenshot/unguided_1.png)

#### Unguided 2

Bagian ini menguji fungsi khusus pushAscending yang memastikan elemen di dalam Stack selalu tersusun secara ascending (menaik) dari Bottom ke Top. Setiap angka yang dimasukkan akan diletakkan di posisi yang tepat; misalnya, memasukkan 2 akan memindahkan angka yang lebih besar ke Stack sementara (temp), memasukkan 2, dan kemudian mengembalikannya. Hasil akhirnya adalah Stack berisi angka-angka yang dimasukkan secara terurut menaik: 9, 8, 4, 3, 3, 2 (dari Top ke Bottom).

### Output Unguided :

##### Output 2

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan6_Modul6/Unguided/screenshot/unguided_1.png)

#### Unguided 3

Program ini menguji fungsi getInputStream yang membaca input dari stream karakter hingga tombol Enter (\n) ditekan. Setiap karakter yang dibaca diubah menjadi nilai integer (dengan mengurangi '0') dan di-push ke dalam Stack. Karena Stack adalah LIFO (Last-In, First-Out), urutan angka yang dicetak pada printInfo(S) akan terbalik dari urutan input, dan kemudian balikStack akan mengembalikan urutan tersebut.

### Output Unguided :

##### Output 3

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan6_Modul6/Unguided/screenshot/unguided_1.png)

## Kesimpulan

Laporan ini berhasil mengimplementasikan struktur data Stack (Tumpukan) yang berpegangan teguh pada prinsip LIFO (Last In, First Out). Demonstrasi kode program, baik yang menggunakan implementasi Array maupun kerangka Linked List, memvalidasi operasi dasar Push dan Pop yang hanya berpusat pada satu titik, yaitu Top. Selain itu, fungsi tambahan seperti pengurutan data (pushAscending) dan pembalikan urutan tumpukan (balikStack) berhasil diuji, menegaskan bahwa Stack adalah alat komputasi vital untuk manajemen urutan data yang terstruktur.

## Referensi

<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). PENGGUNAAN STRUKTUR DATA STACK DALAM PEMROGRAMAN C++ DENGAN PENDEKATAN ARRAY DAN LINKED LIST. JUTECH: Journal Education and Technology, 5(2), 484-498. Retrieved from http://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263.
<br>
<br>[2] Holle, K. F. H. (2022). Modul praktikum struktur data. Retrieved from https://repository.uin-malang.ac.id/15252/.
<br>
=======
# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori

Stack atau Tumpukan adalah struktur data linier fundamental yang beroperasi berdasarkan prinsip LIFO (Last In, First Out), artinya elemen yang terakhir dimasukkan adalah elemen yang pertama kali dikeluarkan, mirip dengan tumpukan piring [1]. Operasi utamanya meliputi Push, yaitu menambahkan elemen baru ke bagian atas (Top), dan Pop, yaitu menghapus elemen dari bagian atas tersebut [2]. Karena hanya mengizinkan akses dan modifikasi melalui satu ujung saja, yaitu Top, Stack sangat efisien dan banyak digunakan dalam berbagai aplikasi komputasi. Penerapan utama dari Stack mencakup manajemen panggilan fungsi (Call Stack) pada sistem operasi, penanganan fitur Undo/Redo, dan evaluasi ekspresi aritmatika. Dengan demikian, Stack adalah alat penting yang menjamin urutan pemrosesan yang terstruktur dan teratur.

### A. Single Linked List<br/>

### 1. Push

### 2. Pop

#### 3. Update

#### 4. View

#### 5. Search

## Guided

### 1. Stack

#### stack.h

```h
#ifndef STACK
#define STACK
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node
{
    int dataAngka;
    address next;
};

struct stack
{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
```

#### stack.cpp

```C++

#include "stack.h"
#include <iostream>
using namespace std;

bool isEmpty(stackTable s)
{
    return s.top == -1;
}
bool isFull(stackTable s)
{
    return s.top == MAX - 1;
}
void createStack(stackTable &s)
{
    s.top = -1;
}
void push(stackTable &s, int angka)
{

    if (isFull(s))
    {
        cout << "Stack penuh!" << endl;
    }
    else
    {
        s.top++;
        s.data[s.top] = angka;
        cout << "Data" << angka << "berhasil ditambahkan kedalam stack !" << endl;
    }
}

void pop(stackTable &s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        int val = s.data[s.top];
        s.top--;
        cout << "Data" << val << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stackTable &s, int posisi)
{
    if (isEmpty(s))
    {
    }
    cout << "Stack kosong!" << endl;
    return;
    if (posisi <= 0)
    {
        cout << "Posisi tidak valid!" << endl;
        return;
    }
    // index = top

    int idx = s.top - (posisi - 1);
    if (idx < 0 || idx > s.top)
    {
        cout << "Posisi " << posisi << " tidak valid!" << endl;
        return;
    }

    cout << "Update data posisi ke-" << posisi << endl;
    cout << "Masukkan angka : ";
    cin >> s.data[idx];
    cout << "Data berhasil diupdate!" << endl;
    cout << endl;
}

void view(stackTable s)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
    }
    else
    {
        for (int i = s.top; i >= 0; --i)
        {
            cout << s.data[i] << " ";
        }
    }
    cout << endl;
}

void searchData(stackTable s, int data)
{
    if (isEmpty(s))
    {
        cout << "Stack kosong!" << endl;
        return;
    }

    cout << "Mencari data " << data << "..." << endl;
    int posisi = 1;
    bool found = false;

    for (int i = s.top; i >= 0; --i)
    {
        if (s.data[i] == data)
        {
            cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
            cout << endl;
            found = true;
            break;
        }
        posisi++;
    }

    if (!found)
    {
        cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
        cout << endl;
    }
}

```

#### main.cpp

```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    stackTable s;
    createStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(s);
    cout << endl;

    pop(s);
    pop(s);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(s);
    cout << endl;

    // Posisi dihitung dari TOP (1-based)
    update(s, 2);
    update(s, 1);
    update(s, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(s);
    cout << endl;

    searchData(s, 4);
    searchData(s, 9);

    return 0;
}

```

Kode C++ ini mengimplementasikan struktur data Stack (Tumpukan) menggunakan linked list (daftar berantai). Stack dibuat dengan fungsi seperti push (menambah elemen ke top/atas), pop (menghapus elemen dari top/atas), isEmpty, view, dan fungsi tambahan seperti update dan searchData (meskipun operasi update dan searchData jarang ada di stack murni karena stack beroperasi hanya di satu ujung, yaitu top). Program utama (main.cpp) mendemonstrasikan operasi-operasi dasar stack: membuat, menambahkan lima node, menghapus dua node, memperbarui node pada posisi tertentu (hitung dari top), dan mencari data.

## Unguided

```h
#ifndef STACK_INT
#define STACK_INT
#include <iostream>
using namespace std;

typedef int infotype;
struct Stack
{
    int info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack &S);
void balikStack(Stack &S);

// Soal 2
void pushAscending(Stack &S, infotype x);

// Soal 3
void getInputStream(Stack &S);
#endif
```

#### Doublylist.cpp

```C++
#include "stackInt.h"

void createStack(Stack &S)
{
    S.top = -1;
}

void push(Stack &S, infotype x)
{
    if (S.top < 20)
    {
        S.top++;
        S.info[S.top] = x;
    }
    else
    {
        cout << "Stack tidak memiliki ruang kosong!!!" << endl;
    }
}

infotype pop(Stack &S)
{
    infotype temp = 0;
    if (S.top > -1)
    {
        temp = S.info[S.top];
        S.info[S.top] = 0;
        S.top--;
    }
    else
    {
        cout << "Stack tidak memiliki elemen!!!" << endl;
    }

    return temp;
}

void printInfo(Stack &S)
{
    int n = S.top;

    cout << "[top] ";

    while (n > -1)
    {
        cout << S.info[n] << " ";
        n--;
    }
    cout << endl;
}

void balikStack(Stack &S)
{
    int n = S.top;
    Stack temp;
    createStack(temp);

    while (n > -1)
    {
        push(temp, S.info[n]);
        pop(S);
        n--;
    }
    S = temp;
}

// Soal 2
void pushAscending(Stack &S, infotype x)
{
    Stack temp;
    createStack(temp);

    while (S.top != -1 && S.info[S.top] > x)
    {
        infotype valueToMove = S.info[S.top];
        push(temp, valueToMove);
        pop(S);
    }

    push(S, x);

    while (temp.top != -1)
    {
        infotype valueToReturn = temp.info[temp.top];
        push(S, valueToReturn);
        pop(temp);
    }
}

// Soal 3
void getInputStream(Stack &S)
{
    char checkenter;
    while (true)
    {
        cin.get(checkenter);
        if (checkenter == '\n')
            break;
        cout << checkenter << endl;
        push(S, checkenter - '0');
    }
}
```

#### main.cpp No. 1

```C++
#include "stackInt.h"

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);
    printInfo(S);
    cout << "balikstack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

#### main.cpp No. 2

```C++
#include "stackInt.h"

int main()
{
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

#### main.cpp No. 3

```C++
 int main()
 {
 cout << "Hello world!" << endl;
 Stack S;
 createStack(S);
 getInputStream(S);
 printInfo(S);
 cout<<"balik stack"<<endl;
 balikStack(S);
 printInfo(S);
 return 0;
 }
```

#### Unguided 1

Program ini menguji operasi dasar Stack: push, pop, dan balikStack. Setelah beberapa kali push dan pop, Stack akan berisi elemen 9, 8, 4, 3 (dari Top ke Bottom). Fungsi balikStack kemudian akan membalik urutan elemen menjadi 3, 4, 8, 9 (dari Top ke Bottom), yang dicetak di akhir program.

### Output Unguided :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan7_Modul7/Unguided/screenshot/unguided_3.png)

#### Unguided 2

Bagian ini menguji fungsi khusus pushAscending yang memastikan elemen di dalam Stack selalu tersusun secara ascending (menaik) dari Bottom ke Top. Setiap angka yang dimasukkan akan diletakkan di posisi yang tepat; misalnya, memasukkan 2 akan memindahkan angka yang lebih besar ke Stack sementara (temp), memasukkan 2, dan kemudian mengembalikannya. Hasil akhirnya adalah Stack berisi angka-angka yang dimasukkan secara terurut menaik: 9, 8, 4, 3, 3, 2 (dari Top ke Bottom).

### Output Unguided :

##### Output 2

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan7_Modul7/Unguided/screenshot/unguided_2.png)

#### Unguided 3

Program ini menguji fungsi getInputStream yang membaca input dari stream karakter hingga tombol Enter (\n) ditekan. Setiap karakter yang dibaca diubah menjadi nilai integer (dengan mengurangi '0') dan di-push ke dalam Stack. Karena Stack adalah LIFO (Last-In, First-Out), urutan angka yang dicetak pada printInfo(S) akan terbalik dari urutan input, dan kemudian balikStack akan mengembalikan urutan tersebut.

### Output Unguided :

##### Output 3

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan7_Modul7/Unguided/screenshot/unguided_3.png)

## Kesimpulan

Laporan ini berhasil mengimplementasikan struktur data Stack (Tumpukan) yang berpegangan teguh pada prinsip LIFO (Last In, First Out). Demonstrasi kode program, baik yang menggunakan implementasi Array maupun kerangka Linked List, memvalidasi operasi dasar Push dan Pop yang hanya berpusat pada satu titik, yaitu Top. Selain itu, fungsi tambahan seperti pengurutan data (pushAscending) dan pembalikan urutan tumpukan (balikStack) berhasil diuji, menegaskan bahwa Stack adalah alat komputasi vital untuk manajemen urutan data yang terstruktur.

## Referensi

<br>[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). PENGGUNAAN STRUKTUR DATA STACK DALAM PEMROGRAMAN C++ DENGAN PENDEKATAN ARRAY DAN LINKED LIST. JUTECH: Journal Education and Technology, 5(2), 484-498. Retrieved from http://jurnal.stkippersada.ac.id/jurnal/index.php/jutech/article/view/4263.
<br>
<br>[2] Holle, K. F. H. (2022). Modul praktikum struktur data. Retrieved from https://repository.uin-malang.ac.id/15252/.
<br>
>>>>>>> 1527520158dc0f56fc020f83297f41843fa322e2
