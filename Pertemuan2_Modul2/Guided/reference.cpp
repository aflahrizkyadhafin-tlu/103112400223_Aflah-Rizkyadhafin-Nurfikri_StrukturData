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