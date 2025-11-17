#include "SLLInventory.h"

bool isEmpty(List L)
{
    if (L.head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createList(List &L)
{
    L.head = nullptr;
}

address allocate(Product P)
{
    address newElm = new Node();
    newElm->info = P;
    newElm->next = nullptr;
    return newElm;
}

void deallocate(address addr)
{
    addr->next = nullptr;
    delete addr;
}

void insertFirst(List &L, Product P)
{
    address newNode = allocate(P), temp = L.head;

    cout << isEmpty << endl;
    if (temp == nullptr)
    {
        L.head = newNode;
    }
    else
    {
        newNode->next = L.head;
        L.head = newNode;
    }
}

void insertLast(List &L, Product P)
{
    address newnode = allocate(P), temp = L.head;

    if (temp == nullptr)
    {
        L.head = newnode;
    }
    else
    {
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void insertAfter(List &L, address &Q, Product P)
{
    address newNode = allocate(P);
    newNode->next = Q->next;
    Q->next = newNode;
}

void deleteFirst(List &L, Product P)
{
    address temp = L.head;
    P = L.head->info;
    L.head = L.head->next;
    deallocate(temp);
}

void deleteLast(List &L, Product P)
{
    address temp = L.head, prev = nullptr;
    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = nullptr;
    P = temp->info;
    deallocate(temp);
}

void deleteAfter(List &L, address &Q, Product P)
{
    address temp = Q->next;
    P = Q->next->info;
    Q->next = Q->next->next;
    deallocate(temp);
}

void updateAtPosition(List &L, int posisi)
{
    address temp = L.head;
    int position = 1;

    while (temp != nullptr && position != posisi)
    {
        cout << (temp != nullptr && position != posisi) << endl;
        temp = temp->next;
        position++;
    }

    cout << "Nama : ";
    cin >> temp->info.Nama;
    cout << "SKU : ";
    cin >> temp->info.SKU;
    cout << "Jumlah : ";
    cin >> temp->info.Jumlah;
    cout << "Harga satuan : ";
    cin >> temp->info.HargaSatuan;
    cout << "Diskon (%) : ";
    cin >> temp->info.DiskonPersen;
    cout << endl;
}

void viewList(List L)
{
    address temp = L.head;
    int posisi = 1;
    while (temp != nullptr)
    {
        cout << "indeks : " << posisi << endl
             << "Nama : " << temp->info.Nama << endl
             << "SKU : " << temp->info.SKU << endl
             << "Jumlah : " << temp->info.Jumlah << endl
             << "Harga satuan : " << temp->info.HargaSatuan << endl
             << "Diskon persen : " << temp->info.DiskonPersen << "%" << endl
             << "Harga akhir : " << temp->info.HargaSatuan * (1 - (temp->info.DiskonPersen / 100)) << endl
             << endl;
        posisi++;
        temp = temp->next;
    }
    cout << endl;
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice)
{
    address temp = L.head;
    int posisi = 1;
    while (temp != nullptr)
    {
        float hargaAkhir = temp->info.HargaSatuan * (1 - (temp->info.DiskonPersen / 100));
        if (hargaAkhir >= minPrice && hargaAkhir <= maxPrice)
        {
            cout << "indeks : " << posisi << endl
                 << "Nama : " << temp->info.Nama << endl
                 << "SKU : " << temp->info.SKU << endl
                 << "Jumlah : " << temp->info.Jumlah << endl
                 << "Harga satuan : " << temp->info.HargaSatuan << endl
                 << "Diskon persen : " << temp->info.DiskonPersen << "%" << endl
                 << "Harga akhir : " << hargaAkhir << endl
                 << endl;
        }
        posisi++;
        temp = temp->next;
    }
    cout << endl;
}

void maxHargaAkhir(List L)
{
    address temp = L.head;
    float maxHargaAkhir = temp->info.HargaSatuan * (1 - (temp->info.DiskonPersen / 100));

    while (temp != nullptr)
    {
        if (temp->info.HargaSatuan * (1 - (temp->info.DiskonPersen / 100)) > maxHargaAkhir)
        {
            maxHargaAkhir = temp->info.HargaSatuan * (1 - (temp->info.DiskonPersen / 100));
        }
        temp = temp->next;
    }

    temp = L.head;
    int pos = 1;
    while (temp->info.HargaSatuan * (1 - (temp->info.DiskonPersen / 100)) == maxHargaAkhir)
    {
        cout << "indeks : " << pos << endl
             << "Nama : " << temp->info.Nama << endl
             << "SKU : " << temp->info.SKU << endl
             << "Jumlah : " << temp->info.Jumlah << endl
             << "Harga satuan : " << temp->info.HargaSatuan << endl
             << "Diskon persen : " << temp->info.DiskonPersen << "%" << endl
             << "Harga akhir : " << maxHargaAkhir << endl
             << endl;
        pos++;
        temp = temp->next;
    }
}
