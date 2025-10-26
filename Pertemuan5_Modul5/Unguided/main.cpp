#include "listAngka.h"

int main()
{
    List linkedList;
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF,nodeG = nullptr;
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
    nodeG = alokasi(infotype());

    insertFirst(linkedList, nodeB);
    insertLast(linkedList, nodeA);
    insertAfter(nodeD, nodeB);
    insertFirst(linkedList, nodeC);
    insertLast(linkedList, nodeE);
    insertFirst(linkedList, nodeF);
    delAfter(nodeB, nodeC);
    printList(linkedList);

    // Soal 1
    // updateFirst(linkedList);
    // updateAfter(nodeD);
    // updateLast(linkedList);
    // updateAfter(linkedList.First);
    // printList(linkedList);

    // Soal 2
    searchByData(linkedList, 18);
    searchByData(linkedList, 99);
    cout << endl;

    searchByAddress(linkedList, nodeA);
    searchByAddress(linkedList, nodeG);
    cout << endl;

    cout << "================ Data diatas 20 ================" << endl;
    searchByRange(linkedList, 20);
    cout << endl;
    
    cout << "================ Data diatas 50 ================" << endl;
    searchByRange(linkedList, 50);
    cout << endl;

    return 0;
}