#include "stackInt.h"

int main()
{
    Stack arrAngka;
    createStack(arrAngka);

    cout << "========= PUSH STACK =========" << endl;
    push(arrAngka, 1);
    push(arrAngka, 2);
    push(arrAngka, 3);
    push(arrAngka, 4);
    printInfo(arrAngka);
    cout << "========= BALIK STACK =========" << endl;
    balikStack(arrAngka);
    printInfo(arrAngka);
    return 0;
}