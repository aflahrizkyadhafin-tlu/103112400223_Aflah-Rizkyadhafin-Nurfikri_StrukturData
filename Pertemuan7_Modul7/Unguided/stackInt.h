#ifndef STACK_INT
#define STACK_INT
#include <iostream>
using namespace std;

typedef int infotype;
struct Stack
{
    int info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack &S);
void balikStack(Stack &S);

#endif