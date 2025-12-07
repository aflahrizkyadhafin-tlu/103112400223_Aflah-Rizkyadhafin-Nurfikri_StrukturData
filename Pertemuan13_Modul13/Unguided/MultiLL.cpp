#include "MultiLL.h"

bool isEmptyParent(listParent &LParent)
{
    if (LParent.first == Nil && LParent.last == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyChild(listChild &LChild)
{
    if (LChild.first == Nil && LChild.last == Nil)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void createListParent(listParent &LParent)
{
    LParent.first = LParent.last = Nil;
}

void createListChild(listChild &LChild)
{
    LChild.first = LChild.last = Nil;
}

adrParent allocNodeParent(string idGol, string namaGol)
{
    adrParent newElm = new NodeParent;
    newElm->next = Nil;
    newElm->prev = Nil;
    newElm->L_Child = listChild();
    newElm->isiData.idGolongan = idGol;
    newElm->isiData.namaGolongan = namaGol;
    return newElm;
}

adrChild allocnodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight)
{
    adrChild newElm = new NodeChild;
    newElm->next = Nil;
    newElm->prev = Nil;
    newElm->isidata.idHewan = idHwn;
    newElm->isidata.namaHewan = namaHwn;
    newElm->isidata.habitat = habitat;
    newElm->isidata.ekor = tail;
    newElm->isidata.bobot = weight;
    return newElm;
}

void deallocNodeParent(adrParent &NParent)
{
    if (NParent != Nil)
    {
        NParent->next = NParent->prev = Nil;
        delete NParent;
        NParent = Nil;
    }
}

void deallocNodeChild(adrChild &NChild)
{
    if (NChild != Nil)
    {
        NChild->next = NChild->prev = Nil;
        delete NChild;
        NChild = Nil;
    }
}

void insertFirstParent(listParent &LParent, adrParent NodeParent)
{
    if (isEmptyParent(LParent))
    {
        LParent.first = LParent.last = NodeParent;
    }
    else
    {
        NodeParent->next = LParent.first;
        LParent.first->prev = NodeParent;
        LParent.first = NodeParent;
    }
}

void insertLastParent(listParent &LParent, adrParent NodeParent)
{
    if (isEmptyParent(LParent))
    {
        LParent.first = LParent.last = NodeParent;
    }
    else
    {
        NodeParent->prev = LParent.last;
        LParent.last->next = NodeParent;
        LParent.last = NodeParent;
    }
}

void deleteFirstParent(listParent &LParent)
{
    adrParent temp = LParent.first;
    if (!isEmptyParent(LParent))
    {
        LParent.first = LParent.first->next;
        LParent.first->prev = Nil;
        deallocNodeParent(temp);
    }
}

void deleteAfterParent(listParent &LParent, adrParent NPrev)
{
    adrParent temp = NPrev->next;
    if (temp != Nil)
    {
        if (NPrev->next->next != Nil)
        {
            NPrev->next = NPrev->next->next;
            NPrev->next->prev = NPrev;
        }
        else
        {
            NPrev->next = Nil;
        }
        delete temp;
    }
}

void insertFirstChild(listChild &LChild, adrChild NodeChild)
{
    if (LChild.first == Nil)
    {
        LChild.first = LChild.last = NodeChild;
    }
    else
    {
        NodeChild->prev = LChild.last;
        LChild.last->next = NodeChild;
        LChild.last = NodeChild;
    }
}

void insertLastChild(listChild &LChild, adrChild NodeChild)
{
    if (LChild.last == Nil)
    {
        LChild.first = LChild.last = NodeChild;
    }
    else
    {
        NodeChild->prev = LChild.last;
        LChild.last->next = NodeChild;
        LChild.last = NodeChild;
    }
}

void deleteFirstChild(listChild &LChild)
{
    adrChild temp = LChild.first;
    if (LChild.first != Nil)
    {
        LChild.first = LChild.first->next;
        LChild.first->prev = Nil;
        deallocNodeChild(temp);
    }
}

void deleteAfterChild(listChild &LChild, adrChild NPrev)
{
    adrChild temp = NPrev->next;
    if (temp->next == Nil)
    {
        NPrev->next = NPrev->next->next;
        NPrev->next->next->prev = NPrev;
        delete temp;
    }
}

void printMLLStructure(listParent &LParent)
{
    adrParent tempParent = LParent.first;
    int posP = 1;

    while (tempParent != Nil)
    {
        adrChild tempChild = tempParent->L_Child.first;
        int posC = 1;
        cout << "=== Parent " << posP << " ===" << endl
             << "ID Golongan : " << tempParent->isiData.idGolongan << endl
             << "Nama Golongan : " << tempParent->isiData.namaGolongan << endl;
        while (tempChild != Nil)
        {
            cout << "  - Child " << posC << endl
                 << "      ID Hewan : " << tempChild->isidata.idHewan << endl
                 << "      Nama Hewan : " << tempChild->isidata.namaHewan << endl
                 << "      Habitat : " << tempChild->isidata.habitat << endl
                 << "      Ekor : " << tempChild->isidata.ekor << endl
                 << "      Bobot : " << tempChild->isidata.bobot << endl;
            posC++;
            tempChild = tempChild->next;
        }
        if (tempParent->L_Child.first == Nil)
        {
            cout << "(Tidak ada child)" << endl;
        }
        cout << "-----------------------------------" << endl;
        posP++;
        tempParent = tempParent->next;
    }
}

void deleteListChild(listChild &LChild)
{
    adrChild temp = LChild.first;
    while (temp != Nil)
    {
        if (temp->next != Nil)
        {
            LChild.first = LChild.first->next;
        }
        else
        {
            LChild.first = LChild.last = Nil;
        }
        deallocNodeChild(temp);
        temp = LChild.first;
    }
}

void searchHewanByEkor(listParent &LParent, bool tail)
{
    adrParent tempParent = LParent.first;
    int posP = 1;

    while (tempParent != Nil)
    {
        adrChild tempChild = tempParent->L_Child.first;
        int posC = 1;
        bool find = false;

        while (tempChild != Nil)
        {
            if (tempChild->isidata.ekor == tail)
            {
                cout << "Data ditemukan pada list anak dari node parent " << tempParent->isiData.namaGolongan << " pada posisi ke-" << posC << "!" << endl;
                cout << "--- Data Child ---" << endl
                     << "ID Child : " << tempChild->isidata.idHewan << endl
                     << "Posisi pada list anak : " << posC << endl
                     << "Nama Hewan : " << tempChild->isidata.namaHewan << endl
                     << "Habitat : " << tempChild->isidata.habitat << endl
                     << "Ekor : " << tempChild->isidata.ekor << endl
                     << "Bobot : " << tempChild->isidata.bobot << endl;
                find = true;
            }
            posC++;
            tempChild = tempChild->next;
        }
        if (find)
        {
            cout << "-----------------------------------" << endl;
            cout << "--- Data Parent ---" << endl
                 << "ID Parent : " << tempParent->isiData.idGolongan << endl
                 << "Posisi dalam list induk : " << posP << endl
                 << "Nama Golongan : " << tempParent->isiData.namaGolongan << endl;
            cout << "-----------------------------------" << endl;
        }
        posP++;
        tempParent = tempParent->next;
    }
}
