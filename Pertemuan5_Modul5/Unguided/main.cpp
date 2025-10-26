#include "listAngka.h"

int main()
{
    List linkedList;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF = nullptr;
    infotype infoA, infoB, infoC, infoD, infoE, infoF;
    CreateList(linkedList);

    infoA.angka = 8;
    infoA.Next = nullptr;
    nodeA = alokasi(infoA);
    infoB.angka = 13;
    nodeB = alokasi(infoB);
    infoC.angka = 18;
    nodeC = alokasi(infoC);
    infoD.angka = 25;
    nodeD = alokasi(infoD);
    infoE.angka = 33;
    nodeE = alokasi(infoE);
    infoF.angka = 40;
    nodeF = alokasi(infoF);

    insertFirst(linkedList, nodeB);
    insertLast(linkedList, nodeA);
    insertAfter(nodeD, nodeB);
    insertFirst(linkedList, nodeC);
    insertLast(linkedList, nodeE);
    insertFirst(linkedList, nodeF);
    delAfter(nodeB, nodeC);
    printList(linkedList);

    return 0;
}