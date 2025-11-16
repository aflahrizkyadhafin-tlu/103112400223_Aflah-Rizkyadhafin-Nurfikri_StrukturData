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