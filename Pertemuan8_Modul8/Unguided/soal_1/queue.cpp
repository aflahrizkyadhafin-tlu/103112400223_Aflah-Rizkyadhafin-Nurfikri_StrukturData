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