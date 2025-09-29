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