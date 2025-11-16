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