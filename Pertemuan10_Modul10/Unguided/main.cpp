#include "MultiLL.h"

int main()
{
    listParent kelompokHewan;
    createListParent(kelompokHewan);

    adrParent A, B, C, D, E;
    A = allocNodeParent("G001", "Aves");
    B = allocNodeParent("G002", "Mamalia");
    C = allocNodeParent("G003", "Pisces");
    D = allocNodeParent("G004", "Amfibi");
    E = allocNodeParent("G005", "Reptil");
    insertFirstParent(kelompokHewan, C);
    insertFirstParent(kelompokHewan, B);
    insertFirstParent(kelompokHewan, A);
    insertLastParent(kelompokHewan, D);
    insertLastParent(kelompokHewan, E);

    adrChild newChild;
    createListChild(A->L_Child);
    createListChild(B->L_Child);
    createListChild(D->L_Child);

    // Input Child G001
    newChild = allocnodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3);
    insertFirstChild(A->L_Child, newChild);
    newChild = allocnodeChild("AV002", "Bebek", "Air", true, 2);
    insertFirstChild(A->L_Child, newChild);

    // Input Child G002
    newChild = allocnodeChild("M001", "Harimau", "Hutan", true, 200);
    insertFirstChild(B->L_Child, newChild);
    newChild = allocnodeChild("M003", "Gorilla", "Hutan", false, 160);
    insertFirstChild(B->L_Child, newChild);
    newChild = allocnodeChild("M002", "Kucing", "Darat", true, 4);
    insertFirstChild(B->L_Child, newChild);

    // Input Child G004
    newChild = allocnodeChild("AM001", "Kodok", "Sawah", false, 0.2);
    insertFirstChild(D->L_Child, newChild);

    cout << "====== Sebelum dihapus ======" << endl;
    printMLLStructure(kelompokHewan);
    // searchHewanByEkor(kelompokHewan, true);
    cout << endl
         << "====== Setelah dihapus ======" << endl;
    deleteListChild(D->L_Child);
    deleteAfterParent(kelompokHewan, C);
    printMLLStructure(kelompokHewan);

    return 0;
}