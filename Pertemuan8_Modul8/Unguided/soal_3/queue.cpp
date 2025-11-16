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