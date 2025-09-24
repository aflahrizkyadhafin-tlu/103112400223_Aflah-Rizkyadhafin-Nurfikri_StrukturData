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