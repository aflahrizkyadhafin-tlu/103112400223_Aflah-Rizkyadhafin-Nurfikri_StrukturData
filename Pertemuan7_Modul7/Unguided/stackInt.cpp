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
        cout << "Nilai " << x << " berhasil di input pada index ke-" << S.top << endl;
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

    while (n > -1)
    {
        cout << S.info[n];
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
    infotype temp, n = S.top;
    Stack urutanAngka;
    createStack(urutanAngka);
    while (n > -1)
    {
        if (S.info[n] > x)
        {
            push(urutanAngka, S.info[n]);
        }
        else if (x != NULL)
        {
            push(urutanAngka, x);
            x = NULL;
        }
        else
        {
            push(urutanAngka, S.info[n]);
        }
        n--;
    }
    S = urutanAngka;
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