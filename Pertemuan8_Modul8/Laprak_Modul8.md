# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>

<p align="center">Aflah Rizkyadhafin Nurfikri - 103112400223</p>

## Dasar Teori


Dalam konteks pemrograman, Queue atau antrean merupakan salah satu jenis struktur data non-primitif bertipe data abstrak (Abstract Data Type/ADT) yang dirancang untuk menyimpan sekumpulan elemen data. Struktur data ini dimodelkan berdasarkan analogi antrean di dunia nyata, dan beroperasi menggunakan prinsip fundamental FIFO (First In First Out). Prinsip FIFO menyatakan bahwa elemen data yang pertama kali dimasukkan ke dalam antrean (enqueue) akan menjadi elemen yang pertama kali dikeluarkan (dequeue). Dalam implementasinya, queue dapat disajikan menggunakan struktur data dasar seperti array maupun linked list [1].

Operasi dasar yang esensial pada queue mencakup Enqueue, yaitu penambahan elemen baru yang selalu dilakukan di ujung belakang (rear atau tail) antrean, dan Dequeue, yaitu penghapusan atau pengambilan elemen yang selalu dilakukan dari ujung depan (front atau head) antrean. Struktur queue memiliki peran krusial dalam berbagai aplikasi komputasi, seperti dalam penjadwalan proses pada sistem operasi—contohnya pada penerapan Algoritma Multilevel Feedback Queue yang mengatur proses antrean —pengelolaan buffer data dan penanganan interupsi [2].

### A. Queue<br/>

#### 1. Queue dengan Head diam dan Tail bergerak

#### 2. Queue dengan Head bergerak dan Tail diam

#### 3. Queue dengan Head bergerak dan Tail bergerak (rotasi)

## Guided

### 1. Queue

#### queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string nama;
    Node *next;
};

struct queue
{
    Node *head, *tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);
#endif
```

#### queue.cpp

```C++
#include "queue.h"
using namespace std;

void CreateQueue(queue &Q)
{
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q)
{
    return Q.head == nullptr;
}

bool isFull(queue)
{
    return false;
}

void enQueue(queue &Q, const string &nama)
{
    Node *baru = new Node{nama, nullptr};
    if (isEmpty(Q))
    {
        Q.head = Q.tail = baru;
    }
    else
    {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node *hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr)
    {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q)
{
    if (isEmpty(Q))
    {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node *p = Q.head; p != nullptr; p = p->next)
    {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q)
{
    while (!isEmpty(Q))
    {
        deQueue(Q);
    }
}
```

#### main.cpp

```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main()
{
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}
```

Program di atas, adalah program yang menjelaskan bagaimana cara implementasi Queue dalam bahasa C++.

### 2. Queue

#### queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

const int MAKSIMAL = 5;

struct queue
{
    string nama[MAKSIMAL];
    int head, tail;
};

bool isEmpty(queue Q);
bool isFull(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
#endif
```

#### queue.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE :
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q)
{
    if (Q.head == -1 && Q.tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isFull implmenetasi 1 & 2
bool isFull(queue Q)
{
    if (Q.tail == MAKSIMAL - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q)
{ // terbentuk queue dengan head = -1 dan tail = -1
    Q.head = -1;
    Q.tail = -1;
}

// enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama)
{
    if (isFull(Q) == true)
    {
        cout << "Queue sudah penuh!" << endl;
    }
    else
    {
        if (isEmpty(Q) == true)
        {
            Q.head = Q.tail = 0;
        }
        else
        {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

// dequeue implementasi 1
void deQueue(queue &Q)
{
    if (isEmpty(Q) == true)
    {
        cout << "Queue kosong!" << endl;
    }
    else
    {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for (int i = 0; i < Q.tail; i++)
        {
            Q.nama[i] = Q.nama[i + 1];
        }
        Q.tail--;
        if (Q.tail < 0)
        { // kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

// viewQueue implementasi 1 & 2
void viewQueue(queue Q)
{
    if (isEmpty(Q) == true)
    {
        cout << "Queue kosong!" << endl;
    }
    else
    {
        for (int i = Q.head; i <= Q.tail; i++)
        {
            cout << i - Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }
//     }
// }
```

#### main.cpp

```C++
#include "queue.h"
#include <iostream>

using namespace std;

int main()
{
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}
```

Program di atas, adalah program yang menjelaskan bagaimana cara implementasi Queue dalam bahasa C++. Namun dengan menggunakan metode Head berjalan dan Tail diam (implementasi 2) dan Head berjalan dan Tail berjalan (implementasi 3).


## Unguided

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
```h
Type infotype: integer
Type Queue: <
info : array [5] of infotype {index array dalam C++
dimulai dari 0}
head, tail : integer
>
procedure CreateQueue (input/output Q: Queue)
function isEmptyQueue (Q: Queue) → boolean
function isFullQueue (Q: Queue) → boolean
procedure enqueue (input/output Q: Queue, input x: infotype)
function dequeue (input/output Q: Queu)
```
### Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

#### queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

typedef int infotype;
struct Queue
{
    int info[5], head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### queue.cpp

```C++
#include "queue.h"
#include <iomanip>

void CreateQueue(Queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
};

bool isEmptyQueue(Queue Q)
{
    return Q.head == -1 && Q.tail == -1;
};

bool isFullQueue(Queue Q)
{
    return Q.tail == 4;
};

void enqueue(Queue &Q, infotype x)
{
    if (isFullQueue(Q) == true)
    {
        cout << "Queue sudah penuh!" << endl;
    }
    else
    {
        if (isEmptyQueue(Q) == true)
        {
            Q.head = Q.tail = 0;
        }
        else
        {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
};

infotype dequeue(Queue &Q)
{
    if (isEmptyQueue(Q) == true)
    {
        cout << "Queue kosong!!!" << endl;
    }
    else
    {
        infotype dataTerhapus = Q.info[Q.head];
        for (int i = 0; i < Q.tail; i++)
        {
            Q.info[i] = Q.info[i + 1];
        }
        Q.tail--;
        if (Q.tail == 0)
        {
            Q.head = Q.tail = -1;
        }
        return dataTerhapus;
    }
};

void printInfo(Queue Q)
{
    cout << " " << Q.head << " - " << Q.tail << " | ";
    if (!isEmptyQueue(Q))
    {
        for (int i = 0; i <= Q.tail; i++)
        {
            cout << Q.info[i] << " ";
        }
    }
    else
    {
        cout << "empty queue";
    }

    cout << endl;
};
```

#### main.cpp

```C++
#include "queue.h"

int main()
{
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    enqueue(Q, 4);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    return 0;
}
```
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan5_Modul5/Unguided/screenshot/Pre-test.png)

Kode ini merupakan implementasi Queue menggunakan C++ dengan metode Head bergerak dan Tail diam.

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

#### queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

typedef int infotype;
struct Queue
{
    int info[5], head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### queue.cpp

```C++
#include "queue.h"
#include <iomanip>

void CreateQueue(Queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
};

bool isEmptyQueue(Queue Q)
{
    return Q.head == -1 && Q.tail == -1;
};

bool isFullQueue(Queue Q)
{
    return Q.tail == 4;
};

void enqueue(Queue &Q, infotype x)
{
    if (isFullQueue(Q) == true)
    {
        cout << "Queue sudah penuh!" << endl;
    }
    else
    {
        if (isEmptyQueue(Q) == true)
        {
            Q.head = Q.tail = 0;
        }
        else
        {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
};

infotype dequeue(Queue &Q)
{
    if (isEmptyQueue(Q) == true)
    {
        cout << "Queue kosong!!!" << endl;
    }
    else
    {
        infotype dataTerhapus = Q.info[Q.head];
        Q.head++;
        if (Q.head >= Q.tail)
        {
            Q.head = Q.tail = -1;
        }
        return dataTerhapus;
    }
};

void printInfo(Queue Q)
{
    cout << " " << Q.head << " - " << Q.tail << " | ";
    if (!isEmptyQueue(Q))
    {
        for (int i = Q.head; i <= Q.tail; i++)
        {
            cout << Q.info[i] << " ";
        }
    }
    else
    {
        cout << "empty queue";
    }

    cout << endl;
};
```

#### main.cpp

```C++
#include "queue.h"

int main()
{
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    enqueue(Q, 4);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    return 0;
}
```

### Output Unguided 2 :

##### Output 1

![Screenshot Output Unguided 2](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan5_Modul5/Unguided/screenshot/Soal_2.png)

Kode ini merupakan implementasi Queue menggunakan C++ dengan metode Head diam dan Tail bergerak.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

#### queue.h

```h
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

typedef int infotype;
struct Queue
{
    int info[5], head, tail;
};

void CreateQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

#### listAngka.cpp

```C++
#include "queue.h"
#include <iomanip>

void CreateQueue(Queue &Q)
{
    Q.head = -1;
    Q.tail = -1;
};

bool isEmptyQueue(Queue Q)
{
    return Q.head == -1 && Q.tail == -1;
};

bool isFullQueue(Queue Q)
{
    if ((Q.tail + 1) % 5 == Q.head)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void enqueue(Queue &Q, infotype x)
{
    if (isFullQueue(Q))
    {
        cout << "Queue sudah penuh!" << endl;
    }
    else
    {
        if (isEmptyQueue(Q))
        {
            Q.head = Q.tail = 0;
        }
        else
        {
            Q.tail = (Q.tail + 1) % 5;
        }
        Q.info[Q.tail] = x;
    }
};

infotype dequeue(Queue &Q)
{
    if (isEmptyQueue(Q))
    {
        cout << "Queue kosong!!!" << endl;
    }
    else
    {
        infotype dataTerhapus = Q.info[Q.head];
        if (Q.head + 1 == Q.tail)
        {
            Q.head = Q.tail = -1;
        }
        else
        {
            Q.head = (Q.head + 1) % 5;
        }
        return dataTerhapus;
    }
};

void printInfo(Queue Q)
{
    cout << " " << Q.head << " - " << Q.tail << " | ";
    if (!isEmptyQueue(Q))
    {
        int i = Q.head;
        while (true)
        {
            cout << Q.info[i] << " ";
            if (i == Q.tail)
            {
                break;
            }
            i = (i + 1) % 5;
        }
    }
    else
    {
        cout << "empty queue";
    }

    cout << endl;
};
```

#### main.cpp

```C++
#include "queue.h"

int main()
{
    cout << "Hello World" << endl;
    Queue Q;
    CreateQueue(Q);
    cout << "----------------------" << endl;
    cout << " H - T \t | Queue info" << endl;
    cout << "----------------------" << endl;
    printInfo(Q);
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    enqueue(Q, 4);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    dequeue(Q);
    printInfo(Q);
    return 0;
}
```

### Output Unguided 3 :

##### Output 1

![Screenshot Output Unguided 3](https://github.com/aflahrizkyadhafin-tlu/103112400223_Aflah-Rizkyadhafin-Nurfikri_StrukturData/blob/main/Pertemuan5_Modul5/Unguided/screenshot/Soal_3.png)

Prosedur aritmatikaKode ini merupakan implementasi Queue menggunakan C++ dengan metode Head bergerak dan Tail bergerak. Head dan Tail akan terus berotasi jika mencapai index maksimal array.

## Kesimpulan

Modul minggu ini mempelajari implementasi <b>Queue</b> menggunakan bahasa pemrograman C++. Queue dibuat dengan 3 metode yaitu, head bergerak tail diam, head diam tail bergerak, dan head bergerak dan tail bergerak (berotasi).

## Referensi

<br>[1] Sihombing, J. (2019). Penerapan stack dan queue pada array dan linked list dalam java. INFOKOM (Informatika & Komputer), 7(2), 15-24.
<br>
<br>[2] Putri, A. D. O., Fauziah, F., & Iskandar, A. (2023). Algoritma Content-Based Filtering dan Algoritma Multilevel Feedback Queue Pada Proses Pemesanan Makanan Berbasis Web. JIPI (Jurnal Ilmiah Penelitian dan Pembelajaran Informatika), 8(1), 266-280.
<br>
