#include "listAngka.h"

int main(){
    address nodeA, nodeB, nodeC, nodeD, nodeE, nodeF;
    List linkedList;
    CreateList(linkedList);

    nodeA = alokasi(infotype({angka: 8, Next:nullptr}));
    nodeB = alokasi(infotype({angka: 13, Next:nullptr}));
    nodeC = alokasi(infotype({angka: 18, Next:nullptr}));
    nodeD = alokasi(infotype({angka: 25, Next:nullptr}));
    nodeE = alokasi(infotype({angka: 33, Next:nullptr}));
    nodeF = alokasi(infotype({angka: 40, Next:nullptr}));

    insertFirst(linkedList,nodeB);
    insertLast(linkedList, nodeA);
    insertAfter(linkedList,nodeD,nodeB);
    insertFirst(linkedList,nodeC);
    insertLast(linkedList,nodeE);
    insertFirst(linkedList,nodeF);
    delAfter(linkedList, nodeB, nodeC);
    printList(linkedList);
    
    return 0;
}